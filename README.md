# Array Jumper

## Overview
Welcome to **Array Jumper**, a strategic movement-based game that centers around mastering the traversal of a 1D array of blocks. The objective is to navigate through this array to reach the final destination while avoiding obstacles and managing limited lives. This project showcases my journey in game development, utilizing C++, SFML, and a structured architecture to deliver a challenging and fun experience.

## Features
- **Movement Mechanics**: 
  - Step forward or backward by one block.
  - Jump forward or backward based on the current block number.
- **Obstacle Avoidance**: 
  - Avoid obstacles that reset the level and cost you a life.
- **Lives Management**: 
  - Limited lives that add a layer of difficulty to the game.
- **Level Progression**: 
  - Reach the last block to complete each level.

## Learning Outcomes
- **Data Structures**: The game design centers around efficient manipulation and traversal of a 1D array, providing a deep dive into array-based logic and problem-solving.
- **Architecture Design**: Implemented a scalable architecture for maintainable and modular code.
- **Event Handling**: Created responsive controls for smooth gameplay.
- **Object-Oriented Design**: Enhanced understanding of OOP principles and practices.
- **Game Loop and State Management**: Maintained fluid transitions and consistent game state.
- **UI/UX Design**: Developed an intuitive interface that complements the gameplay.

## Project Structure

### Services and Their Model, View, and Controllers

- **GraphicService**: Manages game window and rendering operations.
- **EventService**: Handles user input and game events.
- **TimeService**: Manages game timing and countdowns.
- **SoundService**: Manages sound effects and music playback.
- **UIService**: Manages UI components.
  - UI Controllers: `SplashScreenUIController`, `MainMenuUIController`, `InstructionUIController`, `GameplayUIController`, `CreditsScreenUIController`
  - UI Elements: `UIView`, `TextView`, `ImageView`, `ButtonView`, `AnimatedImageView`
- **GameplayService**: Manages core gameplay mechanics.
  - Includes: `GameplayController`, `GameplayView`
- **LevelService**: Manages level logic and configuration.
  - Includes: `BlockType`, `LevelData`, `LevelConfiguration`, `LevelController`, `LevelModel`, `LevelView`
- **PlayerService**: Manages player-related logic.
  - Includes: `PlayerController`, `PlayerModel`, `PlayerView`

### Additional Core Components

- **Main**: Entry point of the game.
- **GameService**: Core service for game initialization and management.
  - Declares and manages all game states.
  - Manages the initialization, updating, and rendering of `ServiceLocator`.
- **ServiceLocator**: Manages the initialization, updating, and rendering of all the above-mentioned services, ensuring smooth communication and coordination among them.
- **Config**: Holds texture file locations for all assets, including sounds, animations, sprite textures, and fonts.

## How to Play

### Controls
- **Move**: Use the 'Left' and 'Right' arrow keys to move your player left or right.
- **Jump**: Hold the 'Space' key while pressing the 'Left' or 'Right' arrow keys to jump forward or backward.
  - The player will jump forward or backward by the value of the current cell.
- **Objective**: Reach the target cell to win the game.

1. **Clone the repository**:
    ```bash
    git clone https://github.com/123rishiag/Array-Jumper.git
    ```
2. **Build the project** using your preferred C++ compiler.
   - Ensure you have SFML installed. Installation instructions are available on SFML’s [official website](https://www.sfml-dev.org/).

3. **Run the executable** to start the game.

## Video Demo
Watch the [Video Demo](https://www.loom.com/share/97d1d95af163443b878ca7824d3b8491?sid=2f466137-0592-4e7f-aa89-dace1243aae6)
