//
// WorldManager - The game world manager.
//
// Copyright 2017-2022 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include "ObjectList.h"
#include "Vector.h"

// Two-letter acronym for easier access to manager.
#define WM me::WorldManager::getInstance()

namespace me {

	const int MAX_ALTITUDE = 4;

	class WorldManager : public Manager {

	private:
		WorldManager();                 // Private since a singleton.
		WorldManager(WorldManager const&);  // Don't allow copy.
		void operator=(WorldManager const&); // Don't allow assignment.
		ObjectList m_updates;		  // All Objects in game world.
		ObjectList m_deletions;         // List of all Objects to delete.
		Object* m_p_view_following;     // Object view is following.
		Vector m_view_slack;	          // "Slack" for view following.

	public:
		// Get the one and only instance of the WorldManager.
		static WorldManager& getInstance();

		// Startup game world (initialize everything to empty).
		// Return 0.
		int startUp();

		// Shutdown game world (delete all game world Objects).
		void shutDown();

		// Insert Object into world.
		// Return 0 if ok, else -1.
		int insertObject(Object* p_o);

		// Remove Object from world.
		// Return 0 if ok, else -1.
		int removeObject(Object* p_o);

		// Return list of all Objects in world.
		ObjectList getAllObjects() const;

		ObjectList ObjectsOfType(std::string type) const;
		
	};

} // end of namespace df
#endif // __WORLD_MANAGER_H__
