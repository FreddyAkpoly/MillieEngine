#include "Event.h"

using namespace std;
namespace me {
	me::Event::Event()
	{
		string m_event_type = UNDEFINED_EVENT;
	}

	me::Event::~Event()
	{
	}

	void me::Event::setType(std::string new_type)
	{
		m_event_type = new_type;
	}

	std::string me::Event::getType() const
	{
		return m_event_type;
	}
}