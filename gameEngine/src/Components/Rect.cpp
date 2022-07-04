/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Rect
*/

#include "Rect.hpp"

Rect::Rect(int rectLeft, int rectTop, int rectWidth, int rectHeight, int nbrRect, std::string ID)
{
    setID(ID);
    _rect = sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight);
    _nbrRect = nbrRect;
}

Rect::~Rect()
{
}

sf::IntRect Rect::getRect()
{
    return _rect;
}

void Rect::setRect(sf::IntRect rect)
{
    _rect = rect;
}

int Rect::getNbrRect()
{
    return _nbrRect;
}
