#include "WorldManager.h"
#include "Object.h"
#include "ObjectListIterator.h"


#include<iostream>

namespace me {

	WorldManager::WorldManager() {
		setType("WorldManager");
	}


	// Get one and only instance of world manager
	WorldManager& WorldManager::getInstance() {
		static WorldManager WorldManagerSingle;
		return WorldManagerSingle;
	}

	int WorldManager::startUp() {
		Manager::startUp();
		return 0;
	}

	void WorldManager::shutDown() {
		ObjectList list = m_updates;
		ObjectListIterator li(&list);

		for (li.first(); !li.isDone(); li.next()) {
			delete li.currentObject();
		}

		Manager::shutDown();
	}

	// Insert Objects into world.
	// Return 0 if ok, or else -1 
	int WorldManager::insertObject(Object* p_o) {
		return m_updates.insert(p_o);

	}

	// Remove Obejcts from world
	// Return 0 if ok, or else -1
	int WorldManager::removeObject(Object* p_o) {
		return m_updates.remove(p_o);
	}

	// Return list of all Objects in world
	ObjectList WorldManager::getAllObjects() const {
		return m_updates;
	}

	// Return list of all objects in the world that matches 
	ObjectList WorldManager::ObjectsOfType(std::string type) const {
		ObjectList list;
		ObjectListIterator li(&m_updates);

		for (li.first(); !li.isDone(); li.next()) {
			if (li.currentObject()->getType() == type) {
				list.insert(li.currentObject());
			}
		}

		return list;
	}

	
}