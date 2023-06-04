#include "GameManager.h"
#include "WorldManager.h"

void objectTest();
using namespace me;
using namespace std;
int main(int argc, char* argv[]) {
    GM.startUp();
    GM.run();
	objectTest();
    GM.shutDown();
}

void objectTest()
{
	
	
	//Creating 2 Objects
	LM.writeLog("Creating 2 Objects\n");
	Object* newObj = new Object();
	newObj->setType("Stone");

	Object* test_object2 = new Object();
	test_object2->setType("Tree");


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
		LM.writeLog(" Object type : % s\n", list_itr.currentObject()->getType());
		LM.writeLog(" Object ID: %d \n", list_itr.currentObject()->getId());

	}


}