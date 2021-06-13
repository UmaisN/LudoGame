#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>
using namespace sf;




int main()
{
   RenderWindow window(VideoMode(720,720), "Ludo Game");
    window.setFramerateLimit(60);

    //YELLOW TOKENS LOCATIONS
 float Y1x=25;
 float Y1y=570;
 float Y2x=25;
 float Y2y=630;
 float Y3x=90;
 float Y3y=630;
 float Y4x=90;
 float Y4y=570;
 //RED TOKENS LOCATIONS

 float R1x=565;
 float R1y=25;
 float R2x=565;
 float R2y=85;
 float R3y=25;
 float R3x=630;
 float R4y=85;
 float R4x=630;

 //BLUE TOKEN LOCATIONS
 float B1x=25;
 float B1y=25;
 float B2x=25;
 float B2y=85;
 float B3x=90;
 float B3y=25;
 float B4x=90;
 float B4y=85;
 //GREEN TOKEN LOCATIONS;
 float G1x=565;
 float G1y=570;
 float G2x=565;
 float G2y=630;
 float G3x=630;
 float G3y=630;
 float G4x=630;
 float G4y=570;
//ARRAY STORING THESE LOCATIONS
float StartingLocations[4][4][2];
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
    while (window.isOpen())
    {
      Event e;
      while (window.pollEvent(e))
      {
          if (e.type == Event::Closed)
            window.close();
 }
 window.draw(background);
 //DRAWING YELLOW TEAMS TOKENS
 YellowToken1.setPosition(Y1x, Y1y);
 window.draw(YellowToken1);
  YellowToken2.setPosition(Y2x, Y2y);
 window.draw(YellowToken2);
  YellowToken3.setPosition(Y3x, Y3y);
 window.draw(YellowToken3);
  YellowToken4.setPosition(Y4x, Y4y);
 window.draw(YellowToken4);
 //----------------------------------//
 //DRAWING YELLOW TEAMS TOKENS
 BlueToken1.setPosition(B1x, B1y);
 window.draw(BlueToken1);
  BlueToken2.setPosition(B2x, B2y);
 window.draw(BlueToken2);
  BlueToken3.setPosition(B3x, B3y);
 window.draw(BlueToken3);
  BlueToken4.setPosition(B4x, B4y);
 window.draw(BlueToken4);
 //----------------------------------//
  //DRAWING RED TEAMS TOKENS
 RedToken1.setPosition(R1x, R1y);
 window.draw(RedToken1);
  RedToken2.setPosition(R2x, R2y);
 window.draw(RedToken2);
  RedToken3.setPosition(R3x, R3y);
 window.draw(RedToken3);
  RedToken4.setPosition(R4x, R4y);
 window.draw(RedToken4);
 //----------------------------------//
  //----------------------------------//
  //DRAWING GREEN TEAMS TOKENS
// GreenToken1.setPosition(G1x, G1y);
 window.draw(GreenToken1);
  GreenToken2.setPosition(G2x, G2y);
 window.draw(GreenToken2);
  GreenToken3.setPosition(G3x, G3y);
 window.draw(GreenToken3);
  GreenToken4.setPosition(G4x, G4y);
 window.draw(GreenToken4);
 //----------------------------------//
      window.display();

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        GreenToken1.setPosition((float)mousePos.x,static_cast<float>(mousePos.y));
        std::cout <<"JIFND";
;
      }
      }
    return 0;
}
