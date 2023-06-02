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
