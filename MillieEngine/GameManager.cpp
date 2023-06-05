#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "DisplayManager.h"
#include "ErrorManager.h"

#include <iostream>
#include <Windows.h>

const int FRAME_TIME_DEFAULT = 33;
namespace me {
	GameManager::GameManager() {
		setType("GameManager");
		m_game_over = false;
		m_step_count = 0;
		frame_time = FRAME_TIME_DEFAULT;
	}

	GameManager& GameManager::getInstance()
	{
		static GameManager instance;
		return instance;
	}

	int GameManager::startUp()
	{
		try {
			LM.startUp();
			WM.startUp();
			DM.startUp();
			LM.writeLog("Game Manager Started %s", LM.getTimeString());

			
			
			return 0;
		}
		catch (const std::exception& e) {
			EM.what(e);
		}
		return 1;
	}

	bool GameManager::isValid(std::string event_name) const
	{
		return false;
	}

	void GameManager::shutDown()
	{
		setGameOver(true);
		LM.writeLog("Game Manager Shuting down. %s", LM.getTimeString());
		LM.shutDown();

	}

	void GameManager::run()
	{
		try {
			
			while (!m_game_over)
			{
				int x = 1;
				Clock clock;
				long int start_time = clock.delta();

				WM.update();
				WM.draw();
				DM.swapBuffers();


				long int end_time = clock.split() / 1000000;

				Sleep((frame_time - end_time));

				if(x == 2)
				 setGameOver(true);
			}
		}
		catch (const std::exception& e) {
			EM.what(e);
		}
	}

	void GameManager::setGameOver(bool new_game_over)
	{
		if (new_game_over)
			m_game_over = new_game_over;
	}

	bool GameManager::getGameOver() const
	{
		return m_game_over;
	}

	int GameManager::getFrameTime() const
	{
		return frame_time;
	}

	int GameManager::getStepCount() const
	{
		return m_step_count;
	}

}