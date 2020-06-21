/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** vessel header
*/

#ifndef VESSEL_H
#define VESSEL_H

#include <utility>
#include <ctime>
#include "Solarfox.hpp"

class Vessel
{
public:
    enum Direction
    {
        UP = Input::UP,
        DOWN = Input::DOWN,
        RIGHT = Input::RIGHT,
        LEFT = Input::LEFT
    };
    Vessel(std::string, std::pair<int, int>, Direction, int);
    ~Vessel();

    std::string getName() const;
    void setName(std::string);
    std::pair<int, int> getPos() const;
    void setPos(std::pair<int, int>);
    Direction getDirection() const;
    void setDirection(Direction);
    Direction getDirectionBuf() const;
    void setDirectionBuf(Direction);
    int getRange() const;
    void setRange(int);
    std::pair<int, int> getShotPos() const;
    void setShotPos(std::pair<int, int>);

    void shoot(std::pair<int, int>);
    void shoot();
    int forward(Entity*);
    void checkInput(Input);
    void turn(Entity *, std::pair<int, int>);

private:
    std::string _name;
    clock_t _lastShot;
    clock_t _time;
    std::pair<int, int> _pos;
    Direction _direction;
    Direction _directionBuf;
    int _range;
    std::pair<int, int> _shotPos;
};

#endif
