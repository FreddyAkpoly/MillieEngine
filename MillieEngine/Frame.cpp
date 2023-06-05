#include "Frame.h"
#include "DisplayManager.h"
namespace me {
	me::Frame::Frame()
	{

	}

	me::Frame::Frame(int new_width, int new_height, std::string new_frame_str)
	{
		m_width = new_width;
		m_height = new_height;
		m_frame_str = new_frame_str;
	
	}

	void me::Frame::setWidth(int new_width)
	{
		m_width = new_width;
	}

	int me::Frame::getWidth() const
	{
		return m_width;
	}

	void me::Frame::setHeight(int new_height)
	{
		m_height = new_height;
	}

	int me::Frame::getHeight() const
	{
		return m_height;
	}

	void me::Frame::setString(std::string new_frame_str)
	{
		m_frame_str = new_frame_str;
	}

	std::string me::Frame::getString() const
	{
		return m_frame_str;
	}

	int me::Frame::draw(Vector position, Color color) const
	{
		if (m_frame_str.empty()) {
			return -1;
		}
		else {
			float x_offset = getWidth()/2;
			float y_offset = getHeight()/2;

			for (int y = 0; y < m_height; y++) {
				for (int x = 0; x < m_width; x++) {
					Vector temp_pos(position.getX() + x - x_offset, position.getY() + y - y_offset);
					DM.drawCh(temp_pos, m_frame_str[y * m_width + x], color);
				}
				
			}
		}
	}


}
