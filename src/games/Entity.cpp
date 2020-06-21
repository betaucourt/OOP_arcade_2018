/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** entity content
*/

#include "Entity.hpp"

Entity::Entity(std::string name, std::pair<float, float> pos,std::pair<float, float> size, float zBuffer) :
_name(name), _pos(pos), _size(size), _angle(0.0), _zBuffer(zBuffer)
{
}

Entity::Entity(Entity &other) : _name(other.getName()), _pos(other.getPos()), _zBuffer(other.getZBuffer())
{
}

Entity::~Entity()
{
}

std::string Entity::getName() const
{
    return _name;
}

void Entity::setName(std::string name)
{
    _name = name;
}

std::pair<float, float> Entity::getPos() const
{
    return _pos;
}

void Entity::setPos(std::pair<float, float> pos)
{
    _pos = pos;
}

std::pair<float, float> Entity::getSize() const
{
    return _size;
}

void Entity::setSize(std::pair<float, float> size)
{
    _size = size;
}

float Entity::getAngle() const
{
    return _angle;
}

void Entity::setAngle(float angle)
{
    _angle = angle;
}

float Entity::getZBuffer() const
{
    return _zBuffer;
}

void Entity::setZBuffer(float zBuffer)
{
    _zBuffer = zBuffer;
}
