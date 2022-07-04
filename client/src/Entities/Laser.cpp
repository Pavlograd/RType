/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Laser
*/

#include <iostream>
#include <string>
#include "Laser.hpp"

void Laser::doNothing()
{
    return;
}

Laser::Laser(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position) : Enemy(ID, type, window, elapsedTime, position)
{
    _components["sprite"] = new Sprite("../assets/sprites/laser.gif", "sprite");
    _components["scale"] = new Scale(2, 2, "scale");
    _components["speed"] = new Speed(5, 0, "speed");
    _components["rect"] = new Rect(0, 40, 50, 7, 7, "rect");
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

void Laser::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();
    float time = (*_elapsedTime).asMicroseconds() / 16000.0;

    _elapsedTimeRect += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);

    if (position.x > 2000)
        _state = DEAD;
    spriteUpdate(position);

    return;
}

void Laser::update()
{
    if (_state == DEAD)
        return;

    rectUpdate();
    //movementUpdate();
    Laser::positionUpdate();

    return;
}