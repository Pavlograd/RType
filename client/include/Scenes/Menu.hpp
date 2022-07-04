/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Menu
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AScene.hpp"

#include "Button.hpp"
#include "ParralaxSprite.hpp"

#include "enum_entities.hpp"

#ifndef MENU_HPP_
#define MENU_HPP_

class Menu : public GE::AScene
{
public:
    Menu(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime);
    ~Menu();
    fptr eventListener(sf::Event event);
    void update();
    std::map<std::string, GE::IEntity *> getEntities();
    void switchButtonUp();
    void switchButtonDown();
    fptr actionActiveButton();
    void addEntity(enum ENTITY_TYPE type, sf::Vector2f position);

protected:
private:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    std::map<std::string, GE::IEntity *> _entities;
};

#endif /* !MENU_HPP_ */