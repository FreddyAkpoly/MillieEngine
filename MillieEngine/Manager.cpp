#include "Manager.h"
#include "WorldManager.h"
#include "ObjectListIterator.h"


namespace me {
	Manager::Manager()
	{
		m_is_started = false;
	}

	int Manager::startUp()  // return 0 if the value of m_is_started is true
	{
		m_is_started = true;
		return 0;
	}

	void Manager::shutDown()    //
	{
		m_is_started = false;
	}

	bool Manager::isStarted() const   // to return the value of boolean m_is_started
	{
		return m_is_started;
	}
	void Manager::setType(std::string type)
	{
		m_type = "Manager";  // to set the type of manager to type

	}
	std::string Manager::getType() const
	{
		return m_type;   // to get type of m_type
	}

	Manager::~Manager()
	{
		shutDown();
	}

	// Send event to all Objects.
	// Return count of number of events sent.

	int Manager::onEvent(const Event* p_event) const
	{
		int count = 0;

		ObjectList all_Objects = WM.getAllObjects();
		ObjectListIterator iter(&all_Objects);
		for (iter.first(); !iter.isDone(); iter.next())
		{
			iter.currentObject()->eventHandler(p_event);
			count++;
		}


		return count;

	}

}