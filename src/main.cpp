/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include <iostream>
#include "Error.hpp"
#include "core/core.hpp"
#include <dlfcn.h>
//#include "games/IGame.hpp"

void usage(void)
{
    std::cout << "USAGE\n\t./arcade library_path\n\nDESCRIPTION\n\tlibrary_path\tgraphical library used at launch" << std::endl;
}

int main(int ac, char **av)
{
  /*Core *core = new Core(av);
  std::vector<std::string> test = core->_parser.getGames();

  std::vector<std::string> test2 = core->_parser.getGraph();
  std::size_t max = test.size();
  std::size_t max2 = test2.size();

  for(std::size_t i = 0; i != max; i++) {
    std::cout << "Game N°" << i << " = " << test.at(i) << std::endl;
  }
  for(std::size_t i = 0; i != max2; i++) {
    std::cout << "Graph N°" << i << " = " << test2.at(i) << std::endl;
  }
  core->run();*/
  srand (time(NULL));
    if (ac != 2) {
        usage();
        return 84;
    }
    try {
        Core *core = new Core(av);
        core->run();
    }
    catch (Error &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
}
