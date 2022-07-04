/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Enemy
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IEntity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Scale.hpp"
#include "Speed.hpp"
#include "Rect.hpp"
#include "enum_level.hpp"

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

class Enemy : public GE::IEntity
{
public:
    Enemy(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position);
    Enemy(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed, GE::IComponent *rect);
    ~Enemy();
    void update();
    void spriteUpdate(sf::Vector2f position);
    void positionUpdate();
    void setMovement(enum MOVEMENT movement);
    sf::Vector2f getPosition();
    sf::IntRect getRect();
    void movementUpdate();
    void rectUpdate();
    void setState(enum STATE state);
    enum STATE getState();

protected:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    enum MOVEMENT _movement;
    float _elapsedTimeRect;
    std::map<std::string, GE::IComponent *> _components;
    enum STATE _state;

private:
};

#endif /* !ENEMY_HPP_ */
