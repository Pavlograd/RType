/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** rtype
*/

#include <iostream>
#include <map>

#include "enum_scenes.hpp"
#include "IEntity.hpp"

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

namespace GE
{
    class IScene
    {
    public:
        virtual void update() = 0;
        enum SCENES getID() { return _ID; };
        void setID(enum SCENES ID) { _ID = ID; };
        virtual std::map<std::string, IEntity *> getEntities() = 0;
        virtual void addEntity(enum ENTITY_TYPE type, sf::Vector2f position) = 0;

    private:
        enum SCENES _ID;
    };
} // namespace GE

#endif /* !ISCENE_HPP_ */