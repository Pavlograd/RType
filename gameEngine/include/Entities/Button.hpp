/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** rtype
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

#include "enum_entities.hpp"

#ifndef _Button_
#define _Button_

class Button : public GE::IEntity
{
public:
    Button(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, enum ACTIVE active, GE::IComponent *position, GE::IComponent *activeText, GE::IComponent *notActiveText);
    ~Button();
    void update();
    enum ACTIVE getIfActive();
    void setIfActive(enum ACTIVE active);

protected:
private:
    enum ACTIVE _isActive;
    sf::RenderWindow *_window;
    std::map<std::string, GE::IComponent *> _components;
};

#endif /* !_Button_ */