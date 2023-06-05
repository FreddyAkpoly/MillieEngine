#include "Manager.h"
#include "GameManager.h"
#include "Vector.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h";
#include "Clock.h"
#include "Event.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include <Windows.h>
#include <assert.h>
#include<iostream>

void game();

using namespace me;
using namespace std;

int main(int argc, char* argv[]) {
	GM.startUp();

	game();
	
	GM.run();


}


class Saucer : public Object
{

public:
	Saucer()
	{
		setType("Saucer");
		
		Vector pos(7.0f, DM.getVertical() / 2.0f);
		setPosition(pos);
		
	}

	// TEST EVENTS
	int eventHandler(const Event* p_e) {
		if (p_e->getType() == KEYBOARD_EVENT)
		{
			const EventKeyboard* p_keyboard_event = dynamic_cast <const EventKeyboard*> (p_e);
			kbd(p_keyboard_event);
			return 1;
		}

		if (p_e->getType() == MSE_EVENT)
		{
			const EventMouse* p_mouse_event = dynamic_cast <const EventMouse*> (p_e);
			mouse(p_mouse_event);
			return 1;
		}

		if (p_e->getType() == COLLISION_EVENT)
		{

			const EventCollision* p_collision_event = dynamic_cast <const EventCollision*> (p_e);
			//WM.markForDelete(p_collision_event->getObject2());
			LM.writeLog("COLLISION OCCURED\n");
			
		}

		if (p_e->getType() == STEP_EVENT)
		{
			LM.writeLog("STEP EVENT\n");
			return 1;
		}

		if (p_e->getType() == OUT_EVENT)
		{
			LM.writeLog("OUT EVENT\n");
			return 1;
		}

		// If get here, have ignored this event.
		
		return 0;
	}

	void mouse(const EventMouse* p_mouse_event)
	{
		// Pressed button?
		if ((p_mouse_event->getMouseAction() == CLICKED) &&
			(p_mouse_event->getMouseButton() == Mouse::LEFT))
			std::cout << "Left Button Clicked\n";

		//if ((p_mouse_event->getMouseAction() == MOVED))
			//std::cout << "MOUSE MOVED\n";
	}

	// Take appropriate action according to key pressed.
	void kbd(const EventKeyboard* p_keyboard_event)
	{

		switch (p_keyboard_event->getKey())
		{
		case Keyboard::W:			// up
			if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED)
				move(-1);
			break;
		case Keyboard::S:			// down
			if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED)
				move(+1);
			break;
		case Keyboard::A:			// left
			if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED)
				moveX(-1);
			break;
		case Keyboard::D:			// right
			if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED)
				moveX(+1);
			break;
		case Keyboard::Q:			// right
			if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED)
				GM.setGameOver(true);
			break;
		};

		return;
	}

	void move(int dy) {
		Vector new_pos(getPosition().getX(), getPosition().getY() + dy);
		// If stays on screen, allow move.
		if ((new_pos.getY() >= 0) &&
			(new_pos.getY() < DM.getVertical()))
		WM.moveObject(this, new_pos);
	}

	void moveX(int dx) {
		Vector new_pos(getPosition().getX() + dx, getPosition().getY() );
		// If stays on screen, allow move.
		if ((new_pos.getX() >= 0) &&
			(new_pos.getX() < DM.getHorizontal()))
			WM.moveObject(this, new_pos);
	}


};



void game() {

	

	//test_object->setDirection(Vector(1, 0));
	//test_object->setSpeed(0.5f);

	new Saucer;

	Object* block_object = new Object();
	block_object->setAltitude(2);
	block_object->setPosition(Vector(30, 0));
	block_object->setSolidness(SOFT);

	Object* block_object2 = new Object();
	block_object2->setAltitude(2);
	block_object2->setPosition(Vector(7, 20));
	block_object2->setSolidness(SOFT);

	Object* block_object3 = new Object();
	block_object3->setAltitude(2);
	block_object3->setPosition(Vector(30, 20));
	block_object3->setSolidness(SOFT);


	
}


