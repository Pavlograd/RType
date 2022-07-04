/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Submarine
*/

#include "Enemy.hpp"

#ifndef SUBMARINE_HPP_
#define SUBMARINE_HPP_

class Submarine : public Enemy {
    public:
        Submarine(std::string ID, enum ENTITY_TYPE type, sf::RenderWindow *window, sf::Time *elapsedTime, GE::IComponent *position);
        void doNothing();
        void update();
        void positionUpdate();

    protected:
    private:
        int _nbrSpin = 0;
};

#endif /* !SUBMARINE_HPP_ */
