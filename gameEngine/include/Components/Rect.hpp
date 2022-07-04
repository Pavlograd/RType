/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Rect
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

#ifndef RECT_HPP_
#define RECT_HPP_

class Rect : public GE::IComponent
{
public:
    Rect(const GE::IComponent &x) : GE::IComponent(x) {}
    Rect(int rectLeft, int rectTop, int rectWidth, int rectHeight, int nbrRect, std::string ID);
    sf::IntRect getRect();
    void setRect(sf::IntRect rect);
    int getNbrRect();
    ~Rect();

protected:
private:
    sf::IntRect _rect;
    int _nbrRect;
};

#endif /* !RECT_HPP_ */
