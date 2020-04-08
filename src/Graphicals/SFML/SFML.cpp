/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sfml
*/

#include "SFML.hpp"

SFML::SFML()
{}

SFML::~SFML()
{}

void SFML::ProcessInput()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _key = SYS_EXIT;
        if (_event.type == sf::Event::KeyPressed) {
            switch (_event.key.code) {
                case sf::Keyboard::Z :
                    _key = UP;
                    break;
                case sf::Keyboard::D :
                    _key = RIGHT;
                    break;
                case sf::Keyboard::S :
                    _key = DOWN;
                    break;
                case sf::Keyboard::Q :
                    _key = LEFT;
                    break;
                case sf::Keyboard::Return :
                    _key = ENTER;
                    break;
                case sf::Keyboard::Space :
                    _key = SPACE;
                    break;
                case sf::Keyboard::O :
                    _key = SYS_PREVIOUS_GRAPHICAL_LIBRARY;
                    break;
                case sf::Keyboard::P :
                    _key = SYS_NEXT_GRAPHICAL_LIBRARY;
                    break;
                case sf::Keyboard::L :
                    _key = SYS_PREVIOUS_GAME;
                    break;
                case sf::Keyboard::M :
                    _key = SYS_NEXT_GAME;
                    break;
                case sf::Keyboard::X :
                    _key = SYS_RESTART;
                    break;
                case sf::Keyboard::Escape :
                    _key = SYS_BACK_TO_MENU;
                    break;
                case sf::Keyboard::W :
                    _key = SYS_EXIT;
                    break;
                default:
                    _key = UNDEFINED;
                    break;
            }
        }
    }
}

KeyEnum SFML::KeyPressed()
{
    return (_key);
}

void SFML::InitWindow()
{
    _window.create(sf::VideoMode(960, 540), "Arcade");
}

bool SFML::IsWindowOpen()
{
    return (_window.isOpen());
}

void SFML::CloseWindow()
{
    printf("close\n");
    _window.close();
}

void SFML::PrintBlock(const float x, const float y, Texture text)
{
    sf::RectangleShape rec(sf::Vector2f(40, 40));

    rec.setPosition(x * 40, y * 40);
    switch(text) {
        case 0:
            rec.setFillColor(sf::Color::Green);
            break;
        case 1:
            rec.setFillColor(sf::Color::Blue);
            break;
        case 2:
            rec.setFillColor(sf::Color::Transparent);
            break;
        case 3:
            rec.setFillColor(sf::Color::White);
            break;
        case 4:
            rec.setFillColor(sf::Color::Red);
            break;
        case 5:
            rec.setFillColor(sf::Color::Cyan);
            break;
        case 6:
            rec.setFillColor(sf::Color::Cyan);
            break;
        case 7:
            rec.setFillColor(sf::Color::Cyan);
            break;
        case 8:
            rec.setFillColor(sf::Color::Magenta);
            break;
    }
    rec.setFillColor(sf::Color::Blue); // use int color (enum)
    _window.draw(rec);
}

void SFML::PrintText(const float x, const float y, const int color,
                     const std::string &content)
{
    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("./src/Graphicals/SFML/res/arial.ttf")) {
        fprintf(stderr, "Error while loading SFML Font\n");
        return;
    }
    text.setFont(font);
    text.setString(content);
    text.setFillColor(sf::Color::Red); // use int color (enum)
    text.setPosition(x, y);
    _window.draw(text);
}

void SFML::DisplayWindow()
{
    _window.display();
}

void SFML::ClearWindow()
{
    _window.clear();
}

bool SFML::is_mouse_clicked()
{
    return (true);
}

std::vector<int> SFML::GetMousePosition()
{
    std::vector<int> res;
    sf::Vector2i vec = sf::Mouse::getPosition();
    
    res.push_back(vec.x);
    res.push_back(vec.y);
    return (res);
}

std::string SFML::GetPlayerUsername()
{
    return "";
}

extern "C" IGraphicals *constructor()
{
    return new SFML;
}