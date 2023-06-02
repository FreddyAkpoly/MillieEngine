

#ifndef __me_VECTOR_H__
#define __me_VECTOR_H__

namespace me {

	class Vector {

	private:
		float m_x; 			//< Horizontal component.
		float m_y; 			//< Vertical component.

	public:

		// Create Vector with (x,y).  
		Vector(float init_x, float init_y);

		// Default is (0,0).
		Vector();

		void setX(float new_x);	        // Set horizontal component.
		float getX() const;		        // Get horizontal component.
		void setY(float new_y);	        // Set vertical component.
		float getY() const;		        // Get vertical component.
		void setXY(float new_x, float new_y); // Set horizizontal & vertical.
		void normalize();			// Normalize vector.
		void scale(float s);			// Scale vector.
		float getMagnitude() const;		// Return magnitude.
		Vector operator+(const Vector& other) const; // Add Vector.
	};

} // end of namespace me
#endif //__me_VECTOR_H__
