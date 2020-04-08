/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

void Pacman::initialization()
{
    newKey = UNDEFINED;
    oldKey = UNDEFINED;
    score = 0;
    can_eat_ghost = false;
    still_eat = 0;
    map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    map.push_back({1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1});
    map.push_back({1, 4, 1, 1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1, 1, 4, 1});
    map.push_back({1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1});
    map.push_back({1, 3, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 3, 1});
    map.push_back({1, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 1});
    map.push_back({1, 1, 1, 3, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 3, 1, 1, 1});
    map.push_back({1, 1, 1, 3, 1, 3, 3, 3, 3, 1, 3, 3, 3, 3, 1, 3, 1, 1, 1});
    map.push_back({8, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 8});
    map.push_back({1, 1, 1, 3, 1, 3, 3, 3, 3, 1, 3, 3, 3, 3, 1, 3, 1, 1, 1});
    map.push_back({1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1});
    map.push_back({1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1});
    map.push_back({1, 3, 1, 1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1, 1, 3, 1});
    map.push_back({1, 4, 3, 1, 3, 3, 3, 3, 3, 0, 3, 3, 3, 1, 3, 3, 3, 4, 1});
    map.push_back({1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1});
    map.push_back({1, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 1});
    map.push_back({1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1});
    map.push_back({1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1});
    map.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
}

void Pacman::exit()
{

}

std::vector<int> Pacman::getPlayerPosition() const
{
    std::vector<int> pos;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 0) {
                pos.push_back(i);
                pos.push_back(j);
                return (pos);
            }
        }
    }
    return (pos);
}

void Pacman::checkBoostPacman()
{
    if (can_eat_ghost) {
        if (still_eat == 0) {
            can_eat_ghost = false;
        } else {
            still_eat -= 1;
        }
    }
}

WinCondition Pacman::movePlayer(int x, int y)
{
    int old_x = x;
    int old_y = y;

    if (newKey == UNDEFINED)
        return (NOT_ENDED);
    if (newKey == DOWN)
        x += 1;
    if (newKey == UP)
        x -= 1;
    if (newKey == RIGHT)
        y += 1;
    if (newKey == LEFT)
        y -= 1;
    if (map[x][y] == 1)
        return (NOT_ENDED);
    if (map[x][y] == 2) {
        map[x][y] = 0;
        map[old_x][old_y] = 2;
        return (NOT_ENDED);
    }
    if (map[x][y] == 3) {
        map[x][y] = 0;
        map[old_x][old_y] = 2;
        score += 5;
        return (NOT_ENDED);
    }
    if (map[x][y] == 4) {
        map[x][y] = 0;
        map[old_x][old_y] = 2;
        can_eat_ghost = true;
        still_eat += 25;
        return (NOT_ENDED);
    }
    if (map[x][y] == 5) {
        if (can_eat_ghost) {
            map[x][y] = 0;
            map[old_x][old_y] = 2;
            score += 50;
            return (NOT_ENDED);
        } else
        return (LOSE);
    }
    if (map[x][y] == 0) {
        if (can_eat_ghost) {
            map[x][y] = 0;
            map[old_x][old_y] = 3;
            score += 50;
            return (NOT_ENDED);
        } else
        return (LOSE);
    }
    if (map[x][y] == 7) {
        if (can_eat_ghost) {
            map[x][y] = 0;
            map[old_x][old_y] = 4;
            score += 50;
            return (NOT_ENDED);
        } else
        return (LOSE);
    }
    if (map[x][y] == 8) {
        if (y == 0) {
            map[old_x][old_y] = 2;
            map[x][map[x].size() - 2] = 0;
            newKey = LEFT;
            oldKey = LEFT;
        } else {
            map[old_x][old_y] = 2;
            map[x][1] = 0;
            newKey = RIGHT;
            oldKey = RIGHT;
        }
    }
    return (NOT_ENDED);
}

WinCondition Pacman::Loop()
{
    std::vector<int> pos;

    checkBoostPacman();
    pos = getPlayerPosition();
    if (pos.size() == 0)
        return (LOSE);
    WinCondition ret = movePlayer(pos[0], pos[1]);
    if (ret == LOSE)
        return (LOSE);
    return (CheckWin());
}

std::vector<std::vector<int>> Pacman::GetMap() const
{
    return (map);
}

WinCondition Pacman::CheckWin() const
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 3 || map[i][j] == 4)
                return (NOT_ENDED);
        }
    }
    return (WIN);
}

int Pacman::getScore() const
{
    return (score);
}

std::string Pacman::getName() const
{
    return ("bob");
}

void Pacman::getKey(KeyEnum key)
{
    if (key != UNDEFINED)
       oldKey = newKey;
        newKey = key;
}

extern "C" IGames *constructor()
{
    return new Pacman;
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


// std::vector<std::vector<int>> get_map(char const *path)
// {
//     std::ifstream infile(path);
//     std::string line;
//     std::vector<std::vector<int>> map;
//     std::vector<int> tmp;

//     while (std::getline(infile, line)) {
//         for (int i = 0; i < line.length(); i++) {
//             if (line[i] == '1')
//                 tmp.push_back(1);
//             if (line[i] == '3')
//                 tmp.push_back(3);
//             if (line[i] == '4')
//                 tmp.push_back(4);
//             if (line[i] == '6')
//                 tmp.push_back(6);
//         }
//         map.push_back(tmp);
//         tmp.clear();
//     }
//     return (map);
// }

