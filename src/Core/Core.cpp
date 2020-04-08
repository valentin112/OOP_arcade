/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "./Core.hpp"

Core::Core()
{
    std::string str("lib/lib_arcade_ncurses.so");
    lib.push_back(str);
    std::string str2("lib/lib_arcade_sfml.so");
    lib.push_back(str2);
    std::string str3("games/lib_arcade_pacman.so");
    games.push_back(str3);
    std::string str4("games/lib_arcade_nibbler.so");
    games.push_back(str4);
    name = "bob";
}

void Core::LoadLib()
{
    // DlLoader loader_sfml("lib/lib_arcade_sfml.so");
    // IGraphicals &sfml = loader_sfml.getInstance("constructor");
    DlLoader loader_ncurses("lib/lib_arcade_ncurses.so");
    IGraphicals &ncurses = loader_ncurses.getInstance("constructor");
    // DlLoader loader_sdl("lib/lib_arcade_sdl.so");
    // IGraphicals &sdl = loader_sdl.getInstance("constructor");
    // this->loaders.push_back(loader_sfml);
    // this->loaders.push_back(loader_ncurses);
    // this->loaders.push_back(loader_sdl);
    // this->libs.push_back(&sfml);
    // this->libs.push_back(&ncurses);
    // this->libs.push_back(&sdl);
}

void Core::init_fps()
{
    this->_pointA = std::chrono::system_clock::now();
    this->_pointB = std::chrono::system_clock::now();
}

int Core::getfps() const
{
    return(this->fps);
}

void Core::resetfps()
{
    this->fps = 0;
}

void Core::fps_gestion()
{
    this->_pointA = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> actual = this->_pointA - this->_pointB;

    if (actual.count() < 60) {
        std::chrono::duration<double, std::milli> delta_ms(60 -
                                                           actual.count());
        auto delta_ms_duration =
            std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delta_ms_duration.count()));
    }

    this->_pointB = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = this->_pointB - this->_pointA;
    this->fps = fps + (actual + sleep_time).count();
    // std::cout<<"fps: "<<this->fps<<std::endl;
}

Core::~Core()
{
}
