# Spike Dodger

A challenging 2D arcade game built with C++ and SFML where players control a bouncing bird to avoid spike walls.

## Features
- Responsive jump mechanics
- Procedurally generated spike walls
- Wall bouncing with momentum
- Collision detection
- Clean object-oriented architecture

## Prerequisites
- SFML library
- C++17 compatible compiler

## Code Explanation

### 1. Constants and Includes

- **SFML headers**: Graphics, window, and system modules
- **STL containers**: vector, smart pointers, time (for random seeding)
- **Constants**: Tweakable game parameters

---

### 2. Bird Class

- **Responsible for**: Player physics and rendering
- **Key members**:
  - `shape`: SFML circle representing the bird
  - `position`: 2D vector (x,y coordinates)
  - `velocity`: Movement vector (horizontal/vertical speed)

---

### 3. SpikeWall Class

- **Responsible for**:
  - Procedural spike generation through rand()
  - Uses SFML's `intersects()` for AABB collision

---

### 4. Game Class (Core Logic)

- **Game loop**:
  1. **Handle input**: Spacebar for jumping
  2. **Update**: Physics and collisions
  3. **Render**: Draw all game objects

---

### 5. Main Function

- **Entry point**: Creates game instance and runs main loop

---

## Build Instructions

1. Install SFML
2. Execute "make" in command prompt

---

## Gameplay Controls
- **SPACE**: Jump
- **Automatic movement**: Left/right wall bouncing
- **Game reset**: On spike/floor contact
