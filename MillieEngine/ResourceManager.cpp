#include "ResourceManager.h"
#include "LogManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using std::cout;
using std::endl;
namespace me {

	ResourceManager::ResourceManager() {
		setType("ResourceManager");
		m_sprite_count = 0;
	}


	ResourceManager& me::ResourceManager::getInstance()
	{
		static ResourceManager ResourceManagerSingle;
		return ResourceManagerSingle;
	}

	int me::ResourceManager::startUp()
	{

		return 0;
	}

	void me::ResourceManager::shutDown()
	{
	}

	//Helper function: Read single line `tag number', return number
	int readLineInt(ifstream* p_file, int* p_line_number, const char* tag) {

		string line;
		getline(*p_file, line);
		if (!line.compare(0, sizeof(tag), tag)) {
			LogManager& logmanager = LogManager::getInstance();
			logmanager.writeLog("ResourceManager::LoadSprite: Error line %d. Tag did not match\n",
				*p_line_number, tag);
			return -1;
		}

		int num = atoi(line.substr(strlen(tag)).c_str());
		++* p_line_number;
		return num;

	}

	//Helper function: Read single line `tag string', return string
	string readLineStr(ifstream* p_file, int* p_line_number, const char* tag) {

		string line;
		getline(*p_file, line);
		if (!line.compare(0, sizeof(tag), tag)) {
			LogManager& logmanager = LogManager::getInstance();
			logmanager.writeLog("ResourceManager::LoadSprite: Error line %d. Tag did not match\n",
				*p_line_number, tag);
			return "error";
		}

		string str = line.substr(strlen(tag) + 1);
		++* p_line_number;
		return str;

	}

	//Helper function: Read frame until `end', return Frame
	Frame readFrame(ifstream* p_file, int* p_line_number, int width, int height) {

		LogManager& logmanager = LogManager::getInstance();
		string line, frame_str;
		for (int i = 1; i <= height; i++) {

			getline(*p_file, line);
			if (line.length() - 1 > width) {
				logmanager.writeLog("ResourceManager::LoadSprite: Error line %d. Line width %d, expected %d\n",
					*p_line_number, line.length() - 1, width);
				return Frame(); //Error
			}

			++* p_line_number;
			line = line.substr(0, line.length() - 1);
			frame_str += line;
		}

		getline(*p_file, line);
		if (line.compare(0, 3, END_FRAME_TOKEN)) {
			logmanager.writeLog("ResourceManager::LoadSprite: Error line %d. Line height at least %d, expected %d\n",
				*p_line_number, height + 1, height);
			return Frame(); //Error
		}

		++* p_line_number;
		return Frame(width, height, frame_str);

	}

	int ResourceManager::loadSprite(string filename, string label) {

		LogManager& logmanager = LogManager::getInstance();
		logmanager.writeLog("ResourceManager::LoadSprite: Loading Sprite!\n");

		if (m_sprite_count > MAX_SPRITES) {
			logmanager.writeLog("ResourceManager::LoadSprite: MAX_SPRITE limit reached!\n");
			return -1;
		}

		string line, color;
		int lineNum, frames, width, height, framecount;
		Sprite* sprite;
		Frame next_frame;
		ifstream spriteFile;

		spriteFile.open(filename.c_str());
		if (spriteFile.is_open()) {
			logmanager.writeLog("ResourceManager::LoadSprite: Opened sprite file!\n");
			frames = readLineInt(&spriteFile, &lineNum, FRAMES_TOKEN);
			if (frames <= 0) {
				return -1;
			}

			width = readLineInt(&spriteFile, &lineNum, WIDTH_TOKEN);
			if (width <= 0) {
				return -1;
			}

			height = readLineInt(&spriteFile, &lineNum, HEIGHT_TOKEN);
			if (height <= 0) {
				return -1;
			}

			color = readLineStr(&spriteFile, &lineNum, COLOR_TOKEN);
			if (color == "error") {
				return -1;
			}
			sprite = new Sprite(frames);
		}
		else return -1;

		int i = 0;
		while (!spriteFile.eof()) {
			if (i == frames) break;
			next_frame = readFrame(&spriteFile, &lineNum, width, height);
			if (next_frame.getWidth() == 0) {
				return -1;
			}
			sprite->addFrame(next_frame);
			i++;
		}

		sprite->setLabel(label);
		sprite->setHeight(height);
		sprite->setWidth(width);
		color = color.substr(0, color.length() - 1);

		if (color.compare("black") == 0) sprite->setColor(BLACK);
		else if (color.compare("red") == 0) sprite->setColor(RED);
		else if (color.compare("green") == 0) sprite->setColor(GREEN);
		else if (color.compare("yellow") == 0) sprite->setColor(YELLOW);
		else if (color.compare("blue") == 0) sprite->setColor(BLUE);
		else if (color.compare("magenta") == 0) sprite->setColor(MAGENTA);
		else if (color.compare("cyan") == 0) sprite->setColor(CYAN);
		else if (color.compare("white") == 0) sprite->setColor(WHITE);
		else sprite->setColor(COLOR_DEFAULT);

		m_p_sprite[m_sprite_count] = sprite;
		m_sprite_count++;
		spriteFile.close();

		logmanager.writeLog("ResourceManager::LoadSprite: Sprite loaded!\n");

		return 0;

	}

	int ResourceManager::unloadSprite(string label) {

		for (int i = 0; i < m_sprite_count; i++) {
			if (m_p_sprite[i]->getLabel() == label) {
				delete m_p_sprite[i];
				for (int j = i; j < m_sprite_count - 1; j++) {
					m_p_sprite[j] = m_p_sprite[j + 1];
				}
				m_sprite_count--;
				return 0; //Success
			}
		}

		return -1; //Sprite not found

	}


	Sprite* ResourceManager::getSprite(std::string label) const {

		for (int i = 0; i < m_sprite_count; i++) {
			if (m_p_sprite[i]->getLabel() == label) {
				return m_p_sprite[i];
			}
		}

		return NULL; //Sprite not found

	}

}