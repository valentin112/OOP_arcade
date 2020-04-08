/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../../interface/IGraphicals.hpp"

class SFML : public IGraphicals
{
    public:
        SFML();
        ~SFML();

        void InitWindow();
        bool IsWindowOpen();
        void CloseWindow();
        void PrintBlock(const float, const float, Texture); // TEXTURE
        void PrintText(const float, const float, const int, const std::string &);
        void DisplayWindow();
        void ClearWindow();
        void ProcessInput(); // NEW
        bool is_mouse_clicked(); // NOUVEAU
        KeyEnum KeyPressed(); //NEW
        std::vector<int> GetMousePosition();
        std::string GetPlayerUsername();

        sf::RenderWindow _window;
        sf::Event _event;
        KeyEnum _key;
};

extern "C" IGraphicals *constructor();

#endif /* !SFML_HPP_ */