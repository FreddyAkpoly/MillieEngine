#pragma once
#include<string>
#include "Event.h"

namespace me
{

	class Event;

	class Manager
	{
	private:
		std::string m_type;        // Manager type identifier
		bool m_is_started;         //True when started successfully

	protected:
		void setType(std::string type);    // set type identifier of the manager

	public:
		Manager();
		virtual ~Manager();

		std::string getType() const;   // get type identifier of manager

		virtual int startUp();      // Startup the manager. Return 0 if ok, else negative number.

		virtual void shutDown();     // Shutdown manager

		bool isStarted() const;      // Return true when startUp() was executed ok, else false

		int onEvent(const Event* p_event) const;   //Send event to all interested Objects.Return count of number of events sent. 

	};

}   // end of namespace df