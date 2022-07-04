/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position)
{
    setID(ID);
    setType(type);
    _state = ALIVE;
    _window = window;
    _elapsedTime = elapsedTime;
    _elapsedTimeRect = (*_elapsedTime).asMicroseconds() / 16000.0;
    _components[position->getID()] = position;
}

Enemy::Enemy(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed, GE::IComponent *rect)
{
    setID(ID);
    setType(type);
    _state = ALIVE;
    _window = window;
    _elapsedTime = elapsedTime;
    _components[position->getID()] = position;
    _components[sprite->getID()] = sprite;
    _components[scale->getID()] = scale;
    _components[speed->getID()] = speed;
    _components[rect->getID()] = rect;
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
    _elapsedTimeRect = (*_elapsedTime).asMicroseconds() / 16000.0;
}

Enemy::~Enemy()
{
}

void Enemy::setMovement(enum MOVEMENT movement)
{
    _movement = movement;
}

void Enemy::spriteUpdate(sf::Vector2f position)
{
    ((Position *)_components["position"])->setPosition(position);
    ((Sprite *)_components["sprite"])->setPosition(((Position *)_components["position"]));
    ((Sprite *)_components["sprite"])->draw(_window);
}

void Enemy::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();

    float time = (*_elapsedTime).asMicroseconds() / 16000.0;
    _elapsedTimeRect += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);
    /*if (position.x < 0)
        position.x = 0;
    if (position.y < 0)
        position.y = 0;
    if (position.x > 1900)
        position.x = 1900;
    if (position.y > 1000)
        position.y = 1000;*/

    spriteUpdate(position);
}

void Enemy::movementUpdate()
{
    setMovement(LEFT);

    switch (_movement)
    {
    case TOP:
        ((Speed *)_components["speed"])->setSpeed(0, -4);
        break;
    case BOTTOM:
        ((Speed *)_components["speed"])->setSpeed(0, 4);
        break;
    case RIGHT:
        ((Speed *)_components["speed"])->setSpeed(4, 0);
        break;
    case LEFT:
        ((Speed *)_components["speed"])->setSpeed(-4, 0);
        break;
    default:
        ((Speed *)_components["speed"])->setSpeed(0, 0);
        break;
    }
}

void Enemy::rectUpdate()
{
    if (_elapsedTimeRect < 10.0)
        return;
    _elapsedTimeRect = 0.0;
    sf::IntRect rect = ((Rect *)_components["rect"])->getRect();

    if (rect.left >= rect.width * ((Rect *)_components["rect"])->getNbrRect()) {
        rect.left = 0;
    } else {
        rect.left += rect.width;
    }
    ((Rect *)_components["rect"])->setRect(rect);
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

void Enemy::update()
{
    if (_state == DEAD)
        return;
    rectUpdate();
    movementUpdate();
    positionUpdate();
    return;
}

void Enemy::setState(enum STATE state)
{
    _state = state;
}

enum STATE Enemy::getState()
{
    return _state;
}

sf::Vector2f Enemy::getPosition()
{
    return ((Position *)_components["position"])->getPosition();
}

sf::IntRect Enemy::getRect()
{
    return ((Rect *)_components["rect"])->getRect();
}