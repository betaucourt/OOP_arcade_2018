/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sdl.hpp
*/

#ifndef ARCADE_SDL_HPP
#define ARCADE_SDL_HPP

#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../IGraph.hpp"


class Sdl : public IGraph
{
public:
    Sdl();
    ~Sdl();

    void openWindow();
    void closeWindow();
    void displaySprite(std::vector<std::pair<std::string, Entity*>>);
    void displayText(std::vector<std::pair<std::string, Text*>>);
    Input getInput();
    // virtual ISound *loadSound(std::string path) const;
    // void putCircle(int radius, int posx, int posy);
    // void putRectangle(int sizex, int sizey, int posx, int posy);
    SDL_Surface *loadTexture(std::string name);
    void setFont(int);
    TTF_Font *getFont();
    SDL_Color getColor();


    SDL_Window *_window;
    SDL_Surface *_windowSprite;
    SDL_Renderer *_renderer;
    TTF_Font *_font;
    SDL_Color _colorFont;

private:
    std::map<std::string, SDL_Surface* > _textures;
    const int _fps;
    const int _frameDelay;

    Uint32 _frameStart;
    int _frameTime;

    void clearWindow();
};

#endif //ARCADE_SDL_HPP
