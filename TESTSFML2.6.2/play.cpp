// Vẽ cửa sổ "play"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "volume.h"
#include "select.h"
#include "windowSinglee.h"
using namespace sf;
using namespace std;

void playGame() {

    RenderWindow Play(VideoMode(920, 720), "Play", Style::Default);
    
    SoundBuffer nhac;
    nhac.loadFromFile("music/pop.mp3");
    Sound nhacthtsu(nhac);
    nhacthtsu.setVolume(gVolume);

    Texture anh2;
    anh2.loadFromFile("Graphics/nenanh.jpg");
    Sprite nen2(anh2);
    float scaleX = (float)Play.getSize().x / anh2.getSize().x;
    float scaleY = (float)Play.getSize().y / anh2.getSize().y;
    nen2.setScale(scaleX, scaleY);

    MainMenu2 modeMenu(Play.getSize().x, Play.getSize().y);

    while (Play.isOpen()) {
        Event e;
        while (Play.pollEvent(e)) {
            if (e.type == Event::Closed)
                Play.close();
            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Escape) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    Play.close();
                }
                if (e.key.code == Keyboard::Up) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    modeMenu.MoveUp();
                }
                if (e.key.code == Keyboard::Down) {
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    modeMenu.MoveDown();
                }
                if (e.key.code == Keyboard::Return) {
                    int pick = modeMenu.MainMenuPressed();
                    if (pick == 0) {
                        Play.setVisible(false);

                        Single();

                        Play.setVisible(true);
                        Play.requestFocus();
                        Play.clear();
                        Play.draw(nen2);
                        modeMenu.draw(Play);
                        Play.display();
                    }
                    if (pick == 1) {
                        // thêm code phần Multiple vào đây
                    }
                    Play.close();
                }
            }
        }
        Play.clear();
        Play.draw(nen2);
        modeMenu.draw(Play);
        Play.display();
    }
}
