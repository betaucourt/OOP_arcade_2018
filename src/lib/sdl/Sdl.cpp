/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sdl.cpp
*/

#include "../../Error.hpp"
#include <iostream>
#include "Sdl.hpp"
#include "../IGraph.hpp"

static bool compareSprite(std::pair<std::string, Entity*> first, std::pair<std::string, Entity*> second)
{
    return first.second->getZBuffer() < second.second->getZBuffer();
}

static bool compareText(std::pair<std::string, Text*> first, std::pair<std::string, Text*> second)
{
    return first.second->getZBuffer() < second.second->getZBuffer();
}

void Sdl::clearWindow()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(_renderer, NULL);
    SDL_RenderPresent(_renderer);
}

Sdl::Sdl() : _window(NULL), _fps(60), _frameDelay(1000/_fps)
{
    if (TTF_Init() == -1)
        throw Error("Impossible to create window : " + std::string(TTF_GetError()));
    _font = TTF_OpenFont("media/font/robot.ttf", 10);
    _colorFont = {255, 255, 255, 255};

    _frameStart = SDL_GetTicks();
    _frameTime = SDL_GetTicks() - _frameStart;
    _renderer = NULL;
}

Sdl::~Sdl()
{
}

TTF_Font *Sdl::getFont()
{
    return _font;
}

SDL_Color Sdl::getColor()
{
    return _colorFont;
}

void Sdl::setFont(int size)
{

}

void Sdl::openWindow()
{
    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow(
            "Arcade sdl",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            900,
            900,
            SDL_WINDOW_OPENGL
    );
    if (_window == NULL)
        throw Error("Impossible to create window : " + std::string(SDL_GetError()));
    _font = TTF_OpenFont("media/font/robot.ttf", 30);
    // frameStart = SDL_GetTicks();
}

void Sdl::closeWindow()
{
    if(_window) {
        SDL_DestroyWindow(_window);
        TTF_CloseFont(_font);
        TTF_Quit();
        SDL_Quit();
    }
}
#include <unistd.h>
void Sdl::displaySprite(std::vector<std::pair<std::string, Entity*>> entities)
{
    std::sort(entities.begin(), entities.end(), compareSprite);

    SDL_Surface* pSurface = NULL;
    pSurface = SDL_GetWindowSurface(_window);
    SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 0, 0, 0));
    for (auto entity : entities) {
        auto it = _textures.find(entity.second->getName());
        if (it == _textures.end())
            _textures[entity.second->getName()] = loadTexture(entity.second->getName());
        SDL_Rect dest = {static_cast<int>(entity.second->getPos().first * 30), static_cast<int>(entity.second->getPos().second * 30), 0, 0};
        _windowSprite = SDL_GetWindowSurface(_window);
        //sprite.setSize(2);
        //setScale(entity->getSize()); //pas sur du type
        if (!_windowSprite)
            throw Error("Impossible to create windowSprite for print a sprite : " + std::string(SDL_GetError()));
        SDL_BlitSurface(_textures[entity.second->getName()], NULL, _windowSprite, &dest);
        SDL_UpdateWindowSurface(_window);
    }
    _frameTime = SDL_GetTicks() - _frameStart;

    if (_frameDelay > _frameTime)
        SDL_Delay(_frameDelay - _frameTime);
}

void Sdl::displayText(std::vector<std::pair<std::string, Text*>> texts)
{
    std::sort(texts.begin(), texts.end(), compareText);

    for (auto entity : texts) {
        setFont(entity.second->getSize());
        auto text = TTF_RenderText_Blended(getFont(), entity.second->getText().c_str(), getColor());
        SDL_Rect dest = {entity.second->getPos().first * 30, entity.second->getPos().second * 30, 0, 0};
        SDL_Surface *windowSprite = SDL_GetWindowSurface(_window);
        if (!windowSprite)
            throw Error("Impossible to create windowSprite for print a sprite : " + std::string(SDL_GetError()));
        SDL_BlitSurface(text, NULL, windowSprite, &dest);
        SDL_UpdateWindowSurface(_window);
    }
}

Input Sdl::getInput()
{
    SDL_Event event;
    _frameStart = SDL_GetTicks();

    if (SDL_PollEvent(&event)) {
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
            return LEFT_CLICK;
        else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
            return RIGHT_CLICK;
        else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    return SPACE;
                case SDLK_UP:
                    return UP;
                case SDLK_DOWN:
                    return DOWN;
                case SDLK_RIGHT:
                    return RIGHT;
                case SDLK_LEFT:
                    return LEFT;
                case SDLK_RETURN:
                    return RETURN;
                case SDLK_b:
                    return PREVLIB;
                case SDLK_n:
                    return NEXTLIB;
                case SDLK_r:
                    return RESTART;
                case SDLK_o:
                    return PREVGAME;
                case SDLK_p:
                    return NEXTGAME;
                case SDLK_ESCAPE:
                    return QUIT;
                default:
                    return NONE;
            }
        }
        else
            return NONE;
    }
    return NONE;
}

// ISound *Sdl::loadSound(std::string path) const
// {
//       // Sound	*sound = new Sound;
//       // sound->load(path);
//       // return (sound);
// }

SDL_Surface* Sdl::loadTexture(std::string name)
{
    SDL_Surface *texture = SDL_LoadBMP(("media/pictures/" + name + ".bmp").c_str());

    if (!texture)
        throw Error("Impossible to access path : " + name);
    return texture;
}

extern "C" Sdl *entry()
{
    return new Sdl();
}
