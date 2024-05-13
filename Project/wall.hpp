#pragma once
#include "entity.hpp"

class Wall : public Entity {
private:
public:
    Wall(const float);

    bool isWall() const;

    void update();
    void render(sf::RenderWindow&);
};

Wall::Wall(const float size) : Entity(size) {
    entity.setPointCount(4);
}

void Wall::update() { /* No update implementation for Wall */ }

bool Wall::isWall() const {
    return true;
}

void Wall::render(sf::RenderWindow& window) {
    sf::CircleShape entity_copy(entity);
    entity_copy.setPosition(entity_copy.getPosition() + sf::Vector2f(entity.getRadius(), -0.5f*entity.getRadius()));
    entity_copy.setRotation(45.f);
    window.draw(entity_copy);
}
