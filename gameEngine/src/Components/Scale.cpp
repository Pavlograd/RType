/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Scale
*/

#include "Scale.hpp"

Scale::Scale(float scaleX, float scaleY, std::string ID)
{
    _scaleX = scaleX;
    _scaleY = scaleY;
    setID(ID);
}

Scale::~Scale()
{
}

std::vector<float> Scale::getScale()
{
    return std::vector<float>{_scaleX, _scaleY};
}