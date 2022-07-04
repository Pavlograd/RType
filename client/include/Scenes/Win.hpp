/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Win
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AScene.hpp"

#include "Button.hpp"
#include "ParralaxSprite.hpp"

#include "enum_entities.hpp"

#ifndef WIN_HPP_
#define WIN_HPP_

class Win : public GE::AScene
{
public:
    Win(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime);
    ~Win();
    fptr eventListener(sf::Event event);
    void update();
    std::map<std::string, GE::IEntity *> getEntities();
    void addEntity(enum ENTITY_TYPE type, sf::Vector2f position);

    void switchButtonUp();
    void switchButtonDown();
    fptr actionActiveButton();

protected:
private:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    std::map<std::string, GE::IEntity *> _entities;
};

#endif /* !WIN_HPP_ */