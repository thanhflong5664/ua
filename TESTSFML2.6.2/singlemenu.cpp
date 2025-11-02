//Vẽ 2 dòng Volume và Credit + nút bấm lên xuống
#include "singlemenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
MainSingleMenu::MainSingleMenu(float width, float height) {
    font.loadFromFile("fontchu/font-times-new-roman.ttf");
    pic1.loadFromFile("Graphics/bandothegioi.jpg");
    pic2.loadFromFile("Graphics/bandoaov.jpg");
    pic3.loadFromFile("Graphics/bandolol.jpg");
    
    map1.setTexture(pic1);
    map2.setTexture(pic2);
    map3.setTexture(pic3);

    map1.setScale(0.7f, 0.7f);
    map2.setScale(0.7f, 0.7f);
    map3.setScale(0.7f, 0.7f);

    map1.setPosition(Vector2f(50, 200));
    map2.setPosition(Vector2f(350, 200));
    map3.setPosition(Vector2f(650, 200));

    options[0].setFont(font);
    options[0].setFillColor(Color::Blue);
    options[0].setString("Map 1");
    options[0].setCharacterSize(30);
    options[0].setPosition(Vector2f(120, 350));

    options[1].setFont(font);
    options[1].setFillColor(Color::Black);
    options[1].setString("Map 2");
    options[1].setCharacterSize(30);
    options[1].setPosition(Vector2f(425, 350));

    options[2].setFont(font);
    options[2].setFillColor(Color::Black);
    options[2].setString("Map 3");
    options[2].setCharacterSize(30);
    options[2].setPosition(Vector2f(700, 350));

    MainSingleMenuSelected = 0;
}

MainSingleMenu::~MainSingleMenu() {}

void MainSingleMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; ++i) window.draw(options[i]);
    window.draw(map1);
    window.draw(map2);
    window.draw(map3);
}

void MainSingleMenu::MoveLeft() {
    options[MainSingleMenuSelected].setFillColor(Color::Black);
    MainSingleMenuSelected--;
    if (MainSingleMenuSelected < 0) MainSingleMenuSelected = Max_main_menu - 1;
    options[MainSingleMenuSelected].setFillColor(Color::Blue);
}

void MainSingleMenu::MoveRight() {
    options[MainSingleMenuSelected].setFillColor(Color::Black);
    MainSingleMenuSelected++;
    if (MainSingleMenuSelected >= Max_main_menu) MainSingleMenuSelected = 0;
    options[MainSingleMenuSelected].setFillColor(Color::Blue);
}