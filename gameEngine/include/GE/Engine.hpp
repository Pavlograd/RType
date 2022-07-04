/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** Engine
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "enum_scenes.hpp"
#include "IEntity.hpp"
#include "IScene.hpp"

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

namespace GE
{
    class Engine
    {
    public:
        Engine();
        ~Engine();
        void start();
        void draw();
        void addScene(IScene *scene);
        void addEntity(IEntity *entity);
        sf::RenderWindow *getWindow();
        sf::Clock getClock();
        sf::Time *getElapsedTime();
        void setScene(enum SCENES scene);
        void setWindow(sf::RenderWindow *window);
        enum SCENES getScene();
        std::map<enum SCENES, IScene *> getScenes();

    protected:
    private:
        sf::RenderWindow *_window;
        sf::Clock _clock;
        sf::Time _elapsedTime;
        std::map<std::string, IEntity *> _entities;
        std::map<enum SCENES, IScene *> _scenes;
        enum SCENES _scene;
    };
} // namespace GE

#endif /* !ENGINE_HPP_ */