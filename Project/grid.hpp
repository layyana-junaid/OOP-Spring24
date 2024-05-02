#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "wall.hpp"
#include "goal.hpp"

float distance(sf::Vector2f, sf::Vector2f);

class Grid {
private:
    std::vector<std::vector<Entity *>> grid;
    sf::Vector2f step;
    int status;

    sf::Vector2f convertToPosition(sf::Vector2u);

    void playerGridUpdate(Player *);
    void enemyGridUpdate(Enemy *);

    bool boundaryCheck(sf::Vector2i);
public:
    Grid(sf::Vector2u, sf::Vector2u);

    sf::Vector2f insert(Entity *, sf::Vector2u);
    void clear(sf::Vector2u);

    int getStatus() const;

    void update(std::vector<Entity *>&);
    void render(sf::RenderWindow&);
};

Grid::Grid(sf::Vector2u gridSize, sf::Vector2u windowSize) : status(false) {
    grid.resize(gridSize.x);

    // initializing each cell with nullptr
    for (std::vector<Entity *>& row : grid) {
        row.resize(gridSize.y);
        for (Entity *cell : row)
            cell = nullptr;
    }

    // finding step lengths
    step = sf::Vector2f(windowSize.x / gridSize.x, windowSize.y / gridSize.y);
}

sf::Vector2f Grid::convertToPosition(sf::Vector2u position) {
    // center by adding 0.5 and multiply to get the actual distance
    return sf::Vector2f((position.x+0.5f)*step.x, (position.y+0.5f)*step.y);
}

sf::Vector2f Grid::insert(Entity *entity, sf::Vector2u position) {
    grid[position.x][position.y] = entity;
    entity->setGridPosition(position);

    // return the grid position as a position in the window for ease in translating grid movement into
    // on screen movement
    return convertToPosition(position);
}

void Grid::clear(sf::Vector2u position) {
    // assign cell as nullptr
    grid[position.x][position.y] = nullptr;
}

bool Grid::boundaryCheck(sf::Vector2i pos) {
    return !(pos.x >= 0 && pos.x < grid.size()) || !(pos.y >= 0 && pos.y < grid.data()->size());
}

void Grid::playerGridUpdate(Player *player) {
    // storing player's current position
    sf::Vector2i current_pos(player->getGridPosition());
    // finding new position of the player in the direction of the keyboard input
    sf::Vector2i new_pos = current_pos + player->getDirection();

    // check if player is within bounds after adding new direction
    if (boundaryCheck(new_pos)) return;

    if (grid[new_pos.x][new_pos.y] != nullptr) {
        if (grid[new_pos.x][new_pos.y]->isWall()) return;

        if (grid[new_pos.x][new_pos.y]->isGoal()) {
            status = 1;
            return;
        }

        if (grid[new_pos.x][new_pos.y]->isEnemy()) {
            status = -1;
            return;
        }
    }

    // clear previous cell
    clear(player->getGridPosition());

    // set player on new position
    player->setPosition(insert(player, sf::Vector2u(new_pos)));
    
    // reset entity direction
    player->setDirection(sf::Vector2i());
}

void Grid::enemyGridUpdate(Enemy *enemy) {
    // list of possible directions an enemy can look
    std::vector<sf::Vector2i> positions{
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, -1)
    };

    // storing current position of enemy as a vector2i
    sf::Vector2i current_pos(enemy->getGridPosition());

    // to find nearest next position of the enemy from the player
    sf::Vector2i nearest;
    float nearest_distance = ~(1<<31); // storing max value
    for (sf::Vector2i position : positions) {
        sf::Vector2i new_pos = current_pos + position;

        // check if new position is valid
        if (boundaryCheck(new_pos) || grid[new_pos.x][new_pos.y] != nullptr) continue;

        // finding distance between enemy's new positon and the player's position
        float current_distance = distance(enemy->getPlayerPosition(), convertToPosition(sf::Vector2u(new_pos)));
        // if it's less than the previous nearest distance
        if (current_distance < nearest_distance) {
            // replace it with current distance
            nearest_distance = current_distance;
            // keep track of position on the grid by replacing the nearest too
            nearest = position;
        }
    }

    // clear previous cell
    clear(enemy->getGridPosition());

    // set enemy to new position
    enemy->setPosition(insert(enemy, sf::Vector2u(current_pos + nearest)));
}

int Grid::getStatus() const {
    return status;
}

void Grid::update(std::vector<Entity *>& entities) {
    // for every entity, check if either player or enemy
    // this is done to use the player and enemy functions
    // down casting is necessary
    for (Entity *entity : entities) {
        if (dynamic_cast<Player *>(entity))
            playerGridUpdate(dynamic_cast<Player *>(entity));
        else if (dynamic_cast<Enemy *>(entity))
            enemyGridUpdate(dynamic_cast<Enemy *>(entity));
    }
}

void Grid::render(sf::RenderWindow& window) {
    for (unsigned i = 0; i < grid.size(); ++i) {
        for (unsigned j = 0; j < grid.data()->size(); ++j) {
            // create a dot
            sf::CircleShape dot(2);
            dot.setFillColor(sf::Color(30, 30, 30));

            // center dot
            sf::Vector2f dotOffset = sf::Vector2f(dot.getRadius(), dot.getRadius());

            // position dot in the grid
            dot.setPosition(sf::Vector2f((i+0.5f)*step.x, (j+0.5f)*step.y) - dotOffset);
            window.draw(dot);

            // render every entity cell in the grid if it isn't nullptr
            if (!grid[i][j]) continue;
            grid[i][j]->render(window);
        }
    }
}

float distance(sf::Vector2f a, sf::Vector2f b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}