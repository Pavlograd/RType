/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** main
*/

#include "Client.hpp"
#include "Engine.hpp"
#include "Menu.hpp"

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL)
        exit(84);
    Client *client = new Client();

    client->start();

    return 0;
}