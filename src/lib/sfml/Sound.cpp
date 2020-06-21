/*
** EPITECH PROJECT, 2017
** Arcade
** File description:
** Sound.cpp
*/

#include <SFML/Audio/SoundBuffer.hpp>
#include "../../Error.hpp"
#include "Sound.hpp"

Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::load(std::string name)
{
    sf::SoundBuffer	audioBuffer;

    if (!audioBuffer.loadFromFile(name))
        throw Error("Can't find/open sound file " + name);
    _sound.setBuffer(audioBuffer);
}

void Sound::play() {
    _sound.play();
}

void Sound::replay() {
    _sound.stop();
    play();
}

void Sound::pause() {
    _sound.pause();
}

void Sound::loop() {
    _sound.stop();
    _sound.setLoop(true);
    play();
}
