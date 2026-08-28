# RoboTeamADT

RoboTeamADT is a C++ project that simulates a team of robots navigating and interacting in a 2D plane. This project focuses on applying concepts like Abstract Data Types (ADT), pointers, dynamic memory allocation, and basic Euclidean geometry within C++.

## Features

* **Robot Management:** Initialize a dynamic team of robots with specific coordinates `(X, Y)`, IDs, and ball possession statuses. All robots start with 100 energy points.
* **Kinematic Movement:** Move robots based on a velocity vector (magnitude), angle (in radians), and time duration. Movement realistically drains the robot's energy based on the distance traveled.
* **Distance Calculation:** Calculates the Euclidean distance between any two robots on the field using a custom 2D Point structure.
* **Proximity Detection:** Algorithm to determine the closest teammate to any given robot.
* **Ball Passing:** A robot can automatically locate its nearest teammate and pass the ball to them.

## Project Structure

* `main.cpp`: The entry point that parses standard input and processes simulation commands.
* `Ponto2D.hpp` / `Ponto2D.cpp`: Defines the `Ponto2D` struct handling 2D spatial coordinates and distance math.
* `Robo.hpp` / `Robo.cpp`: Defines the `Robo` struct, storing states (energy, position, ball possession) and implementing behavior methods.

## How to Build and Run

### Prerequisites
You will need a C++ compiler installed (e.g., `g++` or `clang++`).

### Compilation
Open your terminal, navigate to the project directory, and compile the source files together:

```bash
g++ -Wall main.cpp Ponto2D.cpp Robo.cpp -o roboteam
```

### Execution
Run the compiled binary:

```bash
./roboteam
```

## Input Format and Commands

The program reads continuously from standard input (`stdin`). 

### Initial State
1. **First line:** An integer `N` representing the number of robots.
2. **Next `N` lines:** `X` (double), `Y` (double), and `Has_Ball` (boolean `1` or `0`).
   * *Example: `0.0 0.0 1` (Robot at origin, possessing the ball)*

### Supported Commands
After initialization, the program accepts the following commands:
* `s`: Prints the status of all robots in the format: `ID X Y Has_Ball Energy`.
* `d`: Calculates and prints the distance between all possible pairs of robots.
* `m <id> <v> <th> <t>`: Moves the robot `<id>` with velocity `<v>`, angle `<th>` (radians), for duration `<t>`.
* `p <id>`: Finds the closest teammate to robot `<id>` and prints its current status.
* `b <id>`: Robot `<id>` passes the ball to its closest teammate. Prints an error if the robot doesn't have the ball.