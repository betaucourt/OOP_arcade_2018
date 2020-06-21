/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** text manager
*/

#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include <utility>

class Text
{
public:
    Text(std::string, std::pair<int, int>, float, int);
    Text(Text &);
    ~Text();

    std::string getText() const;
    void setText(std::string);
    std::pair<int, int> getPos() const;
    void setPos(std::pair<int, int>);
    float getZBuffer() const;
    void setZBuffer(float);
    void setSize(int);
    int getSize();

private:
    std::string _text;
    std::pair<int, int> _pos;
    int _zBuffer;
    int _size;
};

#endif
