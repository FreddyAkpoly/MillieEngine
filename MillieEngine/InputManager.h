#pragma once
#include "Manager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include <SFML/Graphics.hpp>

// Two-letter acronym for easier access to manager.
#define IM me::InputManager::getInstance()

namespace me {

	class InputManager : public Manager
	{
	private:

		InputManager();
		InputManager(InputManager const&);
		void operator=(InputManager const&);

	public:
		// Get the one and only instance of the InputManager.
		static InputManager& getInstance();

		// Get window ready to capture input.
		// Return 0 it ok, else -1
		int startUp();

		// Revert back to normal window mode.
		void shutDown();

		// Get input from the keyboard and mouse.
		// Pass event along to all Objects.
		void getInput();

		//return equivalent DragonFly key code
		Keyboard::key getDfCode(int n);

		//return equivalent dragonfly mouse code
		Mouse::Button getDfMouseCode(int n);
	};
}