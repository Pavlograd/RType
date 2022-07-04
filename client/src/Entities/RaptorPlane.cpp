/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** RaptorPlane
*/

#include <iostream>
#include <string>
#include "RaptorPlane.hpp"

void RaptorPlane::doNothing()
{
    return;
}

RaptorPlane::RaptorPlane(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position) : Enemy(ID, type, window, elapsedTime, position)
{
    _components["sprite"] = new Sprite("../assets/sprites/enemy2.gif", "sprite");
    _components["scale"] = new Scale(3, 3, "scale");
    _components["speed"] = new Speed(-4, 0, "speed");
    _components["rect"] = new Rect(0, 4, 33, 28, 7, "rect");
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

void RaptorPlane::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();
    float time = (*_elapsedTime).asMicroseconds() / 16000.0;

    _elapsedTimeRect += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);

    spriteUpdate(position);

    return;
}

void RaptorPlane::update()
{
    if (_state == DEAD)
        return;
    rectUpdate();
    //movementUpdate();
    RaptorPlane::positionUpdate();

    return;
}