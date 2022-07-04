/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapseTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed, GE::IComponent *rect)
{
    setID(ID);
    setType(type);
    _state = ALIVE;
    _window = window;
    _elapsedTime = elapseTime;
    _components[position->getID()] = position;
    _components[sprite->getID()] = sprite;
    _components[scale->getID()] = scale;
    _components[speed->getID()] = speed;
    _components[rect->getID()] = rect;
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

Player::~Player()
{
}

void Player::setMovement(enum MOVEMENT movement)
{
    _movement = movement;
}

void Player::spriteUpdate(sf::Vector2f position)
{
    ((Position *)_components["position"])->setPosition(position);
    ((Sprite *)_components["sprite"])->setPosition(((Position *)_components["position"]));
    ((Sprite *)_components["sprite"])->draw(_window);
}

void Player::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();

    float time = (*_elapsedTime).asMicroseconds() / 16000.0;

    _timeLastShoort += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);
    if (position.x < 0)
        position.x = 0;
    if (position.y < 0)
        position.y = 0;
    if (position.x > 1900)
        position.x = 1900;
    if (position.y > 1000)
        position.y = 1000;

    spriteUpdate(position);
}

void Player::movementUpdate()
{
    setMovement(NONE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        setMovement(TOP);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        setMovement(BOTTOM);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        setMovement(LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        setMovement(RIGHT);
    }

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

void Player::update()
{
    if (_state == DEAD)
        return;
    movementUpdate();
    positionUpdate();
    return;
}

void Player::setState(enum STATE state)
{
    _state = state;
}

enum STATE Player::getState()
{
    return _state;
}

sf::Vector2f Player::getPosition()
{
    return ((Position *)_components["position"])->getPosition();
}

sf::IntRect Player::getRect()
{
    return ((Rect *)_components["rect"])->getRect();
}

bool Player::shoot()
{
    if (_timeLastShoort >= 10.0) {
        _timeLastShoort = 0;
        return true;
    }
    return false;
}