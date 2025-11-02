#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "play.h"
#include "settingmenu.h"
#include "settingwindow.h"
#include "volume.h"
#include "select.h"
using namespace sf;
int main() {

    //tạo cửa sổ
    RenderWindow MENU(VideoMode(920, 720), "Main Menu", Style::Default);
    // tạo mainMenu có kích thước bằng cửa sổ MENU   
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    //tạo nhạc nền và hiệu ứng khi Up, Down
    SoundBuffer nhac;
    nhac.loadFromFile("music/pop.mp3");
    Sound nhacthtsu(nhac);
    nhacthtsu.setVolume(gVolume);                
    Music backgroundMusic;
    backgroundMusic.openFromFile("music/xoso.mp3");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(gVolume);          
    backgroundMusic.play();

    //tạo ảnh nền và gắn ảnh nền với Sprite
    Texture nen;
    nen.loadFromFile("Graphics/snakegamebackground.jpg");
    Sprite bg(nen);

    //lấy tỉ lệ của cửa sổ
    float scaleX = (float)MENU.getSize().x / nen.getSize().x;
    float scaleY = (float)MENU.getSize().y / nen.getSize().y;
    bg.setScale(scaleX, scaleY);

    //khi chạy cửa sổ
    while (MENU.isOpen()) {

        Event sukien;
        //sự kiện đóng cửa sổ
        while (MENU.pollEvent(sukien)) {
            if (sukien.type == Event::Closed)
                MENU.close();

            // điều khiển lên & xuống 
            if (sukien.type == Event::KeyReleased) {
                if (sukien.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                    nhacthtsu.setVolume(gVolume); // chỉnh âm thanh theo gVolume mới nhất
                    nhacthtsu.play();
                    break;
                }
                if (sukien.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                    nhacthtsu.setVolume(gVolume);
                    nhacthtsu.play();
                    break;
                }

                //khi người chơi nhấn Enter
                if (sukien.key.code == Keyboard::Return) {
                    int x = mainMenu.MainMenuPressed();  // trả về số thứ tự dc chọn trong menu

                    if (x == 0) {
                        backgroundMusic.stop();     // dừng nhạc nền
                        MENU.setVisible(false);     // ẩn cửa sổ menu

                        playGame();                 // chạy game
                        
                        MENU.setVisible(true);      // hiện lại cửa sổ menu
                        MENU.requestFocus();        // lấy lại focus
                        backgroundMusic.setVolume(gVolume); 
                        backgroundMusic.play();     

                        MENU.clear();
                        MENU.draw(bg);
                        mainMenu.draw(MENU);
                        MENU.display();
                    }

                    if (x == 1) {
                        backgroundMusic.stop();       // dừng nhạc nền 
                        MENU.setVisible(false);

                        runSettings(); // chạy phần setting ( chỉnh âm thanh hoặc chiếu credit )

         
                        MENU.setVisible(true);        
                        MENU.requestFocus();         
                        
                        backgroundMusic.setVolume(gVolume); 
                        nhacthtsu.setVolume(gVolume);       
                        backgroundMusic.play();          

                     
                        MENU.clear();
                        MENU.draw(bg);
                        mainMenu.draw(MENU);
                        MENU.display();
                    }

                    if (x == 2) {
                        MENU.close();       // thoát chương trình
                    }

                }
            }
        }
        MENU.clear();
        MENU.draw(bg);
        mainMenu.draw(MENU);
        MENU.display();
    }
    return 0;
}
