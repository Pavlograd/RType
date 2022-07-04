/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Laser
*/

#include "Enemy.hpp"

#ifndef LASER_HPP_
#define LASER_HPP_

class Laser : public Enemy {
    public:
        Laser(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position);
        void doNothing();
        void update();
        void positionUpdate();

    protected:
    private:
        int _nbrSpin = 0;
};

#endif /* !LASER_HPP_ */
