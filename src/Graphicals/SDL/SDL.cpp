/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** SDL.cpp
*/

#include "SDL.hpp"

SDL::SDL() : window{NULL}
{}

void SDL::InitWindow()
{
    SDL_Window *Nwindow;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    Nwindow = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    this->window = Nwindow;
    this->renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

bool SDL::IsWindowOpen()
{
    if (window == NULL) {
        this->_window == false;
        return false;
    }
    else
        this->_window = true;
    return (true);
}

void SDL::CloseWindow()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void SDL::PrintBlock(const float x, const float y, Texture texture)
{
    int ix = x, iy = y;

    SDL_Rect rect;
    rect.x = ix;
    rect.y = iy;
    rect.w = 25;
    rect.h = 25;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void SDL::PrintText(const float x, const float y, const int color, const std::string &str)
{
    int sizeX = 100, sizeY =100;

    if (TTF_Init() == -1)
        return; // Error handling idk
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("./res/arcade.TTF", 65);
    SDL_Color white = {255, 255, 255};
    char content[str.size() + 1];
    strcpy(content, str.c_str());
    SDL_Surface *surface = TTF_RenderText_Solid(font, content, white);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    while (TTF_SizeText(font, content, &sizeX, &sizeY) == -1)
        sizeX += 25;
        sizeY += 25;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = sizeX;
    rect.y = sizeY;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    TTF_CloseFont(font);
    TTF_Quit();
}

void SDL::DisplayWindow()
{
    SDL_RenderPresent(renderer);
}

void SDL::ClearWindow()
{
    SDL_RenderClear(renderer);
}

KeyEnum SDL::KeyPressed()
{
    return (_key);
}

void SDL::ProcessInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        printf("Event\n");
        switch (event.key.keysym.sym) {
            case SDLK_z:
                _key = UP;
                break;
            case SDLK_d:
                _key = RIGHT;
                break;
            case SDLK_s:
                _key = DOWN;
                break;
            case SDLK_q:
                printf("q\n");
                _key = LEFT;
                break;
            case SDLK_RETURN:
                _key = ENTER;
                break;
            case SDLK_SPACE:
                _key = SPACE;
                break;
            case SDLK_o:
                _key = SYS_PREVIOUS_GRAPHICAL_LIBRARY;
                break;
            case SDLK_p:
                _key = SYS_NEXT_GRAPHICAL_LIBRARY;
                break;
            case SDLK_l:
                _key = SYS_PREVIOUS_GAME;
                break;
            case SDLK_m:
                _key = SYS_NEXT_GAME;
                break;
            case SDLK_x:
                _key = SYS_RESTART;
                break;
            case SDLK_ESCAPE:
                _key = SYS_BACK_TO_MENU;
                break;
            case SDLK_w:
                _key = SYS_BACK_TO_MENU;
                break;
            default:
                break;
        }
        if (event.type == SDL_QUIT)
            _key = SYS_EXIT;
        else
            _key = UNDEFINED;
    }
}

bool SDL::is_mouse_clicked()
{
    return (true);
}

std::vector<int> SDL::GetMousePosition()
{
    std::vector<int> res; // a faire
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    res.push_back(x);
    res.push_back(y);
    return (res);
}

std::string SDL::GetPlayerUsername()
{
    return ("");
}

extern "C" IGraphicals *constructor()
{
    return new SDL;
}