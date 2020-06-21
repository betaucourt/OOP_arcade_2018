/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** text content
*/

#include "Text.hpp"

Text::Text(std::string text, std::pair<int, int> pos, float zBuffer, int size) :
_text(text), _pos(pos), _zBuffer(zBuffer), _size(size)
{
}

Text::Text(Text &other) : _text(other.getText()), _pos(other.getPos()), _zBuffer(other.getZBuffer())
{
}

Text::~Text()
{
}

std::string Text::getText() const
{
    return _text;
}

void Text::setText(std::string text)
{
    _text = text;
}

std::pair<int, int> Text::getPos() const
{
    return _pos;
}

void Text::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

float Text::getZBuffer() const
{
    return _zBuffer;
}

void Text::setZBuffer(float zBuffer)
{
    _zBuffer = zBuffer;
}

int Text::getSize()
{
    return _size;
}

void Text::setSize(int size)
{
    _size = size;
}
