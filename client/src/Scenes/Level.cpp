/*
** EPITECH PROJECT, 2020
** B-CPP-501-LIL-5-1-rtype-victor.cuvelier
** File description:
** Level
*/

#include "Level.hpp"

#include "eventsReturnFunctions.hpp"

Level::Level(enum SCENES ID, sf::RenderWindow *window, sf::Time *elapsedTime)
{
    setID(ID);
    client = new UDPclient(io_service);
    client->start_timer();
    io_service.run();
    _window = window;
    _elapsedTime = elapsedTime;
    //_entities[std::string("002_submarine1")] = new Submarine("submarine1", SUBMARINE, _window, _elapsedTime, new Position(1920, 800, "position"));
    //_entities[std::string("002_Plane1")] = new Plane("plane1", PLANE, _window, _elapsedTime, new Position(1920, 100, "position"));
    //_entities[std::string("002_RaptorPlane1")] = new RaptorPlane("raptorPlane1", RAPTORPLANE, _window, _elapsedTime, new Position(1920, 200, "position"));
    //_entities[std::string("002_Laser1")] = new Laser("Laser1", LASER, _window, _elapsedTime, new Position(0, 200, "position"));
    _entities[std::string("000_parralax1")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-bg.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.2, 0, "speed"));
    _entities[std::string("000_parralax2")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-bg.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.2, 0, "speed"));
    _entities[std::string("000_parralax3")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-far-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.6, 0, "speed"));
    _entities[std::string("000_parralax4")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 0, "position"), new Sprite("../assets/parralax/parallax-industrial-far-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-0.6, 0, "speed"));
    _entities[std::string("000_parralax5")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 20, "position"), new Sprite("../assets/parralax/parallax-industrial-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1, 0, "speed"));
    _entities[std::string("000_parralax6")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 20, "position"), new Sprite("../assets/parralax/parallax-industrial-buildings.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1, 0, "speed"));
    _entities[std::string("000_parralax7")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(0, 350, "position"), new Sprite("../assets/parralax/parallax-industrial-foreground.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1.4, 0, "speed"));
    _entities[std::string("000_parralax8")] = new ParralaxSprite(PARRALAX_SPRITE, _window, _elapsedTime, new Position(1920, 350, "position"), new Sprite("../assets/parralax/parallax-industrial-foreground.png", "sprite"), new Scale(8, 6.75, "scale"), new Speed(-1.4, 0, "speed"));
    _entities[std::string("002_player1")] = new Player("player1", PLAYER, _window, _elapsedTime, new Position(50, 50, "position"), new Sprite("../assets/sprites/players.gif", "sprite"), new Scale(4, 4, "scale"), new Speed(0, 0, "speed"), new Rect(0, 0, 34, 20, 0, "rect"));
}

Level::~Level()
{
}

void Level::checkMonsterFromServer(std::array<char, 4> arr)
{
    if (arr[0] != '1' && arr[0] != '2' && arr[0] != '3')
        return;
    int positionY = (arr[1] - 48) * 100 + (arr[2] - 48) * 10 + (arr[3] - 48);

    switch (arr[0] - 48)
    {
    case 1:
        addEntity(PLANE, sf::Vector2f(1920, positionY));
        break;
    case 2:
        addEntity(RAPTORPLANE, sf::Vector2f(1920, positionY));
        break;
    case 3:
        addEntity(SUBMARINE, sf::Vector2f(1920, positionY));
        break;
    default:
        break;
    }
}

void Level::updateEnemies(std::map<std::string, GE::IEntity *>::const_iterator it)
{
    enum ENTITY_TYPE type = it->second->getType();
    if ((type == PLANE || type == RAPTORPLANE || type == SUBMARINE) && ((Enemy *)it->second)->getState() == ALIVE)
    {
        sf::Vector2f enemyVector = ((Enemy *)it->second)->getPosition();
        sf::IntRect enemyRect = ((Enemy *)it->second)->getRect();
        for (std::map<std::string, GE::IEntity *>::const_iterator at = _entities.begin(); at != _entities.end(); ++at)
        {
            if (at->second->getType() == LASER && ((Enemy *)at->second)->getState() == ALIVE)
            {
                sf::Vector2f laserVector = ((Laser *)at->second)->getPosition();
                sf::IntRect laserRect = ((Laser *)at->second)->getRect();

                if (((laserVector.x > enemyVector.x && laserVector.x < enemyVector.x + enemyRect.width) || (laserVector.x + laserRect.width > enemyVector.x && laserVector.x + laserRect.width < enemyVector.x + enemyRect.width)) && ((laserVector.y > enemyVector.y && laserVector.y < enemyVector.y + enemyRect.height) || (laserVector.y + laserRect.height > enemyVector.y && laserVector.y + laserRect.height < enemyVector.y + enemyRect.height)))
                {
                    ((Enemy *)it->second)->setState(DEAD);
                    ((Laser *)at->second)->setState(DEAD);
                    _deadEnemies++;
                    break;
                }
            }
        }
        if (enemyVector.x < -100)
        {
            ((Enemy *)it->second)->setState(DEAD);
            _deadEnemies++;
            _lives--;
        }
    }
}

void Level::updatePlayer(std::map<std::string, GE::IEntity *>::const_iterator it)
{
    if (it->second->getType() == PLAYER && ((Player *)it->second)->getState() == ALIVE)
    {
        sf::Vector2f playerVector = ((Player *)it->second)->getPosition();
        sf::IntRect playerRect = ((Player *)it->second)->getRect();

        for (std::map<std::string, GE::IEntity *>::const_iterator at = _entities.begin(); at != _entities.end(); ++at)
        {
            enum ENTITY_TYPE type = at->second->getType();
            if ((type == PLANE || type == RAPTORPLANE || type == SUBMARINE) && ((Enemy *)at->second)->getState() == ALIVE)
            {
                sf::Vector2f enemyVector = ((Enemy *)at->second)->getPosition();
                sf::IntRect enemyRect = ((Enemy *)at->second)->getRect();

                if (((playerVector.x > enemyVector.x && playerVector.x < enemyVector.x + enemyRect.width) || (playerVector.x + playerRect.width > enemyVector.x && playerVector.x + playerRect.width < enemyVector.x + enemyRect.width)) && ((playerVector.y > enemyVector.y && playerVector.y < enemyVector.y + enemyRect.height) || (playerVector.y + playerRect.height > enemyVector.y && playerVector.y + playerRect.height < enemyVector.y + enemyRect.height)))
                {
                    ((Player *)it->second)->setState(DEAD);
                    break;
                }
            }
        }
    }
}

void Level::update()
{
    client->read();
    io_service.poll();
    std::array<char, 4> arr = client->get_monster();
    checkMonsterFromServer(arr);

    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        updatePlayer(it);
        updateEnemies(it);
        it->second->update();
    }
    io_service.reset();
    return;
}

std::map<std::string, GE::IEntity *> Level::getEntities()
{
    return _entities;
}

bool Level::noMorePlayerLeft()
{
    int playersAlive = 0;

    for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        if (it->second->getType() == PLAYER && ((Player *)it->second)->getState() == ALIVE)
            playersAlive++;
    }
    return (playersAlive == 0 || _lives <= 0) ? true : false;
}

fptr Level::eventListener(sf::Event event)
{
    (void)event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        for (std::map<std::string, GE::IEntity *>::const_iterator it = _entities.begin(); it != _entities.end(); ++it)
        {
            if (it->second->getType() == PLAYER && ((Player *)it->second)->shoot())
            {
                addEntity(LASER, sf::Vector2f(((Player *)it->second)->getPosition().x, ((Player *)it->second)->getPosition().y + 35));
                break;
            }
        }
    }

    if (noMorePlayerLeft())
        return gameOver;
    if (_deadEnemies >= 30)
        return winScene;
    return nothingToDo;
}

void Level::addEntity(enum ENTITY_TYPE type, sf::Vector2f position)
{
    bool added = false;

    switch (type)
    {
    case PLANE:
        for (std::map<std::string, GE::IEntity *>::reverse_iterator it = _entities.rbegin(); it != _entities.rend(); ++it)
        {
            if (it->second->getType() == PLANE && ((Enemy *)it->second)->getState() == ALIVE)
            {
                _entities[std::string("002_Plane" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1))] = new Plane(std::string("plane" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1)), PLANE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
                added = true;
                break;
            }
        }
        if (!added)
            _entities[std::string("002_Plane1")] = new Plane("plane1", PLANE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
        break;
    case RAPTORPLANE:
        for (std::map<std::string, GE::IEntity *>::reverse_iterator it = _entities.rbegin(); it != _entities.rend(); ++it)
        {
            if (it->second->getType() == RAPTORPLANE && ((Enemy *)it->second)->getState() == ALIVE)
            {
                _entities[std::string("002_RaptorPlane" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1))] = new RaptorPlane(std::string("raptorPlane" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1)), RAPTORPLANE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
                added = true;
                break;
            }
        }
        if (!added)
            _entities[std::string("002_RaptorPlane1")] = new RaptorPlane("raptorPlane1", RAPTORPLANE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
        break;
    case SUBMARINE:
        for (std::map<std::string, GE::IEntity *>::reverse_iterator it = _entities.rbegin(); it != _entities.rend(); ++it)
        {
            if (it->second->getType() == SUBMARINE && ((Enemy *)it->second)->getState() == ALIVE)
            {
                _entities[std::string("002_Submarine" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1))] = new Submarine(std::string("submarine" + std::to_string(std::stoi(it->first.substr(it->first.find("e") + 1)) + 1)), SUBMARINE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
                added = true;
                break;
            }
        }
        if (!added)
            _entities[std::string("002_submarine1")] = new Submarine("submarine1", SUBMARINE, _window, _elapsedTime, new Position(position.x, position.y, "position"));
        break;
    case LASER:
        for (std::map<std::string, GE::IEntity *>::reverse_iterator it = _entities.rbegin(); it != _entities.rend(); ++it)
        {
            if (it->second->getType() == LASER && ((Enemy *)it->second)->getState() == ALIVE)
            {
                _entities[std::string("002_Laser" + std::to_string(std::stoi(it->first.substr(it->first.find("r") + 1)) + 1))] = new Laser(std::string("laser" + std::to_string(std::stoi(it->first.substr(it->first.find("r") + 1)) + 1)), LASER, _window, _elapsedTime, new Position(position.x, position.y, "position"));
                added = true;
                break;
            }
        }
        if (!added)
            _entities[std::string("002_Laser1")] = new Laser("Laser1", LASER, _window, _elapsedTime, new Position(position.x, position.y, "position"));
        break;
    default:
        break;
    }
    return;
}