/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Nibbler.hpp
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../interface/IGames.hpp"

class Nibbler: public IGames
{
    KeyEnum newKey;
    int score;
    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> player_pos;
    public:
        Nibbler();
        ~Nibbler();
        void initialization();
        void exit();
        WinCondition Loop();
        std::vector<std::vector<int>> GetMap() const;
        int getScore() const;
        void getKey(KeyEnum);
        std::string getName() const;
        void movePlayer(int, int);
};

extern "C" IGames *constructor();

#endif