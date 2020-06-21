/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** solarfox content
*/

#include "Solarfox.hpp"
#include "Vessel.hpp"

extern "C" Solarfox* entry()
{
    return new Solarfox();
}

Solarfox::Solarfox()
{
    _player = new Vessel("player", std::make_pair(14, 14), Vessel::UP, 2);
    _foes.push_back(new Vessel("foe1", std::make_pair(0, 0), Vessel::RIGHT, 100));
    _foes.push_back(new Vessel("foe2", std::make_pair(29, 29), Vessel::LEFT, 100));
    _controls = {Input::UP, Input::DOWN, Input::RIGHT, Input::LEFT, Input::SPACE, Input::RETURN};
    _entities.push_back(std::make_pair("player", new Entity("mainVessel", std::make_pair(14, 14), std::make_pair(30, 30), 10)));
    _entities.push_back(std::make_pair("foe1", new Entity("vesselEnnemi", std::make_pair(0, 0), std::make_pair(30, 30), 10)));
    _entities.push_back(std::make_pair("foe2", new Entity("vesselEnnemi", std::make_pair(29, 29), std::make_pair(30, 30), 10)));
    _score = 0;
    setItems();
}

Solarfox::~Solarfox()
{
    delete _player;
    for (auto foe : _foes)
        delete foe;
    for (auto pair : _entities)
        delete pair.second;
}

void Solarfox::setItems()
{
    srand(time(NULL));

    std::string item = "item";
    for (int i = 0 ; i < 10 ; i++) {
        int x = rand() % 28 + 1;
        int y = rand() % 28 + 1;
        _items.push_back(std::make_pair(item + std::to_string(i), std::make_pair(x, y)));
        _entities.push_back(std::make_pair(item + std::to_string(i), new Entity("target", std::make_pair(x, y), std::make_pair(30, 30), 5)));
    }
}

void Solarfox::controlFoes()
{
    for (Vessel *foe : _foes) {
        if (foe->getPos().first == 1)
            foe->setDirectionBuf(Vessel::Direction::RIGHT);
        if (foe->getPos().first == 28)
            foe->setDirectionBuf(Vessel::Direction::LEFT);
        foe->forward(findEntity(foe->getName()));
        foe->shoot(_player->getPos());
    }
}

int Solarfox::compute(Input input)
{
    if (input == Input::RETURN)
        _player->shoot();
    else if (input + _player->getDirection() != 0 && input != NONE)
        _player->setDirectionBuf(static_cast<Vessel::Direction>(input));
    if (_player->forward(findEntity(std::string("player"))))
        return -2;
    for (std::vector<std::pair<std::string, std::pair<int , int>>>::iterator item = _items.begin() ; item != _items.end() ; item++)
        if (item->second.first == _player->getPos().first && item->second.second == _player->getPos().second) {
            for (std::vector<std::pair<std::string, Entity*>>::iterator entity = _entities.begin() ; entity != _entities.end() ; entity++)
                if (entity->first == item->first) {
                    _entities.erase(entity);
                    break;
                }
            _items.erase(item);
            _score += 100;
            break;
        }
    controlFoes();
    if (!_items.size()) {
        std::cout << "gagné" << '\n';
        return -1;
    }
    return _score;
}
