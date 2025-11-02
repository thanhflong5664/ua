#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "mapwindow.h"
#include "windowLevel.h" // để liên kết đúng hàm
#include "Levelmenu.h"
#include "volume.h"

using namespace sf;
using namespace std;

void Level() {
    RenderWindow LevelWindow(VideoMode(920, 720), "Level", Style::Default);

    SoundBuffer nhac;
    nhac.loadFromFile("music/pop.mp3");
    Sound nhacthtsu(nhac);
    nhacthtsu.setVolume(gVolume);

    Texture anh2;
    anh2.loadFromFile("Graphics/nenanh.jpg");
    Sprite nen2(anh2);
    float scaleX = (float)LevelWindow.getSize().x / anh2.getSize().x;
    float scaleY = (float)LevelWindow.getSize().y / anh2.getSize().y;
    nen2.setScale(scaleX, scaleY);

    LevelMenu capdo(LevelWindow.getSize().x, LevelWindow.getSize().y);

    while (LevelWindow.isOpen()) {
        Event e;
        while (LevelWindow.pollEvent(e)) {
            if (e.type == Event::Closed)
                LevelWindow.close();
            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Escape) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    LevelWindow.close();
                }
                if (e.key.code == Keyboard::Right) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    capdo.MoveRight();
                }
                if (e.key.code == Keyboard::Left) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    capdo.MoveLeft();
                }
                if (e.key.code == Keyboard::Return) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    int pick = capdo.LevelPressed();
                    if (pick == 0) {
                        LevelWindow.setVisible(false);
                        ShowMap1();
                        LevelWindow.setVisible(true);
                        LevelWindow.requestFocus();
                        LevelWindow.clear();
                        LevelWindow.draw(nen2);
                        capdo.draw(LevelWindow);
                        LevelWindow.display();
                    }
                    if (pick == 1) {
                        LevelWindow.setVisible(false);
                        ShowMap2();
                        LevelWindow.setVisible(true);
                        LevelWindow.requestFocus();
                        LevelWindow.clear();
                        LevelWindow.draw(nen2);
                        capdo.draw(LevelWindow);
                        LevelWindow.display();
                    }
                    if (pick == 2) {
                        LevelWindow.setVisible(false);
                        ShowMap3();
                        LevelWindow.setVisible(true);
                        LevelWindow.requestFocus();
                        LevelWindow.clear();
                        LevelWindow.draw(nen2);
                        capdo.draw(LevelWindow);
                        LevelWindow.display();
                    }
                }
            }
        }
        LevelWindow.clear();
        LevelWindow.draw(nen2);
        capdo.draw(LevelWindow);
        LevelWindow.display();
    }
}
