
#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

// System includes.

#include <string>

// Engine includes.
#include "Manager.h"

#include "Sprite.h"
#define FRAMES_TOKEN "frames"
#define HEIGHT_TOKEN "height"
#define WIDTH_TOKEN "width"
#define COLOR_TOKEN "color"
#define END_FRAME_TOKEN "end"
#define END_SPRITE_TOKEN "eof"
// Two-letter acronym for easier access to manager.
#define RM me::ResourceManager::getInstance()

namespace me {

	// Maximum number of unique assets in game.
	const int MAX_SPRITES = 500;
	const int MAX_SOUNDS = 50;
	const int MAX_MUSICS = 50;

	class ResourceManager : public Manager {

	private:
		ResourceManager(ResourceManager const&); // Don't allow copy.
		void operator=(ResourceManager const&);  // Don't allow assignment.
		ResourceManager();		   // Private since a singleton.
		Sprite* m_p_sprite[MAX_SPRITES]; // Array of (pointers to) Sprites.
		int m_sprite_count;	           // Count of number of loaded sprites.
		

	public:
		// Get the one and only instance of the ResourceManager.
		static ResourceManager& getInstance();

		// Get ResourceManager ready to manage resources.
		int startUp();

		// Shut down manager, freeing up any allocated Sprites, Music and Sounds.
		void shutDown();

		// Load Sprite from file.
		// Assign indicated label to Sprite.
		// Return 0 if ok, else -1.
		int loadSprite(std::string filename, std::string label);

		// Unload Sprite with indicated label.
		// Return 0 if ok, else -1.
		int unloadSprite(std::string label);

		// Find Sprite with indicated label.
		// Return pointer to it if found, else NULL.
		Sprite* getSprite(std::string label) const;


	};

} // end of namespace df
#endif //__RESOURCE_MANAGER_H__
