# MILLIE ENGINE

This project is a game engine that provides a foundation for developing interactive and immersive games. The game engine is designed to handle core functionalities such as error handling, resource management, rendering, scene management, audio playback, and user input.

## Usage

To use the game engine, developers can extend and customize the engine by creating game-specific components, such as game objects, scripts, and logic, while leveraging the provided managers for core functionalities. The engine provides a modular and scalable architecture, allowing for easy integration of custom features and behaviors.

## Getting Started

For detailed instructions on getting started with the game engine, refer to the documentation included with the project. The documentation provides information on setting up the development environment, using the engine's features, and implementing game logic.

## Contributing

Contributions to the game engine project are welcome. If you find any issues, bugs, or have suggestions for improvements, please submit them through the issue tracker or consider contributing code enhancements by creating pull requests.

## License

The game engine project is released under the [MIT License](LICENSE). You are free to use, modify, and distribute the engine's source code for both commercial and non-commercial purposes. Refer to the license file for more details.

## Acknowledgements

I would like to acknowledge and express gratitude to "Game Engine Design and Implementation, " by Alan Thorn for guidance into creating the engine.

Please refer to the individual documentation of each manager for more details on their usage and functionalities.

## The Architecture
The core architecture of the game engine can be outlined as follows:

1. **Error Manager**: The Error Manager handles and logs errors that occur within the game engine or during gameplay. It provides error handling and reporting functionalities.

2. **Resource Manager**: The Resource Manager is responsible for managing game resources such as textures, models, sounds, and other assets. It handles loading, unloading, and caching of resources to optimize memory usage.

3. **Render Manager**: The Render Manager handles rendering and graphics-related tasks. It interacts with the graphics API (such as DirectX or OpenGL) to render game objects, apply shaders, manage the rendering pipeline, and handle graphics-related configurations.

4. **Scene Manager**: The Scene Manager manages the game's scenes or levels. It handles scene transitions, loading and unloading of scenes, managing the hierarchy of game objects within a scene, and updating the scene's state.

5. **Audio Manager**: The Audio Manager handles audio-related tasks such as playing background music, sound effects, and managing audio resources. It provides functionalities for loading and playing audio files, controlling volume, and handling audio-related events.

6. **Input Manager**: The Input Manager manages user input from various input devices such as keyboard, mouse, gamepad, or touch screen. It captures input events, processes them, and provides an interface for handling player input within the game.

These managers work together to provide a structured and modular architecture for the game engine. Each manager has its specific responsibilities and interacts with other managers as necessary. This architecture allows for separation of concerns and facilitates the development of scalable and maintainable game systems.


# Manager

## Overview

The `Manager` class serves as a base class for various managers in the game system. It provides basic functionality related to manager initialization and shutdown. Each specific manager in the system should inherit from this base class.

## Initialization

The `startUp()` function is responsible for initializing the manager. By default, it sets the `m_is_started` flag to true, indicating that the manager has been started. Derived classes can override this function to perform additional initialization tasks specific to their functionality.

## Shutting Down

The `shutDown()` function is responsible for shutting down the manager. It sets the `m_is_started` flag to false, indicating that the manager has been stopped. Derived classes can override this function to perform any necessary cleanup operations before shutting down.

## Manager Type

The `setType()` function allows setting the type of the manager. The type is represented as a string. This can be useful for identifying the specific type of a manager instance. The `getType()` function returns the type of the manager.

## Manager Status

The `isStarted()` function returns the status of the manager. It returns true if the manager has been started, and false if it has been shut down.

# GameManager

## Overview

The `GameManager` class is an integral part of the game system. It manages the overall game flow, including starting up the game, running the game loop, and shutting down the game. It also keeps track of game-related information such as the game over status, frame time, and step count.

## Initialization

To initialize the `GameManager`, call the `startUp()` function. This function sets up the necessary components for the game, including logging. If the initialization is successful, it returns 0; otherwise, an exception is thrown.

## Game Loop

The `run()` function is responsible for running the game loop. Inside the loop, the game checks if the game over condition has been met. If not, it performs necessary operations and updates the game state. The loop runs continuously until the game over condition is set to true.

The loop includes a frame timing mechanism to control the frame rate of the game. It calculates the time taken for each iteration of the loop and adjusts the sleep time accordingly to maintain a consistent frame rate.

## Game Over

The game over status can be accessed and modified using the `getGameOver()` and `setGameOver()` functions, respectively. The `setGameOver()` function allows you to change the game over status. By default, the game over status is set to false when the `GameManager` is initialized.

## Additional Information

- The `FRAME_TIME_DEFAULT` constant represents the default frame time in milliseconds.
- The `isValid()` function is currently not implemented and always returns false. It can be utilized to validate specific game events.
- The `shutDown()` function is responsible for shutting down the game. It sets the game over status to true, writes a log message, and shuts down the necessary components, such as logging.

# LogManager

## Overview

The `LogManager` class provides logging functionality for the game. It allows writing log messages to a log file. The class follows the singleton design pattern, ensuring that only one instance of the `LogManager` can exist.

## Initialization

To initialize the `LogManager`, call the `startUp()` function. This function sets up the necessary components for logging, including creating the log file. If the initialization is successful, it returns 0; otherwise, it returns -1.

## Writing Log Messages

To write a log message, use the `writeLog()` function. It takes a format string and additional arguments, similar to `printf()`. The log message is written to the log file. If the log file is open and the write operation is successful, the function returns the number of characters written; otherwise, it returns -1.

The `getTimeString()` function is a helper function that returns a formatted string representing the current time. It is used to include the timestamp in log messages.

## Flushing the Log File

By default, the log file is not flushed after each write operation. To enable flushing, use the `setFlush()` function and pass `true` as the argument. Flushing ensures that the log messages are immediately written to the file, rather than being buffered. Flushing can be useful in certain situations to ensure real-time logging.

## Shutting Down

To shut down the `LogManager`, call the `shutDown()` function. It closes the log file, cleans up any resources, and shuts down the manager.

# ErrorManager

## Overview

The `ErrorManager` class is responsible for handling and logging errors that occur within the game. It follows the singleton design pattern to ensure that only one instance of the `ErrorManager` can exist.

## Getting the ErrorManager Instance

To obtain the singleton instance of the `ErrorManager`, use the `getInstance()` function. It returns a reference to the `ErrorManager` instance.

## Logging Errors

The `what()` function is used to log errors. It takes a `std::exception` object as an argument and logs the error message along with a timestamp. The error message is obtained using the `what()` function of the `std::exception` object. The logged error message is then returned.

## LogManager Dependency

The `ErrorManager` class has a dependency on the `LogManager` class. It uses the `writeLog()` function of the `LogManager` to write error messages to the log file.

# Display Manager

The Display Manager is a component of the game engine that handles graphics and visual display. It provides functionalities for opening and managing a graphics window, rendering characters and strings, and converting between ASCII spaces and window pixels.

## Features

- **Window Management**: The Display Manager handles the creation and management of the graphics window. It allows for setting the window size, title, style, and background color. The manager provides methods for opening and closing the window.

- **ASCII Rendering**: The manager supports rendering ASCII characters and strings at specific locations in the graphics window. It allows for specifying the character, color, and justification (left, center, or right) of the rendered text.

- **Coordinate Conversion**: The Display Manager provides methods to convert between ASCII spaces (character coordinates) and window pixels. Developers can use these methods to position and align game objects and text within the graphics window.

- **Window Buffer Rendering**: The manager handles the rendering of the window buffer, ensuring that the rendered content is visible on the screen. It provides a method to swap the front and back buffers, updating the displayed content.

## Usage

To utilize the Display Manager in your game, follow these steps:

1. Get the singleton instance of the Display Manager using the `getInstance()` method.
2. Call the `startUp()` method to initialize the graphics window and prepare it for display.
3. Use the various rendering methods (`drawCh()` and `drawString()`) to render ASCII characters and strings at specific locations in the window.
4. To update the displayed content, call the `swapBuffers()` method.
5. Finally, when your game is finished, call the `shutDown()` method to close the graphics window and clean up resources.

Please refer to the documentation included with the project for more detailed information on the usage and available functionalities of the Display Manager.

## Dependencies

The Display Manager relies on the SFML (Simple and Fast Multimedia Library) for graphics rendering and window management. Make sure to have SFML installed and properly configured in your development environment.

# Resource Manager

The Resource Manager is a component of the game engine that handles the loading and management of game resources, such as sprites. It provides functionalities for loading sprites from sprite files, storing them in memory, and retrieving them for use in the game.

## Features

- **Sprite Loading**: The Resource Manager supports the loading of sprites from sprite files. The sprite files contain information about the frames, dimensions, and color of the sprite. The manager reads the sprite file, constructs the corresponding Sprite object, and stores it in memory for later use.

- **Sprite Management**: The manager keeps track of the loaded sprites and provides methods to retrieve a sprite by its label. It allows for unloading sprites from memory when they are no longer needed, freeing up system resources.

- **Sprite File Format**: The Resource Manager expects sprite files to follow a specific format. The format includes tags and values for specifying the number of frames, width, height, color, and frame data. The manager reads and parses the sprite file according to this format to construct the sprite object accurately.

## Usage

To utilize the Resource Manager in your game, follow these steps:

1. Get the singleton instance of the Resource Manager using the `getInstance()` method.
2. Call the `startUp()` method to initialize the manager.
3. Use the `loadSprite()` method to load sprites from sprite files. Provide the filename and a unique label for each sprite. The manager will read the sprite file, construct the sprite object, and store it in memory.
4. When you need to use a sprite in your game, call the `getSprite()` method, passing the sprite's label. The manager will return the corresponding sprite object.
5. If a sprite is no longer needed, call the `unloadSprite()` method, passing the sprite's label. The manager will remove the sprite from memory, freeing up system resources.
6. Finally, when your game is finished, call the `shutDown()` method to clean up resources and shut down the manager.

Please refer to the documentation included with the project for more detailed information on the usage and available functionalities of the Resource Manager.

## Dependencies

The Resource Manager does not have any external dependencies. It is designed to work within the game engine framework.

# World Manager

The World Manager is a component of the game engine that manages the game world and objects within it. It provides functionalities for inserting and removing objects from the world, updating their positions, handling collisions, and rendering them in the graphics window.

## Features

- **Object Management**: The World Manager allows for inserting and removing objects from the game world. Objects can be added or removed dynamically during gameplay.

- **Object Update**: The manager updates the positions of objects based on their velocities. It predicts the new position of each object and moves them accordingly. Objects with solidness are checked for collisions with other solid objects.

- **Collision Handling**: The World Manager provides collision detection and handling for objects in the game world. It detects collisions between objects and triggers collision events. Objects can respond to collision events and perform appropriate actions.

- **Rendering**: The manager handles the rendering of objects in the graphics window. It maintains a list of objects to be rendered and organizes them based on their altitudes. Objects are rendered in the correct order to achieve a visually appealing scene.

- **Boundary Detection**: The World Manager detects if an object goes out of the game world's boundaries. It triggers an "out of bounds" event for the object, allowing for custom handling or removal of the object.

## Usage

To utilize the World Manager in your game, follow these steps:

1. Get the singleton instance of the World Manager using the `getInstance()` method.
2. Call the `startUp()` method to initialize the manager.
3. Create objects in your game and insert them into the world using the `insertObject()` method.
4. Implement the necessary event handlers in your objects to respond to collisions and boundary events.
5. In your game loop, call the `update()` method of the World Manager to update the positions of objects and handle collisions.
6. Call the `draw()` method to render the objects in the graphics window.
7. Optionally, mark objects for deletion using the `markForDelete()` method to remove them from the world.
8. Finally, when your game is finished, call the `shutDown()` method to clean up resources.

Please refer to the documentation included with the project for more detailed information on the usage and available functionalities of the World Manager.

## Dependencies

The World Manager relies on other components of the game engine, such as the Object Manager, Event Manager, and Display Manager. Make sure to have these components properly integrated into your project and configured.

# DEMO
![Millie Engine Tetris](https://github.com/FreddyAkpoly/MillieEngine/blob/master/MillieEngine.png)
