/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** solarfox header
*/

#ifndef SOLARFOX_H
#define SOLARFOX_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "../IGame.hpp"
#include "../../Input.hpp"
#include "Vessel.hpp"

class Solarfox : public AGame
{
public:
    Solarfox();
    ~Solarfox();

    int compute(Input);
    void controlFoes();
    void setItems();

private:
    Vessel *_player;
    std::vector<Vessel *> _foes;
    std::vector<std::pair<std::string, std::pair<int, int>>> _items;
};

#endif
