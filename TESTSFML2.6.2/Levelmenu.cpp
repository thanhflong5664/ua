#include "Levelmenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
LevelMenu::LevelMenu(float width, float height) {
    font.loadFromFile("fontchu/font-times-new-roman.ttf");
    
    options[0].setFont(font);
    options[0].setFillColor(Color::Blue);
    options[0].setString("Easy");
    options[0].setCharacterSize(50);
    options[0].setPosition(Vector2f(100, 200));

    options[1].setFont(font);
    options[1].setFillColor(Color::Black);
    options[1].setString("Normal");
    options[1].setCharacterSize(50);
    options[1].setPosition(Vector2f(370, 200));

    options[2].setFont(font);
    options[2].setFillColor(Color::Black);
    options[2].setString("Hard");
    options[2].setCharacterSize(50);
    options[2].setPosition(Vector2f(700, 200));

    LevelSelected = 0;
}

LevelMenu::~LevelMenu() {}

void LevelMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; ++i) window.draw(options[i]);
}

void LevelMenu::MoveLeft() {
    options[LevelSelected].setFillColor(Color::Black);
    LevelSelected--;
    if (LevelSelected < 0) LevelSelected = Max_main_menu - 1;
    options[LevelSelected].setFillColor(Color::Blue);
}

void LevelMenu::MoveRight() {
    options[LevelSelected].setFillColor(Color::Black);
    LevelSelected++;
    if (LevelSelected >= Max_main_menu) LevelSelected = 0;
    options[LevelSelected].setFillColor(Color::Blue);
}