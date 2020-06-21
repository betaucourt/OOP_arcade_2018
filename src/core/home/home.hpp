#ifndef HOME_HPP_
#define HOME_HPP_

#include "games/IGame.hpp"
#include "Input.hpp"

class Home : public AGame
{
public:
  Home();
  ~Home();

  int compute(Input input);
  void showScore(std::vector<std::pair<std::string, std::size_t>>, IGraph *graph);
  std::string selectName(Input input, IGraph *graph);
private:
  std::vector<std::pair<std::string, Entity*>> _entities;
    std::vector<std::pair<std::string, Text*>> _texts;
  std::vector<std::pair<std::string, std::size_t>> _gameSaves;
  std::string _name;
protected:
};

#endif // HOME_HPP_
