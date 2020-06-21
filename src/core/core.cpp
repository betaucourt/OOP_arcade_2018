#include "core/core.hpp"
#include <dlfcn.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

std::string Core::definedPath(char *av1)
{
  std::vector<std::string> test = _parser.getAllGraph();
  int i = test.size();
  std::string *stdav1 = new std::string(av1);
  for(int j = 0; j != i; j++) {
    if (stdav1->compare(test.at(j)) == 0) {
      return av1;
    }
  }
  std::cout << "Cette librairie n'existe pas" << std::endl;
  exit(0);
  return nullptr;
}


Core::Core(char **av)
{
  _parser.getLibFolder();
  _posGame = 0;
  _posGraph = 0;
  std::size_t nbGraph = 0;
  std::string tmp;
  nbGraph = _parser.getTotalGraph();
  if (nbGraph >= 1) {
    _actualGame = _parser.getGameAt(0);
    _posGraph = 0;
  }
  _actualGraph = definedPath(av[1]);
  if (_actualGame.empty() == true || _actualGraph.empty() == true) {
    std::cout << "something very bad happened = exit(0)" << std::endl;
    exit(0);
  }
  setLibGame(_actualGame);
  setLibGraph(_actualGraph);
}

Core::Core()
{
}

Core::~Core()
{

}

std::string Core::getSaveFirst()
{
  std::vector<std::string> to_ret = _parser.getGameName();
  int i = to_ret.size();
  std::string tmp = to_ret.at(0);
  return to_ret.at(0);
}

std::string Core::replacePathSave(std::string path)
{
  std::string to_ret = "./saves/";
  std::string tmp;
  tmp = path.substr(path.rfind("_") + 1);
  to_ret += tmp + ".txt";
  to_ret.erase(to_ret.rfind(".so"), 3);
  return to_ret;
}

std::pair<std::string, std::size_t> Core::getParsedSave(std::string line)
{
  std::pair<std::string, std::size_t> to_ret;

  to_ret.first = line.substr(0, line.find(":"));
  to_ret.second = 9;
  return to_ret;
}

std::vector<std::pair<std::string, std::size_t>> Core::getSaveGame(std::string path)
{
  std::vector<std::pair<std::string, std::size_t>> to_ret;
  std::ifstream is(path, std::ifstream::binary);
  std::string test;
  std::vector<std::string> tmp;

  if (is) {
    is.seekg(0, is.end);
    is.seekg(0, is.beg);
  }
  if (is.is_open()) {
    while (getline(is, test))
      tmp.push_back(test);
  }
  int i = tmp.size();
  if (i == 0 || i == 1)
    return to_ret;
  for(int j = 1; j != i; j++) {
    to_ret.push_back(getParsedSave(tmp.at(j)));
  }
  return to_ret;
}

void Core::setLibGame(std::string lib)
{
  std::string savePath = replacePathSave(lib);
  _actualSave = getSaveGame(savePath);

  if (_loadedGame != NULL) {
    dlclose(_loadedGame);
    _loadedGame = NULL;
  }
  _loadedGame = dlopen(lib.c_str(), RTLD_NOW | RTLD_GLOBAL);
  if (_loadedGame == NULL) {
    std::cout << dlerror() << std::endl;
  }
}

void Core::setLibGraph(std::string lib)
{
  if (_loadedGraph != NULL) {
    dlclose(_loadedGraph);
    _loadedGraph = NULL;
  }
  _loadedGraph = dlopen(lib.c_str(), RTLD_NOW | RTLD_GLOBAL);
  if (_loadedGraph == NULL) {
    std::cout << dlerror() << std::endl;
  }
}

void Core::getNextGraph()
{
  _posGraph++;
  if (_posGraph > (int)_parser.getTotalGraph() - 1)
    _posGraph = 0;
  _actualGraph = _parser.getGraphAt(_posGraph);
  setLibGraph(_actualGraph);
}

void Core::getPrevGraph()
{
  _posGraph--;
  if (_posGraph <= -1)
    _posGraph = (_parser.getTotalGraph() - 1);
  if (_posGraph < 0 && _parser.getTotalGame() == 1)
    _posGraph = 0;
  _actualGraph = _parser.getGraphAt(_posGraph);
  setLibGraph(_actualGraph);
}

void Core::getNextGame()
{
  _posGame++;
  if (_posGame > ((int)_parser.getTotalGame() - 1))
    _posGame = 0;
  _actualGame = _parser.getGameAt(_posGame);
  setLibGame(_actualGame);
}

void Core::getPrevGame()
{
  _posGame--;
  if (_posGame <= -1)
    _posGame = (_parser.getTotalGame() - 1);
  _actualGame = _parser.getGameAt(_posGame);
  setLibGame(_actualGame);
}

int Core::handleInput(Input input, AGame **game, IGraph **graph)
{
  int tmp = 0;

  if (input == SPACE) {
  } else if (input == PREVLIB) {
    (*graph)->closeWindow();
    getPrevGraph();
    (*graph) = loadGraph();
    (*graph)->openWindow();
  } else if (input == NEXTLIB) {
    (*graph)->closeWindow();
    getNextGraph();
    (*graph) = loadGraph();
    (*graph)->openWindow();
  } else if (input == RESTART) {
    delete (*game);
    (*game) = NULL;
    (*game) = loadGame();
  } else if (input == PREVGAME) {
    getPrevGame();
    delete (*game);
    (*game) = loadGame();
  } else if (input == NEXTGAME) {
    getNextGame();
    delete (*game);
    (*game) = loadGame();
  } else if (input == QUIT) {
    exit(0);
  } else {
      tmp = (*game)->compute(input);
      if (tmp <= -1)
        return -1;
      else
        _score = tmp;
  }
  return 0;
}

void Core::run()
{
  setLibGame(_actualGame);
  Input input;
  IGraph *graph = this->loadGraph();
  Home home;

  graph->openWindow();
  _user = home.selectName(input, graph);
  AGame *game = this->loadGame();
  int tmp = 1;
  while (1) {
    input = graph->getInput();
    tmp = handleInput(input, &game, &graph);
    game->getControls();
      graph->displaySprite(game->getEntities());
      graph->displayText(game->getTexts());
      if (tmp == -1 || tmp == -2) {
      delete game;
      game = NULL;
      game = loadGame();
    }
  }
}

std::string Core::getActualGame()
{
  return _actualGame;
}

std::string Core::getActualGraph()
{
  return _actualGraph;
}

std::size_t Core::getGamePos()
{
  return _posGame;
}

std::size_t Core::getGraphPos()
{
  return _posGraph;
}

IGraph *Core::deleteGraph(AGame *game) {
}

IGraph *Core::loadGraph() {
  return (reinterpret_cast<IGraph * (*)()>(dlsym(_loadedGraph, "entry")))();
}

AGame *Core::loadGame() {

  return (reinterpret_cast<AGame * (*)()>(dlsym(_loadedGame, "entry")))();
}

std::pair<std::string, std::size_t> Core::getActualScore()
{
  return _gameScore;
}

std::vector<std::pair<std::string, std::size_t>> Core::getGameScore()
{
  return _actualSave;
}
