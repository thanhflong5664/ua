#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

#define Max_main_menu 3

class MainSingleMenu {
public:
    MainSingleMenu(float width, float height);
    void draw(RenderWindow& window);
    void MoveRight();
    void MoveLeft();

    int MainSingleMenuPressed() const { return MainSingleMenuSelected; }
    ~MainSingleMenu();

private:
    int  MainSingleMenuSelected;
    Font font;
    Texture pic1, pic2, pic3;
    Sprite map1, map2, map3;
    Text options[Max_main_menu]; // 2 mục: Volume, Music
};