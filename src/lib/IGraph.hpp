/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** IGraph.hpp
*/

#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include <string>
#include <vector>
#include <utility>
#include "../Input.hpp"
#include "ISound.hpp"
#include "../games/Entity.hpp"
#include "../games/Text.hpp"

class IGraph
{
public:
    virtual ~IGraph() {};
    virtual void openWindow() = 0;
    virtual void closeWindow() = 0;
    virtual void displaySprite(std::vector<std::pair<std::string, Entity*>>) = 0;
    virtual void displayText(std::vector<std::pair<std::string, Text*>>) = 0;
    virtual Input getInput() = 0;
    // virtual ISound *loadSound(std::string path) const = 0;
    // virtual void putCircle(int radius, int posx, int posy) = 0;
    // virtual void putRectangle(int sizex, int sizey, int posx, int posy) = 0;
};

#endif //IGRAPH_HPP
