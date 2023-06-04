#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Vector.h"

namespace me {
	class Object {
	private:
		int m_id;
		std::string m_type;
		Vector m_position;
	public:
		// Construct Object. 
	// Set default parameters and add to game world (WorldManager).
		Object();

		// Destroy object, removing itself from game world (WorldManager).
		virtual ~Object();

		// Set Object id.
		void setId(int new_id);

		// Get Object id.
		int getId() const;

		// Set type identifier of Object.
		void setType(std::string new_type);

		// Get type identifier of Object.
		char* getType() const;

		// Set position of Object.
		virtual void setPosition(Vector new_position);

		// Get position of Object.
		Vector getPosition() const;

	};
}

#endif // __OBJECT_H__