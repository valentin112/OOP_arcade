/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.hpp
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../interface/IGames.hpp"

class Pacman: public IGames
{
    KeyEnum newKey;
    KeyEnum oldKey;
    std::vector<std::vector<int>> map;
    int score;
    bool can_eat_ghost;
    int still_eat;
    public:
        Pacman();
        ~Pacman();
        WinCondition Loop();
        std::vector<std::vector<int>> GetMap() const;
        int getScore() const;
        void getKey(KeyEnum);
        void initialization();
        void exit();
        std::string getName() const;
        WinCondition CheckWin() const;
        std::vector<int> getPlayerPosition() const;
        WinCondition movePlayer(int, int);
        void checkBoostPacman();
};

extern "C" IGames *constructor();

#endif