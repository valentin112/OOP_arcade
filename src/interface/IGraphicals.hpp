/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphicals
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_
#include <iostream>
#include <vector>
#include "Texture.hpp"
#include "Key.hpp"

/*!
    Graphical interface
*/
class IGraphicals {
public:
    virtual void ProcessInput() = 0; // NOUVEAUX STOCK LE TYPE DE KEY DANS UNE VARIABLE
    virtual void InitWindow() = 0; //create window
    virtual bool IsWindowOpen() = 0; //verifie si la window est open
    virtual void CloseWindow() = 0; // ferme la window
    virtual void PrintBlock(const float, const float, Texture texture) = 0; // print un block(x, y, le block a afficher)        UTILISE L ENUM TEXTURE AU LIEU D UN INT
    virtual void PrintText(const float, const float, const int, 
                           const std::string &) = 0; // print text (x, y, sert a rien, text a ecrire)
    virtual void DisplayWindow() = 0; //affiche la window
    virtual void ClearWindow() = 0; // window refresh
    virtual bool is_mouse_clicked() = 0; // NOUVEAU
    virtual KeyEnum KeyPressed() = 0; // pour avoir les inputs        LE NOM A CHANGE RETURN LE TYPE DE KEY
    virtual std::vector<int> GetMousePosition() = 0; // position de la souris
    virtual std::string GetPlayerUsername() = 0; // TU SAIS LIRE

protected:
private:
};

#endif