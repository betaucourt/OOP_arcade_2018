/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** game interface
*/

#ifndef IGAME_H
#define IGAME_H

#include <vector>
#include <map>
#include "../lib/IGraph.hpp"
#include "../Input.hpp"
#include "../games/Entity.hpp"

class IGame
{
public:
    virtual int compute(Input input) = 0;
};

class AGame : public IGame
{
public:
    virtual int compute(Input input) = 0;
    Entity *findEntity(std::string);
    std::vector<Input> getControls() const;
    std::vector<std::pair<std::string, Entity*>> getEntities() const;
    std::vector<std::pair<std::string, Text*>> getTexts() const;

protected:
    int _score;
    std::vector<Input> _controls;
    std::vector<std::pair<std::string, Entity*>> _entities;
    std::vector<std::pair<std::string, Text*>> _texts;
};

#endif
