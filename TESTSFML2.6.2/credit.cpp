// Vẽ cửa sổ credit
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "volume.h"
using namespace sf;
using namespace std;

void openCredit() {

    RenderWindow Credit(VideoMode(920, 720), "Credit", Style::Default);

    Music backgroundMusic;
    backgroundMusic.openFromFile("music/piano.mp3");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(gVolume);
    backgroundMusic.play();


    // ===== Ảnh nền =====
    Texture anh2;
    anh2.loadFromFile("Graphics/nenanh.jpg");
        
    Sprite nen2(anh2);
    float scaleX = (float)Credit.getSize().x / anh2.getSize().x;
    float scaleY = (float)Credit.getSize().y / anh2.getSize().y;
    nen2.setScale(scaleX, scaleY);

    // ===== Font =====
    Font font;
    font.loadFromFile("fontchu/font-times-new-roman.ttf");
       
    // ===== Danh sách các dòng credit =====
    vector<string> creditLines = {
        "A game developed by group 5.",
        "Presented by Group 5.",
        "Team Members:",
        "- Trinh Tuan Kiet - Game Logic Developer.",
        "- Le Thanh Long - UI Designer & Intergrator.",
        "- Nguyen Vu Gia Phuc - Map Designer.",
        "Kiet implemented the snake movement, scroring, and fruit mechanics.",
        "Long developed the main menu,settings,volume, credit interface and exit.",
        "Phuc designed maps for both single and multiplayer modes.",
        "Background muic menu: Snake Charmer Song (Sight of Wonders).",
        "Background music credit: Rick Astley - Never Gonna Give You Up | Piano cover.",
        "Sound effect: Pop SFX - Myinstants.com.",
        "Developed with C++ and SFML 2.6.2.",
        "Compiled on Visual Studio 2022.",
        "I would like to express my heartfelt thanks to several friends",
        "who contributed their ideas, support, and assistance throughout the development of this game." ,
        "Your help and encouragement have been a great source of motivation for me to complete this project.",
        "Special thanks to Mr.The and our classamtes. Thank you for listening."
    };

    // ===== Tạo các Text từ danh sách =====
    vector<Text> creditTexts;
    for (const auto& line : creditLines) {
        Text t(line, font, 20);
        t.setFillColor(Color::Black);
        creditTexts.push_back(t);
    }

    // ===== Biến điều khiển hiển thị từng dòng =====
    Clock clock;
    float delayPerLine = 1.0f; // 1 giây giữa các dòng
    int currentLine = 0;
    bool creditsDone = false;
    float startY = 0.f; // vị trí dòng đầu tiên

    // ===== Vòng lặp chính của cửa sổ credit =====
    while (Credit.isOpen()) {
        Event e;
        while (Credit.pollEvent(e)) {
            if (e.type == Event::Closed)
                Credit.close();

            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Escape)
                    Credit.close();
            }
        }

        // ===== Cập nhật thời gian hiển thị dòng mới =====
        if (!creditsDone && clock.getElapsedTime().asSeconds() > delayPerLine) {
            clock.restart();
            if (currentLine < (int)creditTexts.size())
                currentLine++;
            else
                creditsDone = true;
        }

        // ===== Vẽ lên cửa sổ =====
        Credit.clear();
        Credit.draw(nen2); // vẽ nền

        // Vẽ các dòng đã xuất hiện
        for (int i = 0; i < currentLine; ++i) {
            FloatRect bounds = creditTexts[i].getLocalBounds();
            creditTexts[i].setPosition(
                (Credit.getSize().x - bounds.width) / 2.f,
                startY + i * 20.f
            );
            Credit.draw(creditTexts[i]);
        }
        Credit.display();
    }
}
