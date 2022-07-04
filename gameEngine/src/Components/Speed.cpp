/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Speed
*/

#include "Speed.hpp"

Speed::Speed(float speedX, float speedY, std::string ID)
{
    _speedX = speedX;
    _speedY = speedY;
    setID(ID);
}

Speed::~Speed()
{
}

void Speed::setSpeed(float speedX, float speedY)
{
    _speedX = speedX;
    _speedY = speedY;
}

std::vector<float> Speed::getSpeed()
{
    return std::vector<float>(_speedX, _speedY);
}
