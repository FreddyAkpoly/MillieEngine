

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


