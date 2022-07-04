/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Client
*/

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.hpp"

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

class Client
{
public:
    Client();
    ~Client();
    sf::RenderWindow *getWindow();
    sf::Clock getClock();
    sf::Time *getElapsedTime();
    void start();

protected:
private:
    sf::RenderWindow *_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "rtype_client");
    sf::Clock _clock;
    sf::Time _elapsedTime;
    GE::Engine *_engine;
};

#endif /* !CLIENT_HPP_ */