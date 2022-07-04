/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Level
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AScene.hpp"

#include "Button.hpp"
#include "ParralaxSprite.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Submarine.hpp"
#include "Plane.hpp"
#include "RaptorPlane.hpp"
#include "Laser.hpp"

#include "enum_entities.hpp"
#include "enum_level.hpp"

#include "UDPclient.hpp"

#ifndef LEVEL_HPP_
#define LEVEL_HPP_

class Level : public GE::AScene
{
public:
    Level(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime);
    ~Level();
    fptr eventListener(sf::Event event);
    void update();
    std::map<std::string, GE::IEntity *> getEntities();
    bool noMorePlayerLeft();
    void addEntity(enum ENTITY_TYPE type, sf::Vector2f position);
    void checkMonsterFromServer(std::array<char, 4> arr);
    void updatePlayer(std::map<std::string, GE::IEntity *>::const_iterator it);
    void updateEnemies(std::map<std::string, GE::IEntity *>::const_iterator it);

protected:
private:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    std::map<std::string, GE::IEntity *> _entities;
    int _lives = 3;
    int _deadEnemies = 0;
    boost::asio::io_service io_service;
    UDPclient *client;
};

#endif /* !LEVEL_HPP_ */