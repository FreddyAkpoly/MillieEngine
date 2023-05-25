#include "Object.h"

namespace me {
	me::Object::Object()
	{

		 m_id = NULL;
		 m_type = "Object";
		 m_position = Vector(0,0);
	}

	void me::Object::setId(int new_id)
	{
		m_id = new_id;
	}

	int me::Object::getId() const
	{
		return m_id;
	}

	void me::Object::setType(std::string new_type)
	{
		m_type = new_type;
	}

	std::string me::Object::getType() const
	{
		return std::string();
	}

	void me::Object::setPosition(Vector new_position)
	{
		m_position = new_position;
	}

	Vector me::Object::getPosition() const
	{
		return m_position;
	}

}

