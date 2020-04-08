/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** NCURSES.cpp
*/

#include "NCURSES.hpp"

NCURSES::NCURSES(): _window(false), key(UNDEFINED)
{}

void NCURSES::InitWindow()
{
    initscr();
    _window = true;
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

bool NCURSES::IsWindowOpen()
{
// check if stdscr et curscr ont des valeur 
// sinon faire avec une data bool
    return (true);
}

void NCURSES::CloseWindow()
{
    endwin();
}

void NCURSES::PrintBlock(const float x, const float y, Texture Texture)
{
    if (Texture == 0)
        mvprintw(y, x, "o");
    if (Texture == 1)
        mvprintw(y, x, "X");
    if (Texture == 2)
        mvprintw(y, x, " ");
    if (Texture == 3)
        mvprintw(y, x, ".");
    if (Texture == 4)
        mvprintw(y, x, ":");
    if (Texture == 5)
        mvprintw(y, x, "F");
    if (Texture == 6)
        mvprintw(y, x, "F");
    if (Texture == 7)
        mvprintw(y, x, "F");
    if (Texture == 8)
        mvprintw(y, x, " ");
}

void NCURSES::PrintText(const float x, const float y, const int color, const std::string &str)
{
    mvprintw(y, x, str.c_str());
}

void NCURSES::DisplayWindow()
{
    refresh();
}

void NCURSES::ClearWindow()
{
    erase();
}

KeyEnum NCURSES::KeyPressed()
{
    return (key);
}

void NCURSES::ProcessInput()
{
    int c = getch();
    if (c == -1)
        return;
    if (c == 90 || c == 122 || c == KEY_UP)
        key = UP;
    if (c == 81 || c == 113 || c == KEY_LEFT)
        key = LEFT;
    if (c == 83 || c == 115 || c == KEY_DOWN)
        key = DOWN;
    if (c == 68 || c == 100 || c == KEY_RIGHT)
        key = RIGHT;
    if (c == 76 || c == 108)
        key = SYS_PREVIOUS_GAME;
    if (c == 77 || c == 109)
        key = SYS_NEXT_GAME;
    if (c == 32)
        key = SYS_BACK_TO_MENU;
}

std::vector<int> NCURSES::GetMousePosition()
{
    std::vector<int> res;
    return (res);
}

std::string NCURSES::GetPlayerUsername()
{
    return ("bob");
}

bool NCURSES::is_mouse_clicked()
{
    return (false);
}

extern "C" IGraphicals *constructor()
{
    return new NCURSES;
}