/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** GameOver
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AScene.hpp"

#include "Button.hpp"
#include "ParralaxSprite.hpp"

#include "enum_entities.hpp"

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

class GameOver : public GE::AScene
{
public:
    GameOver(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime);
    ~GameOver();
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

#endif /* !GAMEOVER_HPP_ */