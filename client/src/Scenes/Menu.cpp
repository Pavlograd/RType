/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Menu
*/

#include "Menu.hpp"

#include "eventsReturnFunctions.hpp"

Menu::Menu(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime)
{
    setID(ID);
    _window = window;
    _elapsedTime = elapsedTime;
    _entities[std::string("000_parralax1")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-bg.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.2, 0, "speed"));
    _entities[std::string("000_parralax2")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-bg.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.2, 0, "speed"));
    _entities[std::string("000_parralax3")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-far-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.6, 0, "speed"));
    _entities[std::string("000_parralax4")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-far-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.6, 0, "speed"));
    _entities[std::string("000_parralax5")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 20, "position"), new Sprite("../assets/parralax/parallax-industrial-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1, 0, "speed"));
    _entities[std::string("000_parralax6")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 20, "position"), new Sprite("../assets/parralax/parallax-industrial-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1, 0, "speed"));
    _entities[std::string("000_parralax7")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 350, "position"), new Sprite("../assets/parralax/parallax-industrial-foreground.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1.4, 0, "speed"));
    _entities[std::string("000_parralax8")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 350, "position"), new Sprite("../assets/parralax/parallax-industrial-foreground.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1.4, 0, "speed"));
    _entities[std::string("001_button1")] = new Button("start_button", BUTTON, _window, (enum ACTIVE)ACTIVE, new Position(870, 300, "position"), new Text("Start", "../assets/fonts/space.ttf", 36, sf::Color::Red, "activeText"), new Text("Start", "../assets/fonts/space.ttf", 36, sf::Color::White, "notActiveText"));
    _entities[std::string("001_button2")] = new Button("options_button", BUTTON, _window, (enum ACTIVE)NOT_ACTIVE, new Position(870, 460, "position"), new Text("Options", "../assets/fonts/space.ttf", 36, sf::Color::Red, "activeText"), new Text("Options", "../assets/fonts/space.ttf", 36, sf::Color::White, "notActiveText"));
    _entities[std::string("001_button3")] = new Button("exit_button", BUTTON, _window, (enum ACTIVE)NOT_ACTIVE, new Position(870, 620, "position"), new Text("Exit", "../assets/fonts/space.ttf", 36, sf::Color::Red, "activeText"), new Text("Exit", "../assets/fonts/space.ttf", 36, sf::Color::White, "notActiveText"));
}

Menu::~Menu()
{
}

void Menu::update()
{
    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        it->second->update();
    }
    return;
}

std::map<std::string, GE::IEntity *> Menu::getEntities()
{
    return _entities;
}

void Menu::switchButtonDown()
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

void Menu::switchButtonUp()
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

fptr Menu::actionActiveButton()
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

fptr Menu::eventListener(sf::Event event)
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

void Menu::addEntity(enum ENTITY_TYPE type, sf::Vector2f position)
{
    (void) type;
    (void) position;

    return;
}