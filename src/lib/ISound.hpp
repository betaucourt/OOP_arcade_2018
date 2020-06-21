/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** ISound.hpp
*/

#ifndef ISOUND_HPP
#define ISOUND_HPP

#include <string>
#include "../Input.hpp"

class ISound
{
    virtual void load(std::string name) = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void replay() = 0;
    virtual void loop() = 0;
};

#endif //ISOUND_HPP
