/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sfml.cpp
*/

#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "../../Error.hpp"
#include <iostream>
#include "Sfml.hpp"
#include "../IGraph.hpp"

static bool compareSprite(std::pair<std::string, Entity*> first, std::pair<std::string, Entity*> second)
{
    return first.second->getZBuffer() < second.second->getZBuffer();
}

static bool compareText(std::pair<std::string, Text*> first, std::pair<std::string, Text*> second)
{
    return first.second->getZBuffer() < second.second->getZBuffer();
}

Sfml::Sfml() : _window(NULL)
{
    _font.loadFromFile("media/font/robot.ttf");
}

Sfml::~Sfml()
{
}

sf::Font Sfml::getFont()
{
    return _font;
}

void Sfml::openWindow()
{
    if (_window)
        delete _window;
    _window = new sf::RenderWindow(sf::VideoMode(900, 900), "Arcade sfml", sf::Style::Close);
    _window->setFramerateLimit(60);
}

void Sfml::closeWindow()
{
    if (_window) {
        _window->close();
        delete _window;
    }
}

void Sfml::displaySprite(std::vector<std::pair<std::string, Entity*>> entities)
{
    std::sort(entities.begin(), entities.end(), compareSprite);
    _window->clear();
    for (auto entity : entities) {
        auto it = _textures.find(entity.second->getName());
        if (it == _textures.end())
            _textures[entity.second->getName()] = loadTexture(entity.second->getName());
        sf::Texture texture = _textures[entity.second->getName()];
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(entity.second->getPos().first * 30 + entity.second->getSize().first / 2, entity.second->getPos().second * 30 + entity.second->getSize().second / 2);
        sprite.setOrigin(entity.second->getSize().first / 2, entity.second->getSize().second / 2);
        sprite.setRotation(entity.second->getAngle());
        _window->draw(sprite);
    }
}

void Sfml::displayText(std::vector<std::pair<std::string, Text*>> texts)
{
    std::sort(texts.begin(), texts.end(), compareText);

    for (auto entity : texts) {
        std::cout << entity.second->getSize() << '\n';
        sf::Text text;
        text.setFont(_font);
        text.setCharacterSize(entity.second->getSize());
        text.setPosition(entity.second->getPos().first * 30, entity.second->getPos().second * 30);
        text.setFillColor(sf::Color::White);
        text.setString(entity.second->getText());
        _window->draw(text);
    }
    _window->display();
}

Input Sfml::getInput()
{
    sf::Event event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return LEFT_CLICK;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        return RIGHT_CLICK;
    if (_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Return)
                    return RETURN;
                if (event.key.code == sf::Keyboard::Space)
                    return SPACE;
                if (event.key.code == sf::Keyboard::Right)
                    return RIGHT;
                if (event.key.code == sf::Keyboard::Left)
                    return LEFT;
                if (event.key.code == sf::Keyboard::Up)
                    return UP;
                if (event.key.code == sf::Keyboard::Down)
                    return DOWN;
                if (event.key.code == sf::Keyboard::B)
                    return PREVLIB;
                if (event.key.code == sf::Keyboard::N)
                    return NEXTLIB;
                if (event.key.code == sf::Keyboard::R)
                    return RESTART;
                if (event.key.code == sf::Keyboard::O)
                    return PREVGAME;
                if (event.key.code == sf::Keyboard::P)
                    return NEXTGAME;
                if (event.key.code == sf::Keyboard::Escape)
                    return QUIT;
                else
                    return NONE;
            default:
                return NONE;
        }
    }
    return NONE;
}

// ISound *Sfml::loadSound(std::string path) const
// {
//       Sound	*sound = new Sound;
//       sound->load(path);
//       return (sound);
// }

// void Sfml::putCircle(int radius, int posx, int posy)
// {
//     sf::CircleShape circle;
//     circle.setRadius(150);
//     circle.setPosition(posx, posy);
//     circle.setColor(sf::Color::Red);
//     _window.draw(circle);
// }
//
// void Sfml::putRectangle(int sizex, int sizey, int posx, int posy)
// {
//     static_cast<T>(&sizex);
//     static_cast<T>(&sizey);
//     sf::RectangleShape rect(sf::Vector2f(sizex, sizey));
//     rect.setPosition(posx, posy);
//     rect.setColor(sf::Color::Red);
//     _window.draw(rect);
// }

sf::Texture Sfml::loadTexture(std::string name)
{
    sf::Texture texture;

    if (!texture.loadFromFile("media/pictures/" + name + ".png"))
        throw Error("Impossible to access path : media/pictures/" + name+ ".png");
    return texture;
}

extern "C" Sfml *entry()
{
    return new Sfml();
}
