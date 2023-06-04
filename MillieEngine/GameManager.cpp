#include "GameManager.h"


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
			LM.writeLog("Game Manager Started %s", LM.getTimeString());

			//Creating 2 Objects
			LM.writeLog("Creating 2 Objects\n");
			Object* newObj = new Object();
			newObj->setType("Stone");
			Vector vec1 = Vector(4.0f, 3.0f);
			newObj->setPosition(vec1);
			

			Object* test_object2 = new Object();
			test_object2->setType("Tree");
			Vector vec2 = Vector(10.0f, 10.0f);
			test_object2->setPosition(vec2);

			//Getting ObjectList from WM
			LM.writeLog("Getting ObjectList from World Manager\n");
			ObjectList test_object_list = WM.getAllObjects();

			// isFull, isEmpty, Count
			LM.writeLog("is Object List Empty: %d \n", test_object_list.isEmpty());
			LM.writeLog("is Object List Full: %d \n", test_object_list.isFull());
			LM.writeLog("Object Count: %d \n", test_object_list.getCount());

			// Using Iterator
			LM.writeLog("Iterating through List using ListIterator\n");
			ObjectListIterator list_itr(&test_object_list);
			for (list_itr.first(); !list_itr.isDone(); list_itr.next())
			{
				LM.writeLog(" Object type : %s\n", list_itr.currentObject()->getType());
				LM.writeLog(" Object ID: %d \n", list_itr.currentObject()->getId());
				LM.writeLog(" Object Pos X: %f ", list_itr.currentObject()->getPosition().getX());
				LM.writeLog(" Object Pos Y: %f \n", list_itr.currentObject()->getPosition().getY());
				

			}


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
				Clock clock;
				long int start_time = clock.delta();

				long int end_time = clock.split() / 1000000;
				Sleep((frame_time - end_time));

				

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