/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** AScene
*/

#include <iostream>

#include "IScene.hpp"
#include "Engine.hpp"

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

typedef int (*fptr)(GE::Engine *);

namespace GE
{
    class AScene : public GE::IScene
    {
    public:
        virtual void update() = 0;
        virtual std::map<std::string, IEntity *> getEntities() = 0;
        virtual fptr eventListener(sf::Event event) = 0;

    protected:
    private:
    };
} // namespace GE

#endif /* !ASCENE_HPP_ */
