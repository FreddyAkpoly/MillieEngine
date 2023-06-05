#pragma once
#include "Event.h"

namespace me {
	const std::string OUT_EVENT = "out";

	class EventOut : public Event
	{
	public:
		EventOut();
	};

}