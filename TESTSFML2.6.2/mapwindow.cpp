#include "mapwindow.h"
#include "volume.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

// Ví dụ mỗi map là 1 hình ảnh khác nhau
void ShowMap1() {
    RenderWindow MAP(VideoMode(920, 720), "Main Menu", Style::Default);

    Music backgroundMusic;
    backgroundMusic.openFromFile("music/bgingame.mp3");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(gVolume);
    backgroundMusic.play();

    Texture m1;
    m1.loadFromFile("Graphics/bandothegioi.jpg");
    Sprite map1(m1);
    float scaleX = (float)MAP.getSize().x / m1.getSize().x;
    float scaleY = (float)MAP.getSize().y / m1.getSize().y;
    map1.setScale(scaleX, scaleY);
    
    while (MAP.isOpen()) {
        Event sukien;
        while (MAP.pollEvent(sukien)) {
            if (sukien.type == Event::Closed)
                MAP.close();
            if (sukien.type == Event::KeyPressed) {
                if (sukien.key.code == Keyboard::Escape)
                    MAP.close();
            }
            MAP.clear();
            MAP.draw(map1);
            MAP.display();
        }
    }
}
void ShowMap2() {
    RenderWindow MAP(VideoMode(900, 700), "Main Menu", Style::Default);
    
    Music backgroundMusic;
    backgroundMusic.openFromFile("music/bgingame.mp3");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(gVolume);
    backgroundMusic.play();

    Texture m1;
    m1.loadFromFile("Graphics/bandolol.jpg");
    Sprite map1(m1);
    float scaleX = (float)MAP.getSize().x / m1.getSize().x;
    float scaleY = (float)MAP.getSize().y / m1.getSize().y;
    map1.setScale(scaleX, scaleY);

    while (MAP.isOpen()) {
        Event sukien;
        while (MAP.pollEvent(sukien)) {
            if (sukien.type == Event::Closed)
                MAP.close();
            if (sukien.type == Event::KeyPressed) {
                if (sukien.key.code == Keyboard::Escape)
                    MAP.close();
            }
        }
        MAP.clear();
        MAP.draw(map1);
        MAP.display();
    }
}

void ShowMap3() {
    RenderWindow MAP(VideoMode(900, 700), "Main Menu", Style::Default);
   
    Music backgroundMusic;
    backgroundMusic.openFromFile("music/bgingame.mp3");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(gVolume);
    backgroundMusic.play();

    Texture m1;
    m1.loadFromFile("Graphics/bandoaov.jpg");
    Sprite map1(m1);
    float scaleX = (float)MAP.getSize().x / m1.getSize().x;
    float scaleY = (float)MAP.getSize().y / m1.getSize().y;
    map1.setScale(scaleX, scaleY);
    
    while (MAP.isOpen()) {
        Event sukien;
        while (MAP.pollEvent(sukien)) {
            if (sukien.type == Event::Closed)
                MAP.close();
            if (sukien.type == Event::KeyPressed) {
                if (sukien.key.code == Keyboard::Escape)
                    MAP.close();
            }
        }
        MAP.clear();
        MAP.draw(map1);
        MAP.display();
    }
}
