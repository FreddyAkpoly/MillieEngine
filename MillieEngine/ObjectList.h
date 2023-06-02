
#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

#include "Object.h"
#include "ObjectListIterator.h"

namespace me {

	const int MAX_OBJECTS = 2000;

	class ObjectListIterator;

	class ObjectList {

	private:
		int m_count;                    // Count of objects in list.
		Object* m_p_obj[MAX_OBJECTS];   // Array of pointers to objects.

	public:
		friend class ObjectListIterator;           // Iterators can access.

		// Default constructor.
		ObjectList();

		// Insert object pointer in list.
		// Return 0 if ok, else -1.
		int insert(Object* p_o);

		// Remove object pointer from list,
		// Return 0 if found, else -1.
		int remove(Object* p_o);

		// Clear list (setting count to 0).
		void clear();

		// Return count of number of objects in list.
		int getCount() const;

		// Return true if list is empty, else false.
		bool isEmpty() const;

		// Return true if list is full, else false.
		bool isFull() const;
	};

} // end of namespace me
#endif // __OBJECT_LIST_H__
