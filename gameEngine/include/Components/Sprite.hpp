/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Sprite
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"
#include "Position.hpp"

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

class Sprite : public GE::IComponent
{
public:
    Sprite(const GE::IComponent &x) : GE::IComponent(x) {}
    Sprite(std::string FileLocation, std::string ID);
    ~Sprite();
    void setPosition(Position *position);
    void setScale(std::vector<float> scale);
    void setRect(sf::IntRect rect);
    void draw(sf::RenderWindow *window);
    sf::Sprite getSprite();

protected:
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif /* !SPRITE_HPP_ */
