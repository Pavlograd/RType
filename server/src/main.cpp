/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main
*/

#include "../include/Network/UDPserver.hpp"

int main() {
  try {
    boost::asio::io_service io_service;
    UDPserver server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}