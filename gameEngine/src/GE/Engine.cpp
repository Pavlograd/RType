/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** Engine
*/

#include "Button.hpp"
#include "Engine.hpp"
#include "AScene.hpp"

namespace GE
{
    Engine::Engine()
    {
        _elapsedTime = _clock.getElapsedTime();
    }

    Engine::~Engine()
    {
    }

    sf::RenderWindow *Engine::getWindow()
    {
        return _window;
    }

    void Engine::setWindow(sf::RenderWindow *window)
    {
        _window = window;
    }


    sf::Clock Engine::getClock()
    {
        return _clock;
    }

    sf::Time *Engine::getElapsedTime()
    {
        return &_elapsedTime;
    }

    void Engine::setScene(enum SCENES scene)
    {
        _scene = scene;
    }

    enum SCENES Engine::getScene()
    {
        return _scene;
    }

    void Engine::addScene(IScene *scene)
    {
        _scenes[scene->getID()] = scene;
        std::map<std::string, IEntity *> entities = scene->getEntities();

        for (std::map<std::string, IEntity *>::const_iterator it = entities.begin(); it != entities.end(); ++it)
        {
            if (_entities.count(it->first))
            {
                //Replace pointer if already exist in map
                entities.find(it->first)->second = _entities.find(it->first)->second;
            }
            else
            {
                _entities[it->first] = it->second;
            }
        }
    }
    void Engine::addEntity(IEntity *entity)
    {
        _entities[entity->getID()] = entity;
    }
    void Engine::draw()
    {
        return;
    }
    std::map<enum SCENES, IScene *> Engine::getScenes()
    {
        return _scenes;
    }

    void Engine::start()
    {
        /*sf::Event event;

        _window->setFramerateLimit(60);
        

        while (_window->isOpen())
        {
            _window->clear();
            _elapsedTime = _clock.restart();
            if (_window->pollEvent(event))
            {
                ((AScene *)_scenes.find(_scene)->second)->eventListener(event)(this);
                switch (event.type)
                {
                case sf::Event::Closed:
                    _window->close();
                    break;
                default:
                    break;
                }
            }
            _scenes.find(_scene)->second->update();
            _window->display();
        }*/
        return;
    }
} // namespace GE