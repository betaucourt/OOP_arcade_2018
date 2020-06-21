/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sound.hpp
*/

#ifndef ARCADE_SOUND_SFML_HPP
#define ARCADE_SOUND_SFML_HPP

#include <SFML/Audio/Sound.hpp>
#include "../ISound.hpp"

class Sound : public ISound
{
public:
    Sound();
    ~Sound();
    void load(std::string path);
    void play();
    void replay();
    void pause();
    void loop();

    sf::Sound _sound;
};

#endif //ARCADE_SOUND_SFML_HPP
