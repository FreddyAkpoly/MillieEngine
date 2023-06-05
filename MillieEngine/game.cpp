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
#include "DisplayManager.h"


#include <Windows.h>
#include <assert.h>
#include<iostream>

bool DisplayTest();
using namespace me;
using namespace std;

int main(int argc, char* argv[]) {
	GM.startUp();

	DisplayTest();

	GM.run();

	GM.shutDown();

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
};

bool DisplayTest() {

	DM.setBackgroundColor(WHITE);
	DM.drawString(Vector(10, 20), "HELLO", LEFT_JUSTIFIED, YELLOW);
	return true;

}
