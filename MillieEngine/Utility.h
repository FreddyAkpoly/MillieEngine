#pragma once

#include "Vector.h"

namespace me
{
	class Utility
	{

	public:
		char* getTimeString();

		// detect collsion at a position and return true if two positions intersect, else false
		static bool positionsIntersect(Vector p1, Vector p2);
	};
}