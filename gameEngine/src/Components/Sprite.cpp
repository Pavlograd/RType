/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string FileLocation, std::string ID)
{
    setID(ID);
    if (!_texture.loadFromFile(FileLocation))
    {
        exit(84);
    }
    _sprite.setTexture(_texture);
}

void Sprite::setPosition(Position *position)
{
    _sprite.setPosition(position->getPosition());
}

void Sprite::setScale(std::vector<float> scale)
{
    if (scale[0] && scale[1])
        _sprite.setScale(scale[0], scale[1]);
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(_sprite);
}

Sprite::~Sprite()
{
}

sf::Sprite Sprite::getSprite()
{
    return _sprite;
}

void Sprite::setRect(sf::IntRect rect)
{
    _sprite.setTextureRect(rect);
}

