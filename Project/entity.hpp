#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Entity {
protected:
    sf::CircleShape entity;
    sf::Vector2u gridPosition;
public:
    Entity(const float);

    void setPosition(const sf::Vector2f);
    void setFillColor(const sf::Color);
    void setGridPosition(const sf::Vector2u);

    sf::Vector2u getGridPosition() const;
    sf::Vector2f getPosition() const;
    float getRadius() const;

    virtual bool isEnemy() const;
    virtual bool isGoal() const;
    virtual bool isWall() const;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow&) = 0;
};

Entity::Entity(const float radius) {
    entity.setRadius(radius);
}

sf::Vector2u Entity::getGridPosition() const {
    return gridPosition;
}

sf::Vector2f Entity::getPosition() const {
    return entity.getPosition();
}
float Entity::getRadius() const {
    return entity.getRadius();
}

void Entity::setGridPosition(const sf::Vector2u position) {
    gridPosition = position;
}

void Entity::setPosition(const sf::Vector2f position) {
    entity.setPosition(position - sf::Vector2f(entity.getRadius(), entity.getRadius()));
}

void Entity::setFillColor(const sf::Color color) {
    entity.setFillColor(color); 
}

bool Entity::isEnemy() const {
    return false;
}

bool Entity::isGoal() const {
    return false;
}

bool Entity::isWall() const {
    return false;
}
