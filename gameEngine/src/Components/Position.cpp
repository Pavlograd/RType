/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Position
*/

#include "Position.hpp"

Position::Position(float x, float y, std::string ID)
{
    _x = x;
    _y = y;
    setID(ID);
}

Position::~Position()
{
}

sf::Vector2f Position::getPosition()
{
    return sf::Vector2f(_x, _y);
}

void Position::setPosition(sf::Vector2f vector)
{
    _x = vector.x;
    _y = vector.y;
}