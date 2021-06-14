#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
using namespace sf;



//---------_________YELLOW TEAM CLASS_______--------//
class YellowTeam {
  public:
    float Y1x=25;
    float Y1y=570;
    float Y2x=25;
    float Y2y=630;
    float Y3x=90;
    float Y3y=630;
    float Y4x=90;
    float Y4y=570;
    Texture TokY1;
    Texture TokY2;
    Texture TokY3;
    Texture TokY4;
    Sprite YellowToken1;
    Sprite YellowToken2;
    Sprite YellowToken3;
    Sprite YellowToken4;
  public:
    YellowTeam()
    {
      TokY2.loadFromFile("images/Yellow.png");
      TokY3.loadFromFile("images/Yellow.png");
      TokY4.loadFromFile("images/Yellow.png");
      TokY1.loadFromFile("images/Yellow.png");
      YellowToken1.setTexture(TokY1);
      YellowToken2.setTexture(TokY2);
      YellowToken3.setTexture(TokY3);
      YellowToken4.setTexture(TokY4);
      YellowToken1.setPosition(Y2x, Y2y);
      YellowToken2.setPosition(Y1x, Y1y);
      YellowToken3.setPosition(Y3x, Y3y);
      YellowToken4.setPosition(Y4x, Y4y);
    }
};

//__________-------RED TEAM CLASS---------__________//
class RedTeam {
  public:
    float R1x=565;
    float R1y=25;
    float R2x=565;
    float R2y=85;
    float R3y=25;
    float R3x=630;
    float R4y=85;
    float R4x=630;
    Texture TokR1;
    Texture TokR2;
    Texture TokR3;
    Texture TokR4;
    Sprite RedToken1;
    Sprite RedToken2;
    Sprite RedToken3;
    Sprite RedToken4;
  public:
    RedTeam()
    {
      TokR2.loadFromFile("images/Red.png");
      TokR3.loadFromFile("images/Red.png");
      TokR4.loadFromFile("images/Red.png");
      TokR1.loadFromFile("images/Red.png");
      RedToken1.setTexture(TokR1);
      RedToken2.setTexture(TokR2);
      RedToken3.setTexture(TokR3);
      RedToken4.setTexture(TokR4);
      RedToken1.setPosition(R2x, R2y);
      RedToken2.setPosition(R1x, R1y);
      RedToken3.setPosition(R3x, R3y);
      RedToken4.setPosition(R4x, R4y);
    }
};
//--------________RED TEAM CLASS__________------------//
//-------_________BLUE TEAM CLASS__________-----------//
class BlueTeam
{
public:
 //BLUE TOKEN LOCATIONS
 float B1x=25;
 float B1y=25;
 float B2x=25;
 float B2y=85;
 float B3x=90;
 float B3y=25;
 float B4x=90;
 float B4y=85;
 Texture TokB1;
 Texture TokB2;
 Texture TokB3;
 Texture TokB4;
 Sprite BlueToken1;
 Sprite BlueToken2;
 Sprite BlueToken3;
 Sprite BlueToken4;
  public:
    BlueTeam()
    {
    TokB2.loadFromFile("images/Blue.png");
    TokB3.loadFromFile("images/Blue.png");
    TokB4.loadFromFile("images/Blue.png");
    TokB1.loadFromFile("images/Blue.png");
    BlueToken1.setTexture(TokB1);
    BlueToken2.setTexture(TokB2);
    BlueToken3.setTexture(TokB3);
    BlueToken4.setTexture(TokB4);
    BlueToken1.setPosition(B1x, B1y);
    BlueToken2.setPosition(B2x, B2y);
    BlueToken3.setPosition(B3x, B3y);
    BlueToken4.setPosition(B4x, B4y);
 }
};
//-----______GREEN TEAM CLASS------____________//
class GreenTeam {
public:
  float G1x=565;
  float G1y=570;
  float G2x=565;
  float G2y=630;
  float G3x=630;
  float G3y=630;
  float G4x=630;
  float G4y=570;
  Texture TokG1;
  Texture TokG2;
  Texture TokG3;
  Texture TokG4;
  Sprite GreenToken1;
  Sprite GreenToken2;
  Sprite GreenToken3;
  Sprite GreenToken4;
  public:
    GreenTeam()
    {
      TokG2.loadFromFile("images/Green.png");
      TokG3.loadFromFile("images/Green.png");
      TokG4.loadFromFile("images/Green.png");
      TokG1.loadFromFile("images/Green.png");
      GreenToken1.setTexture(TokG1);
      GreenToken2.setTexture(TokG2);
      GreenToken3.setTexture(TokG3);
      GreenToken4.setTexture(TokG4);
      GreenToken1.setPosition(G1x, G1y);
      GreenToken4.setPosition(G4x, G4y);
      GreenToken3.setPosition(G3x, G3y);
      GreenToken2.setPosition(G2x, G2y);
   }
};
//______________THE DICE CLASS________________//
class Dice
{
public:
Texture D1,D2,D3,D4,D5,D6,D7;
float RDAx = 750;
float RDAy =  150;
Sprite DS[6];
public:
  Dice()
  {
    D1.loadFromFile("images/Dice1.png");
    D2.loadFromFile("images/Dice2.png");
    D3.loadFromFile("images/Dice3.png");
    D4.loadFromFile("images/Dice4.png");
    D5.loadFromFile("images/Dice5.png");
    D6.loadFromFile("images/Dice6.png");
    DS[0].setTexture(D1);
    DS[1].setTexture(D2);
    DS[2].setTexture(D3);
    DS[3].setTexture(D4);
    DS[4].setTexture(D5);
    DS[5].setTexture(D6);
    DS[0].setPosition(RDAx,RDAy);
    DS[1].setPosition(RDAx,RDAy);
    DS[2].setPosition(RDAx,RDAy);
    DS[3].setPosition(RDAx,RDAy);
    DS[4].setPosition(RDAx,RDAy);
    DS[5].setPosition(RDAx,RDAy);
  }

  int RollTheDice()
  {
    int RandomNumber = rand();
    RandomNumber %=6;
    RandomNumber +=18;
    return RandomNumber;
  }
};

//_______________________THE_______________________//
//______________________MAIN________________________//
//_____________________FUNCTION_____________________//
int main()
{
  sf::Time T1 = sf::seconds(0.2f);
  RenderWindow window(VideoMode(900,900), "Ludo Game");
  window.setFramerateLimit(60);
  //DECLARING CLASS VARIABLES//
  GreenTeam G;
  BlueTeam B;
  RedTeam R;
  YellowTeam Y;
  Dice D;
//_______________//
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
 //DRAWING THE TOKENS__________//
 window.draw(background);
 window.draw(Y.YellowToken1);
 window.draw(Y.YellowToken2);
 window.draw(Y.YellowToken3);
 window.draw(Y.YellowToken4);
 //----------------------------------//
 //DRAWING YELLOW TEAMS TOKENS

 window.draw(B.BlueToken1);
 window.draw(B.BlueToken2);
 window.draw(B.BlueToken3);
 window.draw(B.BlueToken4);
 //----------------------------------//
  //DRAWING RED TEAMS TOKENS
 window.draw(R.RedToken1);
 window.draw(R.RedToken2);
 window.draw(R.RedToken3);
 window.draw(R.RedToken4);
 //----------------------------------//
  //----------------------------------//
  //DRAWING GREEN TEAMS TOKENS
 
 window.draw(G.GreenToken1);
 window.draw(G.GreenToken2);
 window.draw(G.GreenToken3);
 window.draw(G.GreenToken4);
 //----------------------------------//
      

      //FUNCTION TO SHOW DICE ANIMATION
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
      {
        int RandomNumber = rand();
        RandomNumber %=6;
        RandomNumber+=18;
        std::cout << RandomNumber <<std::endl;
        for(int i=0;i<RandomNumber;i++)
        {
          int j=i;
          if(i> 5)
          {
            j %=5;
          }
           window.draw(D.DS[j]);
            window.display();
       sleep(T1);
          }
      
        }

        
     window.display();
      }
    return 0;
}

