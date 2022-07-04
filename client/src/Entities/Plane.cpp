/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Plane
*/

#include <iostream>
#include <string>
#include "Plane.hpp"

void Plane::doNothing()
{
    return;
}

Plane::Plane(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position) : Enemy(ID, type, window, elapsedTime, position)
{
    _components["sprite"] = new Sprite("../assets/sprites/enemy1.gif", "sprite");
    _components["scale"] = new Scale(3, 3, "scale");
    _components["speed"] = new Speed(-4, 6, "speed");
    _components["rect"] = new Rect(0, 4, 33, 28, 7, "rect");
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

void Plane::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();

    float time = (*_elapsedTime).asMicroseconds() / 16000.0;
    _elapsedTimeRect += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);

    if (position.y > 1000 || position.y < 0)
        ((Speed *)_components["speed"])->setSpeed(((Speed *)_components["speed"])->_speedX, ((Speed *)_components["speed"])->_speedY * -1.0);
    spriteUpdate(position);

    return;
}

void Plane::update()
{
    if (_state == DEAD)
        return;

    rectUpdate();
    //movementUpdate();
    Plane::positionUpdate();

    return;
}