#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

#define Max_main_menu 3

class LevelMenu{
public:
    LevelMenu(float width, float height);
    void draw(RenderWindow& window);
    void MoveRight();
    void MoveLeft();

    int LevelPressed() const { return LevelSelected; }
    ~LevelMenu();

private:
    int  LevelSelected;
    Font font;
    Text options[Max_main_menu]; // 3 mục: Easy, Normal, Hard
};