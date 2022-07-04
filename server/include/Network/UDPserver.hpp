/*
** EPITECH PROJECT, 2020
** UDPserver.hpp
** File description:
** UDPserver
*/

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>

#include "enum_connection.hpp"

class UDPserver {
    public:
        UDPserver(boost::asio::io_service &io_service);
        ~UDPserver();
        void create_monster();
        void send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 4>);
        void send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 15> send_buf);
    private:
        std::array<char, 512> recv_buf;
        boost::asio::ip::udp::socket _socket_;
        boost::asio::ip::udp::endpoint sender_endpoint;
        boost::asio::ip::udp::endpoint *receiver_endpoint;
        time_t _time;
        CONNECT state_client;
        CONNECT state_server;
        void connection_client();
        void read();
        void start_receive();
        void action(const boost::system::error_code& , std::size_t);
};

#endif /* !UDPSERVER_HPP_ */
