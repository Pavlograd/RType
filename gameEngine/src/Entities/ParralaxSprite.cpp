/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** ParralaxSprite
*/

#include "ParralaxSprite.hpp"

ParralaxSprite::ParralaxSprite(enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapseTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed)
{
    setType(type);
    _window = window;
    _elapsedTime = elapseTime;
    _components[position->getID()] = position;
    _components[sprite->getID()] = sprite;
    _components[scale->getID()] = scale;
    _components[speed->getID()] = speed;
    ((Sprite *)_components["sprite"])->setScale(((Scale *)_components["scale"])->getScale());
}

ParralaxSprite::~ParralaxSprite()
{
}

void ParralaxSprite::update()
{
    sf::Vector2f position = ((Position *)_components["position"])->getPosition();

    float time = (*_elapsedTime).asMicroseconds() / 16000.0;

    position.x = position.x + (((Speed *)_components["speed"])->_speedX * time);
    if (position.x < -1920) {
        position.x = 1920;
    }
    ((Position *)_components["position"])->setPosition(position);
    ((Sprite *)_components["sprite"])->setPosition(((Position *)_components["position"]));
    ((Sprite *)_components["sprite"])->draw(_window);
    return;
}

