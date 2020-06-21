#include "core/home/home.hpp"
#include <iostream>
#include <ostream>
#include "games/Text.hpp"

Home::Home()
{
  _name = "toto";
}

Home::~Home()
{

}
/*
void Home::showScore(std::vector<std::pair<std::string, std::size_t>> scores, IGraph *graph)
{
  std::cout << "NAME = " << _name << std::endl;
  int j = scores.size();
  for (int i = 0; i != j; i++) {
    std::cout << "SCORE = " << scores.at(i).first << scores.at(i).second << std::endl;
  }

}*/

int Home::compute(Input input)
{
    if (input == DOWN) {
      return 1;
    }
    if (input == UP) {
      return 2;
    }
    if (input == RIGHT) {
      return 3;
    }
    if (input == LEFT) {
      return 4;
    }
    if (input == SPACE) {
      return 42;
    }
    return 0;
}

std::string Home::selectName(Input input, IGraph *graph)
{
  std::vector<char> letters;
  std::string to_ret;
  char *str = new char(4);
  int pos = 0;


  std::size_t titit = _texts.size();
  letters.push_back('A'); letters.push_back('A'); letters.push_back('A');
  std::string toDisplay = "Enter your Username :";
  _texts.push_back(std::make_pair("Username", new Text(toDisplay, std::make_pair<int, int>(15, 15), 5, 20)));
  while (1) {
  graph->displayText(_texts);
  graph->displaySprite(_entities);
  _texts.clear();
    input = graph->getInput();
    str[0] = letters.at(0); str[1] = letters.at(1); str[2] = letters.at(2); str[3] = '\0';
    to_ret = str;
    _texts.clear();
      _texts.push_back(std::make_pair("Username", new Text(toDisplay, std::make_pair<int, int>(13, 15), 5, 20)));
    _texts.push_back(std::make_pair("Haha", new Text(to_ret, std::make_pair<int, int>(13, 18), 5, 20)));
    if (input == RETURN) {
      str[0] = letters.at(0); str[1] = letters.at(1); str[2] = letters.at(2); str[3] = '\0';
      to_ret = str;
      return to_ret;
    } else if (input == RIGHT) {
      pos++;
      if (pos >= 2)
        pos = 2;
    } else if (input == LEFT) {
      pos--;
      if (pos <= 0)
        pos = 0;
    } else if (input == UP) {
        letters.at(0)--;
        if (letters.at(pos)  > 'Z')
          letters.at(pos) = 'A';
    } else if (input == DOWN) {
        letters.at(pos)--;
        if (letters.at(pos) < 'A')
        letters.at(pos) = 'Z';
    }
  }
  return "toto";
}
