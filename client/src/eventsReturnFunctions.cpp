/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** eventsReturnFunctions
*/

#include "eventsReturnFunctions.hpp"

int exitGame(GE::Engine *engine)
{
    engine->getWindow()->close();
    return 0;
}

int startLevel(GE::Engine *engine)
{
    engine->setScene(LEVEL1);
    return 0;
}

int nothingToDo(GE::Engine *engine)
{
    (void)engine;
    return 0;
}

int gameOver(GE::Engine *engine)
{
    engine->setScene(GAME_OVER);
    return 0;
}

int winScene(GE::Engine *engine)
{
    engine->setScene(WIN);
    return 0;
}