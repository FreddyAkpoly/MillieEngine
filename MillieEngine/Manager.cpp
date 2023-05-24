#include "Manager.h"

namespace me {

	Manager::Manager() {
		setType("Manager");
		m_is_started = false;
	}


	void Manager::setType(std::string type) {
		m_type = type;
	}

	std::string Manager::getType() const {
		return m_type;
	}

	int me::Manager::startUp()
	{
		m_is_started = true;
		return 0;
	}

	void me::Manager::shutDown()
	{
		m_is_started = false;
	}

	bool me::Manager::isStarted() const
	{
		return m_is_started;
	}
}