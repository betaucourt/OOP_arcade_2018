/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** vessel content
*/

#include "Solarfox.hpp"

Vessel::Vessel(std::string name, std::pair<int, int> pos, Vessel::Direction direction, int range) :
_name(name), _lastShot(clock()), _time(clock()), _pos(pos), _direction(direction), _directionBuf(direction),
_range(range), _shotPos(std::make_pair(0, 0))
{
}

Vessel::~Vessel()
{
}

void Vessel::turn(Entity *entity, std::pair<int, int> next)
{
    Direction tmp[4] = {UP, RIGHT, DOWN, LEFT};

    _direction = _directionBuf;
    for (int i = 0 ; i < 4 ; i++)
        if (_direction == tmp[i])
            entity->setAngle(90 * i);
    setPos(next);
}

int Vessel::forward(Entity *entity)
{
    float dt = static_cast<float>(clock() - _time) / CLOCKS_PER_SEC;
    std::pair<float, float> next = entity->getPos();


    switch (_direction) {
        case DOWN:
            next.second += dt * 50;
            if (next.second - getPos().second >= 1) {
                next.second = getPos().second + 1;
                turn(entity, next);
            }
            break;
        case UP:
            next.second -= dt * 50;
            if (getPos().second - next.second >= 1) {
                next.second = getPos().second - 1;
                turn(entity, next);
            }
            break;
        case RIGHT:
            next.first += dt * 50;
            if (next.first - getPos().first >= 1) {
                next.first = getPos().first + 1;
                turn(entity, next);
            }
            break;
        case LEFT:
            next.first -= dt * 50;
            if (getPos().first - next.first >= 1) {
                next.first = getPos().first - 1;
                turn(entity, next);
            }
            break;
    }
    entity->setPos(next);
    if (next.first < 1 || next.first > 29 || next.second < 0 || next.second > 29)
        return 1;
    _time = clock();
    return 0;
}

void Vessel::shoot(std::pair<int, int> target)
{
    clock_t tmp = clock();

    if (((tmp - _lastShot) / static_cast<float>CLOCKS_PER_SEC) < 0.02)
        return;
    _lastShot = tmp;
    target = target;
}

void Vessel::shoot()
{
    clock_t tmp = clock();

    if (((tmp - _lastShot) / static_cast<float>CLOCKS_PER_SEC) < 0.02)
        return;
    _lastShot = tmp;
}

void Vessel::checkInput(Input input)
{
    if (input + _direction == 0)
        _directionBuf = static_cast<Direction>(input);
}

std::string Vessel::getName() const
{
    return _name;
}

void Vessel::setName(std::string name)
{
    _name = name;
}

std::pair<int, int> Vessel::getPos() const
{
    return _pos;
}

void Vessel::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

Vessel::Direction Vessel::getDirection() const
{
    return _direction;
}

void Vessel::setDirection(Vessel::Direction direction)
{
    _direction = direction;
}

Vessel::Direction Vessel::getDirectionBuf() const
{
    return _directionBuf;
}

void Vessel::setDirectionBuf(Vessel::Direction directionBuf)
{
    _directionBuf = directionBuf;
}


int Vessel::getRange() const
{
    return _range;
}

void Vessel::setRange(int range)
{
    _range = range;
}

std::pair<int, int> Vessel::getShotPos() const
{
    return _shotPos;
}

void Vessel::setShotPos(std::pair<int, int> pos)
{
    _shotPos = pos;
}
