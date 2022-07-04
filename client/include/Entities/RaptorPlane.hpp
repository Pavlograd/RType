/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** RaptorPlane
*/

#include "Enemy.hpp"

#ifndef RAPTORPLANE_HPP_
#define RAPTORPLANE_HPP_

class RaptorPlane : public Enemy {
    public:
        RaptorPlane(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position);
        void doNothing();
        void update();
        void positionUpdate();

    protected:
    private:
        int _nbrSpin = 0;
};

#endif /* !RAPTORPLANE_HPP_ */
