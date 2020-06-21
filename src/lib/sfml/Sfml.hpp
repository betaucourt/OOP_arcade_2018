/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sfml.hpp
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <vector>
#include <utility>
#include <map>
#include <SFML/Graphics.hpp>
#include "../IGraph.hpp"
#include "Sound.hpp"

class Sfml : public IGraph
{
public:
    Sfml();
    ~Sfml();

    void openWindow();
    void closeWindow();
    void displaySprite(std::vector<std::pair<std::string, Entity*>>);
    void displayText(std::vector<std::pair<std::string, Text*>>);
    Input getInput();
    // virtual ISound *loadSound(std::string path) const;
    // void putCircle(int radius, int posx, int posy);
    // void putRectangle(int sizex, int sizey, int posx, int posy);
    sf::Texture loadTexture(std::string name);
    sf::Font getFont();

    sf::RenderWindow *_window;
    sf::Font _font;

private:
    std::map<std::string, sf::Texture> _textures;
};

#endif //ARCADE_SFML_HPP
