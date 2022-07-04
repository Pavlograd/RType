/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** IComponent
*/

#include <iostream>

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace GE
{
    class IComponent
    {
    public:
        const std::string getID() {return _ID;};
        void setID(std::string ID) {_ID = ID;};
    private:
        std::string _ID;
    };
} // namespace GE

#endif /* !ICOMPONENT_HPP_ */