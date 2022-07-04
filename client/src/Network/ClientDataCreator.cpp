/*
** EPITECH PROJECT, 2020
** ClientDataCreator.cpp
** File description:
** ClientDataCreator
*/

#include "ClientDataCreator.hpp"
#include "Position.hpp"

void ClientDataCreator::write_event(int i)  {
    this->event = i;
}

void ClientDataCreator::write_playerId(const std::string &str) {
    this->playerId = str;
}

void ClientDataCreator::write_player_pos(float x, float y, std::string ID) {
    sf::Vector2f vector;
    vector.x = x;
    vector.y = y;
    this->position_player->setID(ID);
    this->position_player->setPosition(vector);
}

void ClientDataCreator::write_rocket_pos(float x, float y, std::string ID) {
    sf::Vector2f vector;
    vector.x = x;
    vector.y = y;
    this->position_rocket->setID(ID);
    this->position_rocket->setPosition(vector);
}

void ClientDataCreator::write_stream() { 
    std::ostream os(&this->_streamBuf);
    os << this->playerId;
    os << this->event;
    os << this->position_player;
    os << this->position_rocket;
}

boost::asio::streambuf &ClientDataCreator::getStreamBuf(){ 
    return (_streamBuf);
}

ClientDataCreator::ClientDataCreator() {
    this->position_rocket = new Position(-1, -1, "position_rocket");
    this->position_player = new Position(-1, -1, "position_player");
    this->event = -1;
    this->playerId = nullptr;
}

ClientDataCreator::~ClientDataCreator() {
}
