/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DlLoader
*/

#include "DlLoader.hpp"
using func = IGraphicals*(*)();
using game = IGames*(*)();

DlLoader::DlLoader(std::string const &path)
{
    _path = path;
    _handle = dlopen(_path.c_str(), RTLD_LAZY);
    if (_handle == NULL) {
        std::cerr<<dlerror()<<std::endl;
        std::exit(84);
    }
}

DlLoader::~DlLoader()
{
    if (_handle != NULL)
        if (dlclose(_handle) != 0) {
            std::cout << "Error" << std::endl;
            std::exit(84);
        }
}

IGraphicals &DlLoader::getInstance(std::string entry_point)
{
    func desk;
    desk = (func)dlsym(_handle, entry_point.c_str());
    if ((_error = dlerror()) != NULL)  {
        fputs(_error, stderr);
        exit(84);
    }
    auto lib = desk();
    return *lib;
}

IGames &DlLoader::getGame(std::string entry_point)
{
    game desk;
    desk = (game)dlsym(_handle, entry_point.c_str());
    if ((_error = dlerror()) != NULL)  {
        fputs(_error, stderr);
        exit(84);
    }
    auto lib = desk();
    return *lib;
}