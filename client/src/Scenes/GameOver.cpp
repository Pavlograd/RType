/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** GameOver
*/

#include "GameOver.hpp"

#include "eventsReturnFunctions.hpp"

GameOver::GameOver(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime)
{
    setID(ID);
    _window = window;
    _elapsedTime = elapsedTime;
    _entities[std::string("000_parralax1")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 0, "position"), new Sprite("../assets/game_over.jpg", "sprite"), new Scale(2.0, 2.2, "scale"), new Speed(0, 0, "speed"));
    _entities[std::string("001_button1")] = new Button("exit_button", BUTTON, _window, (enum ACTIVE)ACTIVE, new Position(870, 620, "position"), new Text("Exit", "../assets/fonts/space.ttf", 36, sf::Color::Red, "activeText"), new Text("Exit", "../assets/fonts/space.ttf", 36, sf::Color::White, "notActiveText"));
}

GameOver::~GameOver()
{
}

void GameOver::update()
{
    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        it->second->update();
    }
    return;
}

std::map<std::string, GE::IEntity *> GameOver::getEntities()
{
    return _entities;
}

void GameOver::switchButtonDown()
{
    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        if (it->second->getType() == BUTTON && ((Button *)it->second)->getIfActive() == ACTIVE)
        {
            ((Button *)it->second)->setIfActive(NOT_ACTIVE);
            it++;
            if (it != _entities.end() && it->second->getType() == BUTTON)
            {
                ((Button *)it->second)->setIfActive(ACTIVE);
            }
            else
            {
                for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
                {
                    if (it->second->getType() == BUTTON && ((Button *)it->second)->getIfActive() == NOT_ACTIVE)
                    {
                        ((Button *)it->second)->setIfActive(ACTIVE);
                        break;
                    }
                }
            }
            break;
        }
    }
}

void GameOver::switchButtonUp()
{
    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        if (it->second->getType() == BUTTON && ((Button *)it->second)->getIfActive() == ACTIVE)
        {
            ((Button *)it->second)->setIfActive(NOT_ACTIVE);
            it--;
            if (it != _entities.begin() && it->second->getType() == BUTTON)
            {
                ((Button *)it->second)->setIfActive(ACTIVE);
            }
            else
            {
                for (std::map<std::string, GE::IEntity *>::reverse_iterator it = _entities.rbegin(); it != _entities.rend(); ++it)
                {
                    if (it->second->getType() == BUTTON && ((Button *)it->second)->getIfActive() == NOT_ACTIVE)
                    {
                        ((Button *)it->second)->setIfActive(ACTIVE);
                        break;
                    }
                }
            }
            break;
        }
    }
}

fptr GameOver::actionActiveButton()
{
    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        if (it->second->getType() == BUTTON && ((Button *)it->second)->getIfActive() == ACTIVE)
        {
            if (it->second->getID().compare("start_button") == 0)
                return startLevel;
            else if (it->second->getID().compare("options_button") == 0)
                return nothingToDo;
            else if (it->second->getID().compare("exit_button") == 0)
                return exitGame;
            break;
        }
    }
    return nothingToDo;
}

fptr GameOver::eventListener(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            switchButtonUp();
            break;
        case sf::Keyboard::Down:
            switchButtonDown();
            break;
        case sf::Keyboard::Enter:
            return actionActiveButton();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return nothingToDo;
}

void GameOver::addEntity(enum ENTITY_TYPE type, sf::Vector2f position)
{
    (void) type;
    (void) position;

    return;
}