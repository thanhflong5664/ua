#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "singlemenu.h"  // để dùng menu chọn map
#include "windowSinglee.h" // để liên kết đúng hàm
#include "mapwindow.h"
#include "windowLevel.h"
#include "volume.h"
using namespace sf;
using namespace std;

void Single() {
    RenderWindow Single(VideoMode(920, 720), "Single Mode", Style::Default);

    SoundBuffer nhac;
    nhac.loadFromFile("music/pop.mp3");
    Sound nhacthtsu(nhac);
    nhacthtsu.setVolume(gVolume);

    Texture anh2;
    anh2.loadFromFile("Graphics/nenanh.jpg");
    Sprite nen2(anh2);
    float scaleX = (float)Single.getSize().x / anh2.getSize().x;
    float scaleY = (float)Single.getSize().y / anh2.getSize().y;
    nen2.setScale(scaleX, scaleY);

    MainSingleMenu singleMenu(Single.getSize().x, Single.getSize().y);

    while (Single.isOpen()) {
        Event e;
        while (Single.pollEvent(e)) {
            if (e.type == Event::Closed)
                Single.close();
            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Escape)
                    Single.close();
                if (e.key.code == Keyboard::Right) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    singleMenu.MoveRight();
                }
                if (e.key.code == Keyboard::Left) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    singleMenu.MoveLeft();
                }
                if (e.key.code == Keyboard::Return) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    int pick = singleMenu.MainSingleMenuPressed();
                    if (pick == 0) {
                        Single.setVisible(false);
                        Level(); // HEREEEEEEEEEEEEEEEEEEEEEEEEEE
                        Single.setVisible(true);
                        Single.requestFocus();
                        Single.clear();
                        Single.draw(nen2);
                        singleMenu.draw(Single);
                        Single.display();
                    }
                    if (pick == 1) {
                        Single.setVisible(false);
                        Level(); // HEREEEEEEEEEEEEEEEEEEEEEEEEEE
                        Single.setVisible(true);
                        Single.requestFocus();
                        Single.clear();
                        Single.draw(nen2);
                        singleMenu.draw(Single);
                        Single.display();
                    }
                    if (pick == 2) {
                        Single.setVisible(false);
                        Level(); // HEREEEEEEEEEEEEEEEEEEEEEEEEEE
                        Single.setVisible(true);
                        Single.requestFocus();
                        Single.clear();
                        Single.draw(nen2);
                        singleMenu.draw(Single);
                        Single.display();
                    }
                }
            }
        }
        Single.clear();
        Single.draw(nen2);
        singleMenu.draw(Single);
        Single.display();
    }
}
