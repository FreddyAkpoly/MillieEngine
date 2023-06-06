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

			
			
			
			
			//GAME CONTENT
			for (int i = 20; i < 60; i+=2) {
				DM.drawCh(Vector(i, 22), '#', YELLOW);
			}

			for (int i = 20; i < 60; i += 2) {
				DM.drawCh(Vector(i, 0), '#', YELLOW);
			}

			for (int i = 0; i < 60; i+=2) {
				DM.drawCh(Vector(20, i), '#', YELLOW);
			}

			for (int i = 0; i < 60; i += 2) {
				DM.drawCh(Vector(60, i), '#', YELLOW);
			}

			DM.drawCh(Vector(30, 4), '#', RED);
			DM.drawCh(Vector(34, 4), '#', RED);
			DM.drawCh(Vector(38, 4), '#', RED);
			DM.drawCh(Vector(34, 5.6), '#', RED);


		
				DM.drawCh(Vector(65, 2), 'N', WHITE);
				DM.drawCh(Vector(68, 2), 'E', WHITE);
				DM.drawCh(Vector(71, 2), 'X', WHITE);
				DM.drawCh(Vector(74, 2), 'T', WHITE);

				DM.drawCh(Vector(78, 2), 'U', WHITE);
				DM.drawCh(Vector(81, 2), 'P', WHITE);








			

			
			
			
			
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