/*
** EPITECH PROJECT, 2020
** UDPclient.hpp
** File description:
** UDPclient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_

#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include "ClientDataCreator.hpp"
#include "enum_connection.hpp"

class UDPclient {
    public:
        UDPclient(boost::asio::io_service &);
        ~UDPclient();
        void send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 15> send_buf);
        void send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 5> send_buf);
        void start_timer();
        void test_connection();
        void read();
        std::array<char, 4> get_monster();
    private:
        
        boost::asio::deadline_timer timeout;
        std::array<char, 15> serv_buf;  
        std::array<char, 4> recv_buf;
        boost::asio::ip::udp::socket _socket_;
        boost::asio::ip::udp::endpoint sender_endpoint;
        CONNECT state_client;
        CONNECT state_server;
        void cancel_socket();
        void read_timeout(const boost::system::error_code &ec, size_t bytes_transferred);
        void handler(const boost::system::error_code& error, std::size_t size);
        void action(const boost::system::error_code& , std::size_t);
};

#endif
