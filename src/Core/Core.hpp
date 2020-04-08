/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/
// #include "../interface/IGraphicals.hpp"
// #include "../interface/IGames.hpp"


#ifndef CORE_HPP_
#define CORE_HPP_
#include "./Loader/DlLoader.hpp"
#include <chrono>
#include <thread>

class Core {
    public:
        Core();
        ~Core();
        void LoadLib();
        void fps_gestion();
        void init_fps();
        int getfps() const;
        void resetfps();
        std::vector<std::string> getGames() const { return (games);};
    protected:
    private:
        std::chrono::system_clock::time_point _pointA;
        std::chrono::system_clock::time_point _pointB;
        int fps;
        std::vector<std::string> lib;
        std::vector<std::string> games;
        std::string name;        
        // std::vector<DlLoader> loaders;
        // std::vector<IGraphicals *> libs;
        
};

#endif /* !CORE_HPP_ */
