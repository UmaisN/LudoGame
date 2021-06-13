#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;

int main()
{
   RenderWindow app(VideoMode(720,720), "Ludo Game");
    app.setFramerateLimit(60);
  //THE 4 TOKENS FOR YELLOW TEAM
  
  Texture TokY1;
  Texture TokY2;
  Texture TokY3;
  Texture TokY4;
   TokY2.loadFromFile("images/Yellow.png");
   TokY3.loadFromFile("images/Yellow.png");
   TokY4.loadFromFile("images/Yellow.png");
   TokY1.loadFromFile("images/Yellow.png");
   Sprite YellowToken1(TokY1);
   Sprite YellowToken2(TokY2);
   Sprite YellowToken3(TokY3);
   Sprite YellowToken4(TokY4);
   //------------------------//
   //THE 4 TOKENS FOR BLUE TEAM
  Texture TokR1;
  Texture TokR2;
  Texture TokR3;
  Texture TokR4;
   TokR2.loadFromFile("images/Blue.png");
   TokR3.loadFromFile("images/Blue.png");
   TokR4.loadFromFile("images/Blue.png");
   TokR1.loadFromFile("images/Blue.png");
   Sprite BlueToken1(TokR1);
   Sprite BlueToken2(TokR2);
   Sprite BlueToken3(TokR3);
   Sprite BlueToken4(TokR4);
   //--------------------------//
    //THE 4 TOKENS FOR REDTEAM
  Texture TokB1;
  Texture TokB2;
  Texture TokB3;
  Texture TokB4;
   TokB2.loadFromFile("images/Red.png");
   TokB3.loadFromFile("images/Red.png");
   TokB4.loadFromFile("images/Red.png");
   TokB1.loadFromFile("images/Red.png");
   Sprite RedToken1(TokB1);
   Sprite RedToken2(TokB2);
   Sprite RedToken3(TokB3);
   Sprite RedToken4(TokB4);
   //--------------------------//
    //THE 4 TOKENS FOR GREEN TEAM
  Texture TokG1;
  Texture TokG2;
  Texture TokG3;
  Texture TokG4;
   TokG2.loadFromFile("images/Green.png");
   TokG3.loadFromFile("images/Green.png");
   TokG4.loadFromFile("images/Green.png");
   TokG1.loadFromFile("images/Green.png");
   Sprite GreenToken1(TokG1);
   Sprite GreenToken2(TokG2);
   Sprite GreenToken3(TokG3);
   Sprite GreenToken4(TokG4);
   //--------------------------//
    Texture bg;
    bg.loadFromFile("images/board.png",sf::IntRect(15,15,720,720));
    Sprite background(bg);
    while (app.isOpen())
    {
      Event e;
      while (app.pollEvent(e))
      {
          if (e.type == Event::Closed)
            app.close();
 }
 app.draw(background);
 //DRAWING YELLOW TEAMS TOKENS
 YellowToken1.setPosition(25.f, 570.f);
 app.draw(YellowToken1);
  YellowToken2.setPosition(25.f, 630.f);
 app.draw(YellowToken2);
  YellowToken2.setPosition(90.f, 630.f);
 app.draw(YellowToken2);
  YellowToken2.setPosition(90.f, 570.f);
 app.draw(YellowToken2);
 //----------------------------------//
 //DRAWING YELLOW TEAMS TOKENS
 BlueToken1.setPosition(25.f, 25.f);
 app.draw(BlueToken1);
  BlueToken2.setPosition(25.f, 85.f);
 app.draw(BlueToken2);
  BlueToken2.setPosition(90.f, 25.f);
 app.draw(BlueToken2);
  BlueToken2.setPosition(90.f, 85.f);
 app.draw(BlueToken2);
 //----------------------------------//
  //DRAWING RED TEAMS TOKENS
 RedToken1.setPosition(565.f, 25.f);
 app.draw(RedToken1);
  RedToken2.setPosition(565.f, 85.f);
 app.draw(RedToken2);
  RedToken2.setPosition(630.f, 25.f);
 app.draw(RedToken2);
  RedToken2.setPosition(630.f, 85.f);
 app.draw(RedToken2);
 //----------------------------------//
  //----------------------------------//
  //DRAWING GREEN TEAMS TOKENS
 GreenToken1.setPosition(565.f, 570.f);
 app.draw(GreenToken1);
  GreenToken2.setPosition(565.f, 630.f);
 app.draw(GreenToken2);
  GreenToken2.setPosition(630.f, 630.f);
 app.draw(GreenToken2);
  GreenToken2.setPosition(630.f, 570.f);
 app.draw(GreenToken2);
 //----------------------------------//
      app.display();
    }
    return 0;
}
