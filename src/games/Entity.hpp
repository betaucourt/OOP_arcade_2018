/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** entity manager
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <utility>

class Entity
{
public:
    Entity(std::string, std::pair<float, float>, std::pair<float, float>, float);
    Entity(Entity &);
    ~Entity();

    std::string getName() const;
    void setName(std::string);
    std::pair<float, float> getPos() const;
    void setPos(std::pair<float, float>);
    std::pair<float, float> getSize() const;
    void setSize(std::pair<float, float>);
    float getAngle() const;
    void setAngle(float angle);
    float getZBuffer() const;
    void setZBuffer(float);

private:
    std::string _name;
    std::pair<float, float> _pos;
    std::pair<float, float> _size;
    float _angle;
    int _zBuffer;
};

#endif
