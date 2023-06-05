#include "ResourceManager.h"
#include "LogManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using std::cout;
using std::endl;
namespace me {


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

    int ResourceManager::loadSprite(std::string filename, std::string label) {
        // Open file
        std::ifstream file(filename);
        if (!file.is_open()) {
            return -1; // Unable to open the file. Return an error value.
        }

        // Read sprite header
        std::string line;
        std::getline(file, line);
        int frame_count = std::atoi(line.c_str());
        std::getline(file, line);
        int width = std::atoi(line.c_str());
        std::getline(file, line);
        int height = std::atoi(line.c_str());
        std::getline(file, line);
        int slowdown = std::atoi(line.c_str());
        std::getline(file, line);
        Color color = Color::BLACK;
        if (line == "red") {
            color = Color::RED;
        }

        // Create new Sprite
        Sprite* sprite = new Sprite(frame_count);
        sprite->setHeight(height);
        sprite->setWidth(width);
        sprite->setSlowdown(slowdown);
        sprite->setColor(color);

        // Read and add frames to Sprite
        for (int f = 1; f <= frame_count; f++) {
            std::string frame_string;
            for (int h = 1; h <= height; h++) {
                std::getline(file, line);
                frame_string += line;
            }
            Frame frame(width, height , frame_string);
            frame.setHeight(height);
            frame.setWidth(width);
            sprite->addFrame(frame);
        }

        // Close file
        file.close();

        // Add label to Sprite
        sprite->setLabel(label);

        // Add the sprite to the resource manager's collection
        m_p_sprite[m_sprite_count++] = sprite;

        return 0; // Return a success value (e.g., OK) to indicate that the sprite was loaded successfully.
    }



	int ResourceManager::unloadSprite(std::string label) {
		for (int i = 0; i < m_sprite_count; i++) {
			if (label == m_p_sprite[i]->getLabel()) {
				delete m_p_sprite[i];

				// Shift remaining sprites.
				for (int j = i; j < m_sprite_count - 1; j++) {
					m_p_sprite[j] = m_p_sprite[j + 1];
				}

				m_sprite_count--;
				return 0; // Return a success value (e.g., OK) to indicate that the sprite was unloaded successfully.
			}
		}

		return -1; // Sprite not found. Return an error value (e.g., ERROR) to indicate that the sprite was not found.
	}

	Sprite* me::ResourceManager::getSprite(std::string label) const
	{
		for (int i = 0; i < m_sprite_count; i++) {
			if (label == m_p_sprite[i]->getLabel()) {
				return m_p_sprite[i];
			}
		}

		return nullptr; // Sprite not found.
	}

}
