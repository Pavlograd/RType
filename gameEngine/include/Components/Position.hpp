/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Position
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position : public GE::IComponent {
    public:
        Position(const GE::IComponent &x) : GE::IComponent(x) {}
        Position(float x, float y, std::string ID);
        ~Position();
        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f vector);

    protected:
    private:
        float _x;
        float _y;
};

#endif /* !POSITION_HPP_ */
