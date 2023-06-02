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

