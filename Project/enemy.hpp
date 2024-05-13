#pragma once
#include "entity.hpp"
#include <cmath>

class Enemy : public Entity {
private:
    Entity *player;
public:
    Enemy(const float, Entity *);

    sf::Vector2f getPlayerPosition();

    bool isEnemy() const;

    void render(sf::RenderWindow&);
    void update();
};

Enemy::Enemy(const float radius, Entity *player) : Entity(radius), player(player) {}

sf::Vector2f Enemy::getPlayerPosition() {
    return player->getPosition();
}

void Enemy::render(sf::RenderWindow& window) {
    window.draw(this->entity);
}

bool Enemy::isEnemy() const {
    return true;
}

void Enemy::update() {
    
}
