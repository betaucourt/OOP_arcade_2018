
#ifndef CORE_H_
#define CORE_H_

#include <ostream>
#include <iostream>
#include "core/parser/parser.hpp"
#include "core/home/home.hpp"
#include "games/IGame.hpp"

class Core
{
public:
    Core();
    Core(char **av);
    ~Core();

    Parser _parser;
    Home _home;

    void run();


    void getNextGraph();
    void getPrevGraph();
    void getNextGame();
    void getPrevGame();
    void setLibGame(std::string);
    void setLibGraph(std::string);
    std::string definedPath(char *av1);
    std::string getSaveFirst();
    std::string replacePathSave(std::string path);
    std::vector<std::pair<std::string, std::size_t>> getSaveGame(std::string path);
    std::pair<std::string, std::size_t> getParsedSave(std::string line);
    int handleInput(Input input, AGame **game, IGraph **graph);
    IGraph *deleteGraph(AGame *game);
    //getter
    std::string getActualGame();
    std::vector<std::pair<std::string, std::size_t>> getGameScore();
    std::pair<std::string, std::size_t> getActualScore();
    std::size_t getGamePos();
    std::string getActualGraph();
    std::size_t getGraphPos();
    int _posGame;
    int _posGraph;
    AGame *loadGame();
    IGraph *loadGraph();
private:
  std::pair<std::string, std::size_t> _gameScore;
  std::vector<std::pair<std::string, std::size_t>> _actualSave;
  std::string _user;
  std::vector<void *> _gameList;
  std::vector<void *> _graphList;
  std::string _actualGame;
  std::string _actualGraph;
  void *_loadedGame;
  void *_loadedGraph;
  std::size_t _score;

protected:

};



#endif // CORE_H_
