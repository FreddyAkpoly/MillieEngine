#pragma once

#include "Manager.h"

#define GM me::GameManager::getInstance()

namespace me
{
	class GameManager : public Manager
	{
	private:

		GameManager();   // it's private bcoz it's a singleton class
		GameManager(GameManager const&);   // Don't allow copy
		void operator = (GameManager const&);  //Don't allow assignment
		bool game_over;  // if true then game loop should stop
		int frame_time;  // Target time per game loop in milliseconds

	public:

		//Get the singleton instance of the GameManager.
		static GameManager& getInstance();

		//Startup all GameManager services.
		int startUp();

		//Shut down GameManager services.
		void shutDown();

		//Run game loop
		void run();

		// Set game over status to indicated value.
		// If true (default), will stop the game loop.
		void setGameOver(bool new_game_over = true);

		//get game over status
		bool getGameOver() const;

		// Return Frame Time.
		// Frame time is target time for game loop, in milliseconds.
		int getFrameTime() const;

	};
}