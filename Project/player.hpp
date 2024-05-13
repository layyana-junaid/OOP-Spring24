#pragma once
#include "entity.hpp"
#include <iostream>

class Player : public Entity {
private:
    sf::Vector2i direction;
public:
    Player(const float);

    void setDirection(const sf::Vector2i);
    sf::Vector2i getDirection() const;

    void render(sf::RenderWindow&);
    void update();
};

Player::Player(const float radius) : Entity(radius) {}

void Player::setDirection(const sf::Vector2i direction) {
    this->direction = direction;
}

sf::Vector2i Player::getDirection() const {
    return direction;
}

void Player::render(sf::RenderWindow& window) {
    window.draw(this->entity);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        direction = sf::Vector2i(0, -1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        direction = sf::Vector2i(-1, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        direction = sf::Vector2i(0, 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        direction = sf::Vector2i(1, 0);
}