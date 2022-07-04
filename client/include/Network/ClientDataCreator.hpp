/*
** EPITECH PROJECT, 2020
** ClientDataCreator.hpp
** File description:
** ClientDataCreator
*/

#ifndef CLIENTDATACREATOR_HPP_
#define CLIENTDATACREATOR_HPP_

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "Position.hpp"

class ClientDataCreator {
    public:
        ClientDataCreator();
        ~ClientDataCreator();
        void write_playerId(const std::string &str);
        void write_event(int i);
        void write_player_pos(float x, float y, std::string ID);
        void write_rocket_pos(float x, float y, std::string ID);
        void write_stream();
        boost::asio::streambuf &getStreamBuf();
    private:
        boost::asio::streambuf _streamBuf;
        std::string playerId;
        int event;
        Position *position_player;
        Position *position_rocket;
};

#endif /* !CLIENTDATACREATOR_HPP_ */
