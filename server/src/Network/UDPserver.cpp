/*
** EPITECH PROJECT, 2020
** UDPserver.cpp
** File description:
** UDPserver
*/

#include "../../include/Network/UDPserver.hpp"

void UDPserver::read()
{
    _socket_.async_receive_from(boost::asio::buffer(recv_buf), sender_endpoint, std::bind(&UDPserver::action, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPserver::send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 4> send_buf) 
{	
	_socket_.send_to(boost::asio::buffer(send_buf), endpoint);
}


void UDPserver::send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 15> send_buf) 
{	
	_socket_.send_to(boost::asio::buffer(send_buf), endpoint);
}

void UDPserver::connection_client()
{
    std::array<char, 15> send_buf = {"server_connect"};
    state_client = CLIENT_CONNECT;
    state_server = SERVER_CONNECT;

    send(*receiver_endpoint, send_buf);
}

void UDPserver::create_monster()
{
    int type;
    int first_y;
    int second_y;
    int third_y;
    std::array<char, 4> buff;
    srand(time(NULL));
    type = rand() % 3 + 1;
    first_y = rand() % 7;
    second_y = rand() % 9;
    third_y = rand() % 9;
    buff[0] = '0' + type;
    buff[1] = '0' + first_y;
    buff[2] = '0' + second_y;
    buff[3] = '0' + third_y;
    send(*receiver_endpoint, buff);
}

void UDPserver::action(const boost::system::error_code &error, std::size_t size)
{
    (void)size;
    if (!error)
    {
        if (strcmp(recv_buf.data(), "client_connect") == 0 && state_client != CLIENT_CONNECT)
        {
            connection_client();
        }       
        if (time(NULL) - _time >= 3) { 
            create_monster();
            _time = time(NULL); 
        }  
        this->read();        
    } else {
        std::cout << error << std::endl;
    }
}

UDPserver::UDPserver(boost::asio::io_service &io_service) : _socket_(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7172))
{
    receiver_endpoint = new boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7171);
    _time = time(NULL);
    this->read();
}

UDPserver::~UDPserver()
{
}
