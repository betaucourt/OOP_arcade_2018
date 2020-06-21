
#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <vector>
#include <iostream>
#include <ostream>

class Parser
{
public:
  Parser();
  ~Parser();
  //init
  void setLibFolder();
  void setGames();
  std::vector<std::string> parseFolder(std::string gamePath);
  void setGameName();
  //Getter
  std::vector<std::string> getGameName();
  std::string getLibFolder();
  std::vector<std::string> getGames();
  std::vector<std::size_t> getPosGame();
  std::vector<std::string> getGraph();
  std::vector<std::size_t> getPosGraph();
  std::size_t getTotalGame();
  std::size_t getTotalGraph();
  std::string getGameAt(std::size_t);
  std::string getGraphAt(std::size_t);
  std::vector<std::string> getAllGames();
  std::vector<std::string> getAllGraph();


private:
  std::string _save;
  std::string _libFolder;
  std::vector<std::string> _gameName;
  std::vector<std::string> _foundG;
  std::vector<std::string> _foundL;
  std::vector<std::size_t> _posG;
  std::vector<std::size_t> _posL;
  std::size_t _totalG;
  std::size_t _totalL;


protected:

};


#endif //  PARSER_HPP_
