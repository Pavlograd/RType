/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Client
*/

#include "Client.hpp"
#include "AScene.hpp"
#include "Menu.hpp"
#include "Level.hpp"
#include "GameOver.hpp"
#include "Win.hpp"
#include "UDPclient.hpp"

Client::Client()
{
    _elapsedTime = _clock.getElapsedTime();
    _engine = new GE::Engine();
    _engine->setWindow(_window);
    _engine->addScene(new Menu(MENU, _window, getElapsedTime()));
    _engine->addScene(new Level(LEVEL1, _window, getElapsedTime()));
    _engine->addScene(new GameOver(GAME_OVER, _window, getElapsedTime()));
    _engine->addScene(new Win(WIN, _window, getElapsedTime()));
    _engine->setScene(MENU);
}

Client::~Client()
{
}

sf::RenderWindow *Client::getWindow()
{
    return _window;
}

sf::Clock Client::getClock()
{
    return _clock;
}

sf::Time *Client::getElapsedTime()
{
    return &_elapsedTime;
}

void Client::start()
{
    sf::Event event;
    _window->setFramerateLimit(60);

    while (_window->isOpen())
    {
        _window->clear();
        _elapsedTime = _clock.restart();
        if (_window->pollEvent(event))
        {
            ((GE::AScene *)_engine->getScenes().find(_engine->getScene())->second)->eventListener(event)(_engine);
            switch (event.type)
            {
            case sf::Event::Closed:
                _window->close();
                break;
            default:
                break;
            }
        }
        _engine->getScenes().find(_engine->getScene())->second->update();
        _window->display();
    }
    return;
}