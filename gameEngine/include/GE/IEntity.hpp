/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** IEntity
*/

#include "IComponent.hpp"

#include "enum_entities.hpp"

#ifndef _IENTITY_
#define _IENTITY_

namespace GE
{
    class IEntity
    {
    public:
        virtual void update() = 0;
        const std::string getID() { return _ID; };
        void setID(std::string ID) { _ID = ID; };
        const enum ENTITY_TYPE &getType() { return _type; };
        void setType(enum ENTITY_TYPE type) { _type = type; };

    private:
        std::string _ID;
        enum ENTITY_TYPE _type;
    };

} // namespace GE

#endif /* !_IENTITY_ */
