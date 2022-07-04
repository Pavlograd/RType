/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Submarine
*/

#include <iostream>
#include <string>
#include "Submarine.hpp"

void Submarine::doNothing()
{
    return;
}

Submarine::Submarine(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position) : Enemy(ID, type, window, elapsedTime, position)
{
    _components["sprite"] = new Sprite("../assets/sprites/enemy3.gif", "sprite");
    _components["scale"] = new Scale(3, 3, "scale");
    _components["speed"] = new Speed(-4, 3, "speed");
    _components["rect"] = new Rect(0, 0, 65, 50, 2, "rect");
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
    ((Sprite *)_components["sprite"])->setRect(((Rect *)_components["rect"])->getRect());
}

void Submarine::positionUpdate()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();

    float time = (*_elapsedTime).asMicroseconds() / 16000.0;
    _elapsedTimeRect += time;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);

    _nbrSpin++;

    if (_nbrSpin == 50) {
        _nbrSpin = 0;
        ((Speed *)_components["speed"])->setSpeed(((Speed *)_components["speed"])->_speedX, ((Speed *)_components["speed"])->_speedY * -1.0);
    }
    position.y = position.y + (((Speed *)_components["speed"])->_speedY * time);

    spriteUpdate(position);

    return;
}

void Submarine::update()
{
    if (_state == DEAD)
        return;
    rectUpdate();
    //movementUpdate();
    Submarine::positionUpdate();

    return;
}