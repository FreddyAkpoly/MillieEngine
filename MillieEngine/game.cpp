#include "GameManager.h"
#include "SFML/Window.hpp"
using namespace me;
using namespace std;
bool eventTest();
int main(int argc, char* argv[]) {
    GM.startUp();
    GM.run();
	eventTest();
    GM.shutDown();

}

bool eventTest()
{

	//Creating Event
	Event* new_event = new Event();
	

	EventStep step_event;

	LM.writeLog("New Event: %s \n", new_event->getType());
	if (new_event->getType() == "TEST_EVENT") {
		LM.writeLog("Success\n");
		return true;
	}

	return false;
}