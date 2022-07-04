/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Speed
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

#ifndef SPEED_HPP_
#define SPEED_HPP_

class Speed : public GE::IComponent
{
public:
    Speed(const GE::IComponent &x) : GE::IComponent(x) {}
    Speed(float speedX, float speedY, std::string ID);
    void setSpeed(float speedX, float speedY);
    std::vector<float> getSpeed();
    ~Speed();
    float _speedX;
    float _speedY;

};

#endif /* !SPEED_HPP_ */
