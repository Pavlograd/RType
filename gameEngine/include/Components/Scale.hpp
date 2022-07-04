/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Scale
*/

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

#ifndef SCALE_HPP_
#define SCALE_HPP_

class Scale : public GE::IComponent
{
public:
    Scale(const GE::IComponent &x) : GE::IComponent(x) {}
    Scale(float scaleX, float scaleY, std::string ID);
    std::vector<float> getScale();
    ~Scale();

protected:
private:
    float _scaleX;
    float _scaleY;
};

#endif /* !SCALE_HPP_ */
