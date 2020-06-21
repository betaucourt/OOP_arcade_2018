#include "parser.hpp"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

Parser::Parser()
{
  this->setLibFolder();
  _save = "./saves/";
};

Parser::~Parser()
{

};

void Parser::setGameName()
{
  std::vector<std::string> path = getAllGames();
  int i = path.size();

std::cout << std::endl << std::endl;
  for(int j = 0; j != i; j++) {
    if (path.at(j).find_last_of(".so") != std::string::npos) {
      path.at(j) = path.at(j).substr(path.at(j).rfind("_") + 1);
      path.at(j) = path.at(j).erase(path.at(j).rfind("."));
      path.at(j) += ".txt";
      _gameName.push_back(path.at(j));
    }
  }
  for(int j = 0; j != i; j++) {
    std::cout << "GAME NAME = " << _gameName.at(j) << std::endl;
  }
  std::cout << std::endl << std::endl;
}

std::vector<std::string> Parser::getGameName()
{
  return _gameName;
}

std::vector<std::string> Parser::parseFolder(std::string gamePath)
{
  DIR *dir = opendir(gamePath.c_str());
  struct dirent *entry;
  std::string tmp;
  tmp = gamePath;
  std::vector<std::string> to_ret;

  while ((entry = readdir(dir)) != NULL) {
    tmp = entry->d_name;
    if (tmp.find(".so") != std::string::npos)
      to_ret.push_back(entry->d_name);
  }
  closedir(dir);
  return to_ret;
}

void Parser::setGames()
{
  std::vector<std::string> libPath;
  std::vector<std::size_t> libNb;
  std::size_t curr;
  std::string gamePath = this->getLibFolder() + "/games/";
  libPath = parseFolder(gamePath);

  curr = libPath.size();
  _totalG = curr;
  for(std::size_t i = 0; i != curr; i++) {
    libPath.at(i) = gamePath + libPath.at(i);
  }
  gamePath = this->getLibFolder() + "/graph/";
  _foundG = libPath;
  libPath.clear();
  libPath = parseFolder(gamePath);
  curr = libPath.size();
  _totalL = curr;
  for(std::size_t i = 0; i != curr; i++) {
    libPath.at(i) = gamePath + libPath.at(i);
  }
  _foundL = libPath;
}

void Parser::setLibFolder()
{
  std::string path;
  path = ".";
  _libFolder = path;
  this->setGames();
}


std::string Parser::getLibFolder()
{
  return _libFolder;
}

std::vector<std::string> Parser::getGames()
{
  return _foundG;
}

std::vector<std::size_t> Parser::getPosGame()
{
  return _posG;
}

std::vector<std::string> Parser::getGraph()
{
  return _foundL;
}

std::vector<std::size_t> Parser::getPosGraph()
{
  return _posL;
}

std::size_t Parser::getTotalGame()
{
  return _totalG;
}

std::size_t Parser::getTotalGraph()
{
  return _totalL;
}


std::vector<std::string> Parser::getAllGames()
{
  return _foundG;
}

std::vector<std::string> Parser::getAllGraph()
{
  return _foundL;
}

std::string Parser::getGameAt(std::size_t pos)
{
  return _foundG.at(pos);
}

std::string Parser::getGraphAt(std::size_t pos)
{
  return _foundL.at(pos);
}
