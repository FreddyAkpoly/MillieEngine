#include "Sprite.h"

namespace me {


me::Sprite::~Sprite()
{
	if (m_frame != nullptr) {
		delete[] m_frame;
	}
}

me::Sprite::Sprite(int max_frames)
{
	m_frame_count = 0;
	m_width = 0;
	m_height = 0;
	m_frame = new Frame[max_frames];
	m_max_frame_count = max_frames;
	m_color = COLOR_DEFAULT;
}

void me::Sprite::setWidth(int new_width)
{
	m_width = new_width;
}

int me::Sprite::getWidth() const
{
	return m_width;
}

void me::Sprite::setHeight(int new_height)
{

	m_height = new_height;
}

int me::Sprite::getHeight() const
{
	return m_height;
}

void me::Sprite::setColor(Color new_color)
{
	m_color = new_color;
}

Color me::Sprite::getColor() const
{
	return m_color;
}

int me::Sprite::getFrameCount() const
{
	return m_frame_count;
}

int me::Sprite::addFrame(Frame new_frame)
{
	if (m_frame_count == m_max_frame_count) { // Is Sprite full?
		return -1; // Return an error value (e.g., -1) to indicate that the sprite is full
	}
	else {
		m_frame[m_frame_count] = new_frame;
		m_frame_count++;
		return 0; // Return a success value (e.g., 0) to indicate that the frame was added successfully
	}
}

Frame me::Sprite::getFrame(int frame_number) const
{
	if ((frame_number < 0) || (frame_number >= m_frame_count)) {
		Frame empty; // Create an empty frame
		return empty; // Return the empty frame
	}
}

void me::Sprite::setLabel(std::string new_label)
{
	m_label = new_label;
}

std::string me::Sprite::getLabel() const
{
	return m_label;
}

void me::Sprite::setSlowdown(int new_sprite_slowdown)
{
	m_slowdown = new_sprite_slowdown;
}

int me::Sprite::getSlowdown() const
{
	return m_slowdown;
}

int me::Sprite::draw(int frame_number, Vector position) const
{
	return 0;
}
}