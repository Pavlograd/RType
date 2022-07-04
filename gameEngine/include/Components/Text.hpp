/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Text
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

#ifndef TEXT_HPP_
#define TEXT_HPP_

class Text : public GE::IComponent
{
public:
    Text(const GE::IComponent &x) : GE::IComponent(x) {}
    Text(std::string text, std::string fontLocation, int size, sf::Color color, std::string ID);
    void setPosition(sf::Vector2f vector);
    void setColor(sf::Color color);
    sf::Text getText();
    ~Text();

protected:
private:
    sf::Font _font;
    sf::Text _text;
};

#endif /* !TEXT_HPP_ */
