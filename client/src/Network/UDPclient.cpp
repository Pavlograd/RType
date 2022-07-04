/*
** EPITECH PROJECT, 2020
** UDPclient.cpp
** File description:
** UDPclient
*/

#include "UDPclient.hpp"
#include <iostream>

std::array<char, 4> UDPclient::get_monster()
{
  std::array<char, 4> ret = {'N', 'N', 'N', 'N'};

  if (recv_buf[0] == 'N' || recv_buf[0] == 's')
  {
    return (ret);
  }
  else
  {
    ret[0] = recv_buf[0];
    ret[1] = recv_buf[1];
    ret[2] = recv_buf[2];
    ret[3] = recv_buf[3];
    recv_buf[0] = 'N';
    recv_buf[1] = 'N';
    recv_buf[2] = 'N';
    recv_buf[3] = 'N';
  }
  return (ret);
}

void UDPclient::cancel_socket()
{
  exit(84);
}

void UDPclient::handler(const boost::system::error_code &error, std::size_t size)
{
  (void) size;
  if (!error)
  {
    if (strcmp(serv_buf.data(), "server_connect") == 0)
    {
      std::cout << "[CLIENT] Connected to server" << std::endl;
      state_client = CLIENT_CONNECT;
      state_server = SERVER_CONNECT;
      start_timer();
    }
    else
    {
      std::cerr << "[CLIENT] Fail to connect" << std::endl;
      cancel_socket();
    }
  }
  else
  {
    exit(84);
  }
}

void UDPclient::read_timeout(const boost::system::error_code &ec, size_t bytes_transferred)
{
  (void) bytes_transferred;
  if (!ec && state_client != CLIENT_CONNECT)
  {
    exit(84);
  }
}

void UDPclient::start_timer()
{
  if (state_client != CLIENT_CONNECT)
  {
    timeout.expires_from_now(boost::posix_time::millisec(5));
    timeout.async_wait(std::bind(&UDPclient::read_timeout, this, std::placeholders::_1, true));
    test_connection();
  }
}

void UDPclient::test_connection()
{
  std::array<char, 15> send_buf  = {"client_connect"}; 

  send(boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7172), send_buf);    
  _socket_.async_receive_from(boost::asio::buffer(serv_buf), sender_endpoint, std::bind(&UDPclient::handler, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPclient::read()
{  
    std::array<char, 5> none = {"None"}; 
    send(boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7172), none);    
    _socket_.async_receive_from(boost::asio::buffer(recv_buf), sender_endpoint, std::bind(&UDPclient::action, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPclient::send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 5> send_buf)
{
  _socket_.send_to(boost::asio::buffer(send_buf), endpoint);
}

void UDPclient::send(boost::asio::ip::udp::endpoint endpoint, std::array<char, 15> send_buf)
{
  _socket_.send_to(boost::asio::buffer(send_buf), endpoint);
}

void UDPclient::action(const boost::system::error_code &error, std::size_t size)
{
  (void) size;
  if (!error)
  {
    read();
  }
  else
  {
    exit(84);
  }
}

UDPclient::UDPclient(boost::asio::io_service &io_service) : _socket_(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7171)), timeout(io_service)
{
  std::cout << "[CLIENT] Start connection to serveur" << std::endl;
  state_client = CLIENT_DECO;
  state_server = SERV_DECO;
}

UDPclient::~UDPclient()
{
}