/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Core/Core.hpp"

// bool check_file(char *file)
// {
//     std::string res;
//     std::stringstream ss;

//     ss << file;
//     res = ss.str();
//     if (res.substr(res.find_last_of(".") + 1) != "so") {
//         std::cerr << "Invalid argument." << std::endl;
//         return (false);
//     }
//     return (true);
// }

void display(std::vector<std::vector<int>> map, IGraphicals &lib)
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            lib.PrintBlock(i, j, static_cast<Texture>(map[i][j]));
        }
    }
}

WinCondition gameLoop(IGraphicals &lib, Core &core, IGames &game)
{
    game.initialization();
    core.init_fps();
    KeyEnum key;
    WinCondition check = NOT_ENDED;
    while (check == NOT_ENDED) {
        lib.ClearWindow();
        display(game.GetMap(), lib);
        lib.PrintText(25, 25,2, std::to_string(game.getScore()));
        lib.DisplayWindow();
        lib.ProcessInput();
        key = lib.KeyPressed();
        if (key == SYS_BACK_TO_MENU)
            return (NOT_ENDED);
        game.getKey(key);
        if (core.getfps()> 100) {
            check = game.Loop();
            core.resetfps();
        }
        if (lib.KeyPressed() == SYS_EXIT) {
            lib.CloseWindow();
            break;
        }
        core.fps_gestion();
    }
    return (check);
}

std::string getGameName(std::string str)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    std::string dest;

    while (tmp < str.length()) {
        if (str[tmp] == '.')
            j = tmp;
        if (str[tmp] == '_')
            i = tmp;
        tmp++;
    }
    while (i + 1 < j) {
        dest += str[i + 1];
        i++;
    }
    return (dest);
}

void menu(std::string str)
{
    DlLoader loader_lib(str);
    DlLoader loader_game("games/lib_arcade_pacman.so");
    DlLoader loader_game2("games/lib_arcade_nibbler.so");
    auto core = new Core();
    IGraphicals &lib = loader_lib.getInstance("constructor");
    IGames &game1 = loader_game.getGame("constructor");
    IGames &game2 = loader_game2.getGame("constructor");
    lib.InitWindow();
    KeyEnum key;
    while (1) {
        lib.ClearWindow();
        lib.PrintText(0, 0, 2, "WELCOME TO OUR ARCADE");
        lib.PrintText(1, 0, 2, "CHOOSE A GAME");
        lib.PrintText(2, 0, 2, getGameName(core->getGames()[0]));
        lib.PrintText(2, 10, 2, getGameName(core->getGames()[1]));
        lib.DisplayWindow();
        lib.ProcessInput();
        key = lib.KeyPressed();
        if (key == SYS_EXIT)
            break;
        if (key == SYS_PREVIOUS_GAME) {
            gameLoop(lib, *core, game1);
        }
        if (key == SYS_NEXT_GAME) {
            gameLoop(lib, *core, game2);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Arcade takes 1 lib as argument" << std::endl;
        return (84);
    }
    std::string str(av[1]);
    menu(str);
    return (0);
}