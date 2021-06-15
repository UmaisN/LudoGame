/*
  Ludo Game, Semester 4 OS Project
  Done by Umais Nisar and Salar Abbas
  i190573, i190490
  Section C
*/



#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <unistd.h>    //contains fork and exec
#include <sys/types.h> //contains syscalls
#include <sys/wait.h>  //wait library
#include <errno.h>
#include <pthread.h> //Contains threading stuff
#include <semaphore.h>

using namespace sf;

sem_t players;
RenderWindow app;

void *masterThread(void* arg);

//GLOBALS//
int rollValue;

//---------_________YELLOW TEAM CLASS_______--------//
class YellowTeam
{
public:
  float Y1x = 25;
  float Y1y = 570;
  float Y2x = 25;
  float Y2y = 630;
  float Y3x = 90;
  float Y3y = 630;
  float Y4x = 90;
  float Y4y = 570;
  float YellowArray1[45][2];
  float YellowArray2[45][2];
  float YellowArray3[45][2];
  float YellowArray4[45][2];
  float StartingX = 270;
  float StartingY = 630;
  int Token1Location = 0;
  int Token2Location = 0;
  int Token3Location = 0;
  int Token4Location = 0;
  bool TokenWon[4] = {0, 0, 0, 0};

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

    //1
    for (int i = 0; i < 4; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    //2
    for (int i = 4; i < 8; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    //3
    for (int i = 8; i < 10; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    //---------ROUND 2------------//
    //4
    for (int i = 10; i < 14; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX += 60;
    }
    //5
    for (int i = 14; i < 18; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    //6
    for (int i = 18; i < 20; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX += 60;
    }
    //7
    //---------ROUND #-----------//
    for (int i = 20; i < 24; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY += 60;
    }
    //8
    for (int i = 24; i < 28; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX += 60;
    }
    //9
    for (int i = 28; i < 30; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY += 60;
    }
    //10
    for (int i = 30; i < 34; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    //11
    for (int i = 34; i < 38; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingY += 60;
    }
    //12
    for (int i = 38; i < 39; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    //13
    for (int i = 39; i < 45; i++)
    {
      YellowArray1[i][0] = StartingX;
      YellowArray1[i][1] = StartingY;
      YellowArray2[i][0] = StartingX;
      YellowArray2[i][1] = StartingY;
      YellowArray3[i][0] = StartingX;
      YellowArray3[i][1] = StartingY;
      YellowArray4[i][0] = StartingX;
      YellowArray4[i][1] = StartingY;

      StartingY -= 60;
    }
    //14
  }
};

//__________-------RED TEAM CLASS---------__________//
class RedTeam
{
public:
  float StartingX = 388;
  float StartingY = 27;
  float R1x = 565;
  float R1y = 25;
  float R2x = 565;
  float R2y = 85;
  float R3y = 25;
  float R3x = 630;
  float R4y = 85;
  float R4x = 630;
  float RedArray4[45][2];
  float RedArray1[45][2];
  float RedArray2[45][2];
  float RedArray3[45][2];
  int Token1Location = 0;
  int Token2Location = 0;
  int Token3Location = 0;
  int Token4Location = 0;
  bool TokenWon[4] = {0, 0, 0, 0};
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

    for (int i = 0; i < 4; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 4; i < 8; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 8; i < 10; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 10; i < 14; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 14; i < 18; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 18; i < 20; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 20; i < 24; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 24; i < 28; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 28; i < 30; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 30; i < 34; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 34; i < 38; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 38; i < 39; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 39; i < 45; i++)
    {
      RedArray1[i][0] = StartingX;
      RedArray1[i][1] = StartingY;
      RedArray2[i][0] = StartingX;
      RedArray2[i][1] = StartingY;
      RedArray3[i][0] = StartingX;
      RedArray3[i][1] = StartingY;
      RedArray4[i][0] = StartingX;
      RedArray4[i][1] = StartingY;
      StartingY += 60;
    }
  }
};

//-------_________BLUE TEAM CLASS__________-----------//
class BlueTeam
{
public:
  //BLUE TOKEN LOCATIONS
  float B1x = 25;
  float B1y = 25;
  float B2x = 25;
  float B2y = 85;
  float B3x = 90;
  float B3y = 25;
  float B4x = 90;
  float B4y = 85;
  int Token1Location = 0;
  int Token2Location = 0;
  int Token3Location = 0;
  int Token4Location = 0;
  float BlueArray1[45][2];
  float BlueArray2[45][2];
  float BlueArray3[45][2];
  float BlueArray4[45][2];
  float StartingX = 26;
  float StartingY = 267;
  bool TokenWon[4] = {0, 0, 0, 0};
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
    for (int i = 0; i < 4; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 4; i < 8; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 8; i < 10; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 10; i < 14; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 14; i < 18; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 18; i < 20; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 20; i < 24; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 24; i < 28; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 28; i < 30; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 30; i < 34; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 34; i < 38; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 38; i < 39; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 39; i < 45; i++)
    {
      BlueArray1[i][0] = StartingX;
      BlueArray1[i][1] = StartingY;
      BlueArray2[i][0] = StartingX;
      BlueArray2[i][1] = StartingY;
      BlueArray3[i][0] = StartingX;
      BlueArray3[i][1] = StartingY;
      BlueArray4[i][0] = StartingX;
      BlueArray4[i][1] = StartingY;
      StartingX += 60;
    }
  }
};
//-----______GREEN TEAM CLASS------____________//
class GreenTeam
{
public:
  float G1x = 565;
  float G1y = 570;
  float G2x = 565;
  float G2y = 630;
  float G3x = 630;
  float G3y = 630;
  float G4x = 630;
  float G4y = 570;
  Texture TokG1;
  Texture TokG2;
  Texture TokG3;
  Texture TokG4;
  int Token1Location = 0;
  int Token2Location = 0;
  int Token3Location = 0;
  int Token4Location = 0;
  float StartingX = 628;
  float StartingY = 387;
  float GreenArray1[45][2];
  float GreenArray2[45][2];
  float GreenArray3[45][2];
  float GreenArray4[45][2];
  bool TokenWon[4] = {0, 0, 0, 0};
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
    for (int i = 0; i < 4; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 4; i < 8; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 8; i < 10; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 10; i < 14; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 14; i < 18; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX -= 60;
    }
    for (int i = 18; i < 20; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 20; i < 24; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 24; i < 28; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY -= 60;
    }
    for (int i = 28; i < 30; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 30; i < 34; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 34; i < 38; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX += 60;
    }
    for (int i = 38; i < 39; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingY += 60;
    }
    for (int i = 39; i < 45; i++)
    {
      GreenArray1[i][0] = StartingX;
      GreenArray1[i][1] = StartingY;
      GreenArray2[i][0] = StartingX;
      GreenArray2[i][1] = StartingY;
      GreenArray3[i][0] = StartingX;
      GreenArray3[i][1] = StartingY;
      GreenArray4[i][0] = StartingX;
      GreenArray4[i][1] = StartingY;
      StartingX -= 60;
    }
  }
};
//______________THE DICE CLASS________________//
class Dice
{
public:
  Texture Roll, RollPressed;
  Texture D1, D2, D3, D4, D5, D6, D7;
  float RDAx = 750;
  float RDAy = 150;
  Sprite DS[6];
  Sprite R, RP;

public:
  Dice()
  {
    //Roll Button
    Roll.loadFromFile("images/Roll.png");
    RollPressed.loadFromFile("images/RollPressed.png");
    R.setTexture(Roll);
    RP.setTexture(RollPressed);
    R.setPosition(700, 40);
    RP.setPosition(700, 40);

    //Dice stuff
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
    DS[0].setPosition(RDAx, RDAy);
    DS[1].setPosition(RDAx, RDAy);
    DS[2].setPosition(RDAx, RDAy);
    DS[3].setPosition(RDAx, RDAy);
    DS[4].setPosition(RDAx, RDAy);
    DS[5].setPosition(RDAx, RDAy);
  }
  int RollTheDice()
  {
    int RandomNumber = rand();
    RandomNumber %= 6;
    RandomNumber += 18;
    return RandomNumber;
  }
};
//CLASS FOR PLAYER OF RED TEAM/___________________________??
class PlayerRed
{
public:
  RedTeam Team;
  int score = 0;
  std::string name = "";

public:
  PlayerRed()
  {
    name = "red dude";
  }
  void MoveToken(int TokenNumber, int Value)
  {
    if (TokenNumber == 1)
    {
      Team.Token1Location += Value;
    }
    if (TokenNumber == 2)
    {
      Team.Token2Location += Value;
    }
    if (TokenNumber == 3)
    {
      Team.Token3Location += Value;
    }
    if (TokenNumber == 4)
    {
      Team.Token4Location += Value;
    }
  }
};
//CLASS FOR BLUE TEAM PLAYER_______________________//
class PlayerBlue
{
public:
  BlueTeam Team;
  int score = 0;
  std::string name = "";

public:
  PlayerBlue()
  {
    name = "blue dude";
  }
  void MoveToken(int TokenNumber, int Value)
  {
    if (TokenNumber == 1)
    {
      Team.Token1Location += Value;
    }
    if (TokenNumber == 2)
    {
      Team.Token2Location += Value;
    }
    if (TokenNumber == 3)
    {
      Team.Token3Location += Value;
    }
    if (TokenNumber == 4)
    {
      Team.Token4Location += Value;
    }
  }
};
//GREEN TEAM PLAYER_____________________//
class PlayerGreen
{
public:
  GreenTeam Team;
  int score = 0;
  std::string name = "";

public:
  PlayerGreen()
  {
    name = "Green dude";
  }
  void MoveToken(int TokenNumber, int Value)
  {
    if (TokenNumber == 1)
    {
      Team.Token1Location += Value;
    }
    if (TokenNumber == 2)
    {
      Team.Token2Location += Value;
    }
    if (TokenNumber == 3)
    {
      Team.Token3Location += Value;
    }
    if (TokenNumber == 4)
    {
      Team.Token4Location += Value;
    }
  }
};
//BLUE TEAM PLAYER________________//
class PlayerYellow
{
public:
  YellowTeam Team;
  int score = 0;
  std::string name = "";

public:
  PlayerYellow()
  {
    name = "Yellow dude";
  }
  void MoveToken(int TokenNumber, int Value)
  {
    if (TokenNumber == 1)
    {
      Team.Token1Location += Value;
    }
    if (TokenNumber == 2)
    {
      Team.Token2Location += Value;
    }
    if (TokenNumber == 3)
    {
      Team.Token3Location += Value;
    }
    if (TokenNumber == 4)
    {
      Team.Token4Location += Value;
    }
  }
};

//_______________________THE_______________________//
//______________________MAIN________________________//
//_____________________FUNCTION_____________________//
int main()
{
  int Turn = 10; //DECIDES WHOSE TURN IT IS IN THE DICE ROLLING
  sf::Time T1 = sf::seconds(0.2f);
  RenderWindow window(VideoMode(900, 900), "Ludo Game");
  masterThread(&window);
  window.setFramerateLimit(60);

  //4 players
  //sem_init(&players,0,4);
  pthread_t roller;
  //DECLARING CLASS VARIABLES//
  Dice D;
  PlayerRed PR;
  PlayerGreen PG;
  PlayerBlue PB;
  PlayerYellow PY;

  //_______________//
  Texture bg;
  bg.loadFromFile("images/board.png", sf::IntRect(15, 15, 720, 720));
  Sprite background(bg);
  while (window.isOpen())
  {
    Event e;
    while (window.pollEvent(e))
    {
      if (e.type == Event::Closed)
        window.close();
      //DRAWING ROLL BUTTON AND ITS FUNCTION//
      auto mouse_pos = sf::Mouse::getPosition(window);          // Mouse position relative to the window
      auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
      if (e.type == Event::MouseButtonPressed)
      {

        if (e.key.code == Mouse::Left)
        {
          if (D.R.getGlobalBounds().contains(translated_pos))
          {
            static int yc = 0;
            static int rc = 0;
            static int bc = 0;
            static int gc = 0;

            int TokenHas = 0;
            window.draw(D.RP);
            int j;
            srand(time(NULL));
            j = rand() % 6;
            rollValue = j + 1;
            std::cout << "Roll Value: " << rollValue << std::endl;
            //YELLOW MOVEMENT
            if (Turn % 4 == 0)
            {
              if (rollValue == 6 && yc == 0)
              {
                yc++;
                j = rand() % 6;
                rollValue = j + 1;
                std::cout << "Roll Value: " << rollValue << std::endl;
                PY.MoveToken(1, rollValue);
                if (PY.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PY.Team.Token1Location -= rollValue;
                }
                if (PY.Team.TokenWon[0] == false)
                {
                  if (PY.Team.Token1Location == 44)
                  {
                    PY.Team.TokenWon[0] = true; //
                  }

                  PY.Team.YellowToken1.setPosition(PY.Team.YellowArray1[PY.Team.Token1Location][0], PY.Team.YellowArray1[PY.Team.Token1Location][1]);
                  std::cout << PY.Team.Token1Location << std::endl;
                  window.draw(PY.Team.YellowToken1);
                }
              }
              else if (yc > 0)
              {
                PY.MoveToken(1, rollValue);
                if (PY.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PY.Team.Token1Location -= rollValue;
                }
                if (PY.Team.TokenWon[0] == false)
                {
                  if (PY.Team.Token1Location == 44)
                  {
                    PY.Team.TokenWon[0] = true; //
                  }

                  PY.Team.YellowToken1.setPosition(PY.Team.YellowArray1[PY.Team.Token1Location][0], PY.Team.YellowArray1[PY.Team.Token1Location][1]);
                  std::cout << PY.Team.Token1Location << std::endl;
                  window.draw(PY.Team.YellowToken1);
                }
              }
            }
            //------------------YELLOW MOVEMENT ENDS HERE_______________________//

            //RED MOVEMENT
            if (Turn % 4 == 1)
            {
              if (rollValue == 6 && rc == 0)
              {
                rc++;
                j = rand() % 6;
                rollValue = j + 1;
                std::cout << "Roll Value: " << rollValue << std::endl;
                PR.MoveToken(1, rollValue);
                if (PR.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PR.Team.Token1Location -= rollValue;
                }
                if (PR.Team.TokenWon[0] == false)
                {
                  if (PR.Team.Token1Location == 44)
                  {
                    PR.Team.TokenWon[0] = true; //
                  }
                  PR.Team.RedToken1.setPosition(PR.Team.RedArray1[PR.Team.Token1Location][0], PR.Team.RedArray1[PR.Team.Token1Location][1]);
                  std::cout << PR.Team.Token1Location << std::endl;
                  window.draw(PR.Team.RedToken1);
                }
              }
              else if (rc > 0)
              {
                PR.MoveToken(1, rollValue);
                if (PR.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PR.Team.Token1Location -= rollValue;
                }
                if (PR.Team.TokenWon[0] == false)
                {
                  if (PR.Team.Token1Location == 44)
                  {
                    PR.Team.TokenWon[0] = true; //
                  }
                  PR.Team.RedToken1.setPosition(PR.Team.RedArray1[PR.Team.Token1Location][0], PR.Team.RedArray1[PR.Team.Token1Location][1]);
                  std::cout << PR.Team.Token1Location << std::endl;
                  window.draw(PR.Team.RedToken1);
                }
              }
            }
            //____________RED MOVEMENT ENDS HERE_____________//

            //GREEN MOVEMENT
            if (Turn % 4 == 2)
            {
              if (rollValue == 6 && gc == 0)
              {
                gc++;
                j = rand() % 6;
                rollValue = j + 1;
                std::cout << "Roll Value: " << rollValue << std::endl;
                PG.MoveToken(1, rollValue);
                if (PG.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PG.Team.Token1Location -= rollValue;
                }
                if (PG.Team.TokenWon[0] == false)
                {
                  if (PG.Team.Token1Location == 44)
                  {
                    PG.Team.TokenWon[0] = true; //
                  }
                  PG.Team.GreenToken1.setPosition(PG.Team.GreenArray3[PG.Team.Token1Location][0], PG.Team.GreenArray3[PG.Team.Token1Location][1]);
                  std::cout << PG.Team.Token1Location << std::endl;
                  window.draw(PG.Team.GreenToken1);
                }
              }
              else if (gc > 0)
              {
                PG.MoveToken(1, rollValue);
                j = rand() % 6;
                rollValue = j + 1;
                std::cout << "Roll Value: " << rollValue << std::endl;
                if (PG.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PG.Team.Token1Location -= rollValue;
                }
                if (PG.Team.TokenWon[0] == false)
                {
                  if (PG.Team.Token1Location == 44)
                  {
                    PG.Team.TokenWon[0] = true; //
                  }
                  PG.Team.GreenToken1.setPosition(PG.Team.GreenArray3[PG.Team.Token1Location][0], PG.Team.GreenArray3[PG.Team.Token1Location][1]);
                  std::cout << PG.Team.Token1Location << std::endl;
                  window.draw(PG.Team.GreenToken1);
                }
              }
            }
            //_______________GREEN MOVEMENT ENDS HERE_________//

            //BLUE MOVEMENT
            if (Turn % 4 == 3)
            {
              if (rollValue == 6 && bc == 0)
              {
                bc++;
                PB.MoveToken(1, rollValue);
                if (PB.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PB.Team.Token1Location -= rollValue;
                }
                if (PB.Team.TokenWon[0] == false) //IF IT IS TRUE, MEANS TOKEN HAS WON SO IT WONT GO THROUGH
                {
                  if (PG.Team.Token1Location == 44)
                  {
                    PB.Team.TokenWon[0] = true; //
                  }

                  PB.Team.BlueToken1.setPosition(PB.Team.BlueArray4[PB.Team.Token1Location][0], PB.Team.BlueArray4[PB.Team.Token1Location][1]);
                  std::cout << PB.Team.Token1Location << std::endl;
                  window.draw(PB.Team.BlueToken1);
                }
              }
              else if (bc>0){
                PB.MoveToken(1, rollValue);
                if (PB.Team.Token1Location >= 45) //CHECK IF TOKEN HAS COMPLETED PATH
                {
                  PB.Team.Token1Location -= rollValue;
                }
                if (PB.Team.TokenWon[0] == false) //IF IT IS TRUE, MEANS TOKEN HAS WON SO IT WONT GO THROUGH
                {
                  if (PG.Team.Token1Location == 44)
                  {
                    PB.Team.TokenWon[0] = true; //
                  }

                  PB.Team.BlueToken1.setPosition(PB.Team.BlueArray4[PB.Team.Token1Location][0], PB.Team.BlueArray4[PB.Team.Token1Location][1]);
                  std::cout << PB.Team.Token1Location << std::endl;
                  window.draw(PB.Team.BlueToken1);
                }
              }
            }
            //_____________BLUE MOVEMENT ENDS HERE___________//
            Turn++;
            window.draw(D.DS[j]);
            window.display();
          }
          else
          {
            window.draw(D.R);
          }
        }
      }
      else
      {
        window.draw(D.R);
      }
      /*
      if (e.type == Event::MouseButtonPressed)
      {
        if (e.key.code == Mouse::Left)
        {
          std::cout << "(" << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << ")" << std::endl;
        }
      }
      */
    }

    //DRAWING THE TOKENS__________//
    window.draw(background);
    if (PY.Team.TokenWon[0] == true)
    {
    }
    else
    {
      window.draw(PY.Team.YellowToken1);
    }
    if (PY.Team.TokenWon[1] == true)
    {
    }
    else
    {
      window.draw(PY.Team.YellowToken2);
    }
    if (PY.Team.TokenWon[2] == true)
    {
    }
    else
    {
      window.draw(PY.Team.YellowToken3);
    }
    if (PY.Team.TokenWon[3] == true)
    {
    }
    else
    {
      window.draw(PY.Team.YellowToken4);
    }

    //----------------------------------//
    //DRAWING YELLOW TEAMS TOKENS

    window.draw(PB.Team.BlueToken1);
    window.draw(PB.Team.BlueToken2);
    window.draw(PB.Team.BlueToken3);
    window.draw(PB.Team.BlueToken4);
    //----------------------------------//
    //DRAWING RED TEAMS TOKENS
    window.draw(PR.Team.RedToken1);
    window.draw(PR.Team.RedToken2);
    window.draw(PR.Team.RedToken3);
    window.draw(PR.Team.RedToken4);
    //----------------------------------//
    //----------------------------------//
    //DRAWING GREEN TEAMS TOKENS

    window.draw(PG.Team.GreenToken1);
    window.draw(PG.Team.GreenToken2);
    window.draw(PG.Team.GreenToken3);
    window.draw(PG.Team.GreenToken4);
    //----------------------------------//

    ///////////DISPLAY////////
    window.display();
  }
  return 0;
}

void *temp(void *arg){
  // 0 0 1 1 
  //start an sem (sem wait for dice roll)
  //sem wait if dice roll has happened 
  //sem post dice roll
  //sem wait board
  //sem wait moved
  //sem post board

  //main
  //sem post dice roll has happened in place where dice roll happens
  //sem post if a token moves

  sem_wait(&players);
}

void *masterThread(void* arg){
  int z=0;
  sem_init(&players,0,4);
  pthread_t player[4];
  for (int i =0;i<4;i++){
    pthread_create(&player[i],NULL,&temp,(void *)z);
  }
  for (int i=0;i<4;i++){
    pthread_join(player[i],NULL);
  }
  pthread_exit(0);
}

  //init sems here
  //pass render Window
  //create 4 threads for each player
  //pass each thread an integer

  //init sems here
  //Join 4 threads
