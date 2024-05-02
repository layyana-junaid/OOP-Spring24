#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemy.hpp"
#include "grid.hpp"
#include "wall.hpp"
#include "goal.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Clock delay;
    Goal *goal;

    std::vector<Entity *> entities;
    Grid grid;

    void assign(Entity *, sf::Vector2u);

    void addWall(unsigned, unsigned);
public:
    Game();

    void updateEvents();

    void update();
    void render();

    void run();

    ~Game();
};

void Game::assign(Entity *entity, sf::Vector2u position) {
    entity->setPosition(grid.insert(entity, position));
}

Game::Game() : window(sf::VideoMode(800, 600), "Game"), grid(sf::Vector2u(20, 15), window.getSize()) {
    window.setFramerateLimit(60);

    goal = new Goal(18.f);
    goal->setFillColor(sf::Color::Yellow);
    assign(goal, sf::Vector2u(11, 2));

    addWall(2, 0);
    addWall(3, 0);
    addWall(4, 0);

    // Add walls to create a maze-like structure
    for (int i = 1; i < 14; ++i)
        addWall(1, i);

    for (int i = 1; i < 14; ++i)
        addWall(18, i);

    for (int i = 1; i < 19; ++i) {
        if (i == 3) continue;
        addWall(i, 1);
    }

    for (int i = 1; i < 19; ++i) {
        if (i == 3) {
            addWall(2, 14);
            addWall(3, 14);
            addWall(4, 14);
            continue;
        };
        addWall(i, 13);
    }

    for (int i = 8; i < 15; ++i)
        addWall(i, 10);

    for (int i = 6; i < 9; ++i)
        addWall(i, 7);

    for (int i = 3; i < 13; ++i)
        addWall(5, i);
    for (int i = 1; i < 8; ++i) {
        if (i == 4) continue;
        addWall(10, i);
    }
    for (int i = 11; i < 15; ++i)
        addWall(i, 3);

    for (int i = 8; i < 14; ++i)
        addWall(15, i);

    Player *player = new Player(18.f);
    assign(player, sf::Vector2u(3, 13));
    player->setFillColor(sf::Color::Green);

    Enemy *enemy1 = new Enemy(18.f, player);
    assign(enemy1, sf::Vector2u(13, 11));

    entities.push_back(player);
    entities.push_back(enemy1);
    entities.push_back(goal);
}

void Game::addWall(unsigned x, unsigned y) {
    Wall *wall = new Wall(24.f);
    assign(wall, sf::Vector2u(x, y));
    wall->setFillColor(sf::Color::Cyan);
    entities.push_back(wall);
}

Game::~Game() {
    for (Entity *entity : entities)
        delete entity;
}

void Game::updateEvents() {
    sf::Event event;
    while (window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
}

void Game::update() {
    if (delay.getElapsedTime().asMilliseconds() < 200) return;
    delay.restart();

    for (Entity *entity : entities)
        entity->update();
    grid.update(entities);
}

void Game::render() {
    window.clear();

    grid.render(window);

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        updateEvents();

        switch(grid.getStatus()) {
        case -1:
            std::cout << "Game Over!" << std::endl;
            return;
        case 1:
            std::cout << "Game Won!" << std::endl;
            return;
        }

        update();
        render();
    }
}
