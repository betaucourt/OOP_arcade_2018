/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** inpput header
*/

#ifndef INPUT_H
#define INPUT_H

enum Input {
    SPACE,
    PREVLIB,
    NEXTLIB,
    RESTART,
    PREVGAME,
    NEXTGAME,
    RIGHT_CLICK,
    LEFT_CLICK,
    RETURN,
    QUIT,
    NONE,
    ACTION,
    DOWN,
    UP = -1 * DOWN,
    RIGHT,
    LEFT = -1 * RIGHT
};

// SPACE : when key space is released
// PREVLIB : when key b is released
// NEXTLIB : when key n is released
// RESTART : when key r is released
// PREVGAME : when key o is released
// NEXTGAME : when key p is released
// RIGHT_CLICK : when right click of mouth is released
// LEFT_CLICK : when left click of mouth is released
// RETURN : when key enter/return is released
// DOWN : when key down is released
// UP : when key up is released
// LEFT : when key left is released
// RIGHT : when key right is released
// NONE : when nothing or other event happen

#endif
