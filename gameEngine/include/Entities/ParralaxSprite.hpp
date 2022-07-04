/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** ParralaxSprite
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IEntity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Scale.hpp"
#include "Speed.hpp"

#include "enum_entities.hpp"

#ifndef PARRALAXSPRITE_HPP_
#define PARRALAXSPRITE_HPP_

class ParralaxSprite : public GE::IEntity
{
public:
    ParralaxSprite(enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed);
    ~ParralaxSprite();
    void update();

protected:
private:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    std::map<std::string, GE::IComponent *> _components;
};

#endif /* !PARRALAXSPRITE_HPP_ */
