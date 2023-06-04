
#include "Object.h"
#include "WorldManager.h"
#include <cstring>
#include <iostream>

namespace me {

	Object::Object() {
		static int id = 0;
		m_id = id++;
		m_type = "Object";
		m_position = Vector(0, 0);
		
		// Add self to WorldManager
		WM.insertObject(this);
	}

	void Object::setId(int new_id) {
		m_id = new_id;
	}

	int Object::getId() const {
		return m_id;
	}

	void Object::setType(std::string new_type) {
		m_type = new_type;
	}

	char* Object::getType() const {
		static char name[10]; // Static to retain the memory after the function returns
		strcpy_s(name, sizeof(name), m_type.c_str());
		return name;
	}

	void Object::setPosition(Vector new_pos) {
		m_position = new_pos;
	}

	Vector Object::getPosition() const {
		return m_position;
	}

	Object::~Object() {
		WM.removeObject(this);					//Remove Self from game world
	}

}