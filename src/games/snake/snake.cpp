#include "snake.hpp"

extern "C" Snake* entry()
{
    return new Snake();
}

void Snake::preparePrint()
{
  std::size_t tmp = _snake.size();
  for(int i = 0; i != tmp; i++) {
    if (i == 0)
    _entities.push_back(std::make_pair("head", new Entity("snakeHead", _snake.at(i), std::make_pair(30, 30), 10)));
    else
    _entities.push_back(std::make_pair("body" + i, new Entity("snakeBody", _snake.at(i), std::make_pair(30, 30), 10)));
  }
  _entities.push_back(std::make_pair("fruit", new Entity("fruit", _fruit, std::make_pair(30, 30), 10)));
  _direction = NONE;
}

void Snake::turn(Entity *entity)
{
    Input tmp[4] = {UP, RIGHT, DOWN, LEFT};

    for (int i = 0 ; i < 4 ; i++) {
        if (_direction == tmp[i])
            entity->setAngle(90 * i);
    }
}

int Snake::getDirection(std::string dir)
{
  if (_direction == 9)
    return 0;

  if (dir == "x") {
    if (_direction == LEFT) {
      return -1;
    }
    else if (_direction == RIGHT)
      return 1;
    return 0;
  } else if (dir == "y") {
    if (_direction == DOWN)
      return 1;
    else if (_direction == UP)
      return -1;
    return 0;
  }
}

void Snake::addBlock()
{
  _block = _snake.at(_snake.size() - 1);
  _snake.push_back(_block);
}

void Snake::moveSnake()
{
  int i = _snake.size() - 1;

  _lastPlace = _snake.at(0);
  _snake.at(0).first += getDirection("x");
  _snake.at(0).second += getDirection("y");
  if (_lastPlace.first != _snake.at(0).first || _lastPlace.second != _snake.at(0).second)  {
    while (i != 1) {
        _snake.at(i) = _snake.at(i - 1);
      i--;
    }
    _snake.at(1) = _lastPlace;
  }
  checkFruit();
}

Snake::Snake()
{
  std::size_t x = 15;
  std::size_t y = 15;

  for(y = 15; y != 19; y++) {
    _block = std::make_pair(x, y);
    _snake.push_back(_block);
  }
  _fruit.first = 11; _fruit.second = 11;
  _score = 0;
  preparePrint();

}

Snake::~Snake()
{

}

std::pair<int, int> Snake::newRandomPos()
{
  addBlock();
  std::size_t random = rand() % 27;
  for(int i = 0; i != 50; i++);
  std::size_t random2 = rand() % 27;
  std::pair<int, int> to_ret = std::make_pair(random, random2);
  return to_ret;
}

void Snake::checkFruit()
{
  if (_fruit.first == 50 && _fruit.second == 50) {
    _fruit = newRandomPos();
  }
  if (_snake.at(0).first == _fruit.first && _snake.at(0).second == _fruit.second) {
    _score += 15;
    _fruit = newRandomPos();
  }
}

bool Snake::headTouchBody()
{
  std::pair<int, int> to_check = _snake.at(0);
  std::size_t size = _snake.size() - 1;
  while (size != 1) {
    if (to_check.first == _snake.at(size).first && to_check.second == _snake.at(size).second) {
      exit(0);
      return true;
    }
    size--;
  }
  return false;
}

int Snake::checkEnd()
{
  if (_snake.at(0).first <= 0 || _snake.at(0).first >= 30)
    return -1;
  if (_snake.at(0).second <= 0 || _snake.at(0).second >= 30)
    return -1;
  if (headTouchBody() == true)
    return -1;
  if (_score == 130) {
    _score = 130;
    return -2;
  }
  return _score;
}

int Snake::compute(Input input)
{
    _direction = input;

  moveSnake();
checkFruit();
  _entities.clear();
  preparePrint();
  turn(_entities.at(0).second);
  return checkEnd();
}
