/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_
#include <iostream>
#include <vector>
#include "Key.hpp"

/// Used by the core to check the state of the game
///
enum WinCondition {
    WIN,
    LOSE,
    NOT_ENDED
};

/*!
    Game interface
*/
class IGames {
public:
    virtual ~IGames() = default;
    virtual void initialization() = 0;
    virtual void exit() = 0;
    virtual WinCondition Loop() = 0;
    virtual std::vector<std::vector<int>> GetMap() const = 0;
    virtual int getScore() const = 0;
    virtual void getKey(KeyEnum) = 0;
    virtual std::string getName() const = 0;

protected:
private:
};

#endif /* !IGAMES_HPP_ */