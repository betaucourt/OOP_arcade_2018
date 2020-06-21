/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** solarfox header
*/

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <iostream>
#include "../IGame.hpp"
#include "../../Input.hpp"
#include "../../games/Text.hpp"

class Snake : public AGame
{
public:
    Snake();
    ~Snake();

    int compute(Input);
    void preparePrint();
    void moveSnake();
    void addBlock();
    int getDirection(std::string dir);
    void turn(Entity *entity);
    void checkFruit();
    std::pair<int, int> newRandomPos();
    int checkEnd();
    bool headTouchBody();

private:
  /*enum Direction {
    RIGHT = Input::RIGHT,
    LEFT = Input::LEFT,
    UP = Input::UP,
    DOWN = Input::DOWN,
    NONE = Input::NONE,
  };*/
  std::size_t _score;
  Input _direction;
  std::pair<int, int> _lastPlace;
  std::pair<int, int> _block;
  std::vector<std::pair<int, int>> _snake;
  std::pair<int, int> _fruit;
  std::vector<std::pair<std::string, Text*>> _texts;

};

#endif
