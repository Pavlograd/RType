/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Plane
*/

#include "Enemy.hpp"

#ifndef PLANE_HPP_
#define PLANE_HPP_

class Plane : public Enemy {
    public:
        Plane(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position);
        void doNothing();
        void update();
        void positionUpdate();

    protected:
    private:
        int _nbrSpin = 0;
};

#endif /* !PLANE_HPP_ */
