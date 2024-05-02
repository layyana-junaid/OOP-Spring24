#pragma once
#include "entity.hpp"

class Goal : public Entity {
private:
public:
    Goal(const float);

    bool isGoal() const;

    void update();
    void render(sf::RenderWindow&);
};

Goal::Goal(const float size) : Entity(size) {
    entity.setPointCount(4);
}

bool Goal::isGoal() const {
    return true;
}

void Goal::update() { /* No update implementation for Goal */ }

void Goal::render(sf::RenderWindow& window) {
    window.draw(entity);
}
