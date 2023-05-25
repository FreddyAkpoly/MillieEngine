#include "LogManager.h"
#include "ErrorManager.h"
#include "GameManager.h"

bool gameManagerTest();
bool vectorTest();
void objectTest();
bool clockTest();

int main(int argc, char* argv[]) {

        GM.startUp();
        GM.run();
		clockTest();
		vectorTest();
		objectTest();
        GM.shutDown();
      

}

bool clockTest()
{
	me::Clock clock;

	clock.delta();// Start time
	Sleep(100);
	int t = (int)clock.split() / 1000000; // About 1 second .


	// Print time to logfile for debugging . 
	LM.writeLog(" split time t is % d", t);

	// See if reported 1 second as expected .
	if (t != 1) {
		LM.writeLog(" split time t is % d", t);
		return false;
	}
	// If we get here , test has passed.
	LM.writeLog(" % s passed.n", __func__);
	return true;
}

// Vector test
bool vectorTest()
{
	// Create Vector
	me::Vector vec = me::Vector(4.0f, 3.0f);
	LM.writeLog("Vector X, Y Coordinate: %f  %f\n", vec.getX(), vec.getY());

	// Check Test result
	if (vec.getX() != 4.0f && vec.getY() != 3.0f) {
		LM.writeLog("%s FAILED \n", __FUNCTION__);
		return false;
	}
	LM.writeLog("%s PASSED \n", __FUNCTION__);
	return true;

}

//Object test
void objectTest()
{

	//Creating 2 Objects
	LM.writeLog("Creating 2 Objects\n");
	me::Object* newObj = new me::Object();
	newObj->setType("Stone");

	me::Object* test_object2 = new me::Object();
	test_object2->setType("Tree");


}