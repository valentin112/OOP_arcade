/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** SDL.hpp
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_ttf.h>
#include "../../interface/IGraphicals.hpp"

class SDL: public IGraphicals
{
    bool _window;
    public:
        SDL();
        ~SDL();
        void InitWindow();
        bool IsWindowOpen();
        void CloseWindow();
        void PrintBlock(const float, const float, Texture);
        void PrintText(const float, const float, const int, const std::string &);
        void DisplayWindow();
        void ClearWindow();
        void ProcessInput();
        bool is_mouse_clicked();
        KeyEnum KeyPressed();
        std::vector<int> GetMousePosition();
        std::string GetPlayerUsername();
    private:
        KeyEnum _key;
        SDL_Window *window;
        SDL_Renderer* renderer;
};

extern "C" IGraphicals *constructor();

#endif