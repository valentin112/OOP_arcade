/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** NCURSES.hpp
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "../../interface/IGraphicals.hpp"

class NCURSES: public IGraphicals
{
    bool _window;
    KeyEnum key;
    public:
        ~NCURSES() = default;
        NCURSES();
        bool is_mouse_clicked();
        void InitWindow();
        bool IsWindowOpen();
        void CloseWindow();
        void PrintBlock(const float, const float, Texture Texture);
        void PrintText(const float, const float, const int, const std::string &);
        void DisplayWindow();
        void ClearWindow();
        KeyEnum KeyPressed();
        std::vector<int> GetMousePosition();
        std::string GetPlayerUsername();
        void ProcessInput();
};

extern "C" IGraphicals *constructor();

#endif