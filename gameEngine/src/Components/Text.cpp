/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(std::string text, std::string fontLocation, int size, sf::Color color, std::string ID)
{
    _text.setString(text);
    _text.setCharacterSize(size);
    _text.setFillColor(color);

    if (!_font.loadFromFile(fontLocation))
    {
        exit(84);
    }
    _text.setFont(_font);

    setID(ID);
}

Text::~Text()
{
}

sf::Text Text::getText()
{
    return _text;
}

void Text::setPosition(sf::Vector2f vector)
{
    _text.setPosition(vector);
}

void Text::setColor(sf::Color color)
{
    _text.setFillColor(color);
}

