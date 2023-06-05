#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

#include <iostream>
#include <Windows.h>

const int FRAME_TIME_DEFAULT = 33;

namespace me {

	GameManager::GameManager() {
		setType("GameManager");
		game_over = false;
		frame_time = FRAME_TIME_DEFAULT;
	}


	//Singleton Instance
	//
	GameManager& GameManager::getInstance() {
		static GameManager GameManagerSingle;
		return GameManagerSingle;
	}


	// Startup all GameManager Services
	int GameManager::startUp() {
		timeBeginPeriod(1);
		LM.startUp();
		WM.startUp();
		DM.startUp();
		IM.startUp();
		RM.startUp();
		LM.writeLog("Game Manager Started. \n");
		return 0;
	}


	// ShutDown all Game Manager Services
	void GameManager::shutDown() {
		timeEndPeriod(1);
		setGameOver(true);
		LM.writeLog("Game Manager Shuting down. \n");
	}

	// Run Game Loop
	void GameManager::run() {
		while (!game_over) {
			Clock clock;
			long int start_time = clock.delta();

			IM.getInput();
			// Get Input

			WM.update();

			WM.draw();

			//DM.drawCh(Vector(0, 0), '-',YELLOW);

			DM.swapBuffers();


			long int end_time = clock.split() / 1000000;

			Sleep((frame_time - end_time));

		}

	}



	// Set GameOver status to recieved boolean
	void GameManager::setGameOver(bool new_game_over) {
		if (new_game_over)
			game_over = new_game_over;
	}


	// Get GameOver Status
	bool GameManager::getGameOver() const {
		return game_over;
	}


	// Return frame Time
	int GameManager::getFrameTime() const {
		return frame_time;
	}

}