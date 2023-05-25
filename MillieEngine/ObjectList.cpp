#include "ObjectList.h"

namespace me {
	me::ObjectList::ObjectList()
	{
		m_count = 0;
		m_p_obj[MAX_OBJECTS] = NULL;
	}

	int me::ObjectList::insert(Object* p_o)
	{
		if (!isFull()) {
			m_p_obj[m_count] = p_o;
			m_count++;
			return 0;
		}
		return -1;
	}

	int me::ObjectList::remove(Object* p_o)
	{
		for (int i = 0; i < m_count;i++) {
			if (m_p_obj[i]==p_o) {
				for (int j = i; j < m_count - 1;j++) {
					m_p_obj[j] = m_p_obj[j + 1];
				}
				m_count--;
				return 0;
			}
		}
		return -1;
	}

	void me::ObjectList::clear()
	{
		m_count = 0;
	}

	int me::ObjectList::getCount() const
	{
		return m_count;
	}

	bool me::ObjectList::isEmpty() const
	{
		if (m_count == 0)
			return true;
		return false;
	}

	bool me::ObjectList::isFull() const{

		if(m_count == MAX_OBJECTS)
			return true;
		return false;
		
	}
}

