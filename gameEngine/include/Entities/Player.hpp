/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Player
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IEntity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Scale.hpp"
#include "Speed.hpp"
#include "Rect.hpp"
#include "enum_level.hpp"

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player : public GE::IEntity
{
public:
    Player(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position, GE::IComponent *sprite, GE::IComponent *scale, GE::IComponent *speed, GE::IComponent *rect);
    ~Player();
    void update();
    void spriteUpdate(sf::Vector2f position);
    void positionUpdate();
    sf::Vector2f getPosition();
    sf::IntRect getRect();
    void setMovement(enum MOVEMENT movement);
    void movementUpdate();
    void setState(enum STATE state);
    enum STATE getState();
    bool shoot();

protected:
private:
    sf::RenderWindow *_window;
    sf::Time *_elapsedTime;
    std::map<std::string, GE::IComponent *> _components;
    enum MOVEMENT _movement;
    enum STATE _state;
    float _timeLastShoort = 0;
};

#endif /* !PLAYER_HPP_ */
