/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: Task 6
 */
#include <iostream>
#include <string>

// Graphics rendering engine
class GraphicsRenderer {
public:
    void render() {
        std::cout << "Rendering graphics------" << std::endl;
    }
};

// Input handler
class InputHandler {
public:
    void handleInput() {
        std::cout << "Handling input------" << std::endl;
    }
};

// Physics engine
class PhysicsEngine {
public:
    void simulatePhysics() {
        std::cout << "Simulating physics------" << std::endl;
    }
};

// Game engine using composition
class GameEngine {
private:
    GraphicsRenderer graphicsRenderer;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void run() {
        graphicsRenderer.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        std::cout << "Game loop running..." << std::endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();

    return 0;
}
