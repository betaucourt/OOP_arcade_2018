/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame content
*/

#include "IGame.hpp"

std::vector<Input> AGame::getControls() const
{
    return _controls;
}

std::vector<std::pair<std::string, Entity*>> AGame::getEntities() const
{
    return _entities;
}

std::vector<std::pair<std::string, Text*>> AGame::getTexts() const
{
    return _texts;
}

Entity *AGame::findEntity(std::string name)
{
    for (std::pair<std::string, Entity*> pair : _entities) {
        if (pair.first == name)
            return pair.second;
    }
    return nullptr;
}
