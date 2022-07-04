/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** rtype
*/

#include "Button.hpp"

Button::Button(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, enum ACTIVE active, GE::IComponent *position, GE::IComponent *activeText, GE::IComponent *notActiveText)
{
    setID(ID);
    setType(type);
    _window = window;
    _isActive = active;
    _components[position->getID()] = position;
    _components[activeText->getID()] = activeText;
    _components[notActiveText->getID()] = notActiveText;
    ((Text *)_components["activeText"])->setPosition(((Position *)_components["position"])->getPosition());
    ((Text *)_components["notActiveText"])->setPosition(((Position *)_components["position"])->getPosition());
}

Button::~Button()
{
}

void Button::update()
{
    if (_isActive == ACTIVE)
        _window->draw(((Text *)_components["activeText"])->getText());
    else
        _window->draw(((Text *)_components["notActiveText"])->getText());
}

enum ACTIVE Button::getIfActive()
{
    return _isActive;
}

void Button::setIfActive(enum ACTIVE active)
{
    _isActive = active;
}