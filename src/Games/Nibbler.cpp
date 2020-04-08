/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Nibbler.cpp
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

void Nibbler::initialization()
{
    newKey = UNDEFINED;
    score = 0;
    map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1});
    map.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    player_pos = {{10, 9}};
    player_pos.push_back({11, 9});
    player_pos.push_back({12, 9});
    player_pos.push_back({13, 9});
}

void Nibbler::exit()
{

}

void Nibbler::movePlayer(int x, int y)
{
    int i = 1;
    std::vector<int> tmp = {player_pos[0][0], player_pos[0][1]};
    std::vector<int> tmp2;
    map[x][y] = 0;
    player_pos[0][0] = x;
    player_pos[0][1] = y;
    while (i < player_pos.size()) {
        tmp2 = player_pos[i];
        player_pos[i] = tmp;
        map[tmp[0]][tmp[1]] = 0;
        tmp = tmp2;
    }
    map[tmp[0]][tmp[1]] = 2;
}

WinCondition Nibbler::Loop()
{
    int first_x = player_pos[0][0];
    int first_y = player_pos[0][1];

    score += 1;
    if (newKey == UNDEFINED)
        return (NOT_ENDED);
    if (newKey == DOWN)
        first_x += 1;
    if (newKey == UP)
        first_x -= 1;
    if (newKey == RIGHT)
        first_y += 1;
    if (newKey == LEFT)
        first_y -= 1;
    if (map[first_x][first_y] == 1 || map[first_x][first_y] == 0)
        return (LOSE);
    if (map[first_x][first_y] == 2) {
        movePlayer(first_x, first_y);
    }
    return (NOT_ENDED);
}

std::vector<std::vector<int>> Nibbler::GetMap() const
{
    return (map);
}


int Nibbler::getScore() const
{
    return (score);
}

std::string Nibbler::getName() const
{
    return ("bob");
}

void Nibbler::getKey(KeyEnum key)
{
    if (key != UNDEFINED)
        newKey = key;
}

extern "C" IGames *constructor()
{
    return new Nibbler;
}
// map
// 0 -> player
// 1 -> block
// 2 -> espace vide
// 3 -> point mangable
// 4 -> point pour manger fantome
// 5 -> fantome sur 2
// 6 -> fantome sur 3
// 7 -> fantome sur 4
// 8 -> ouverture de la map
