/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DlLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include <dlfcn.h>
#include <iostream>
#include <stdio.h>
#include "../../interface/IGraphicals.hpp"
#include "../../interface/IGames.hpp"

class DlLoader {
public:
	DlLoader(std::string const &path);
	~DlLoader();
	IGraphicals &getInstance(std::string entry_point);
	IGames &getGame(std::string entry_point);
private:
	std::string _path;
	void *_handle;
	char *_error;
};
#endif