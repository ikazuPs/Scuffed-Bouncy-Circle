#include <graphics.h> // for the game texture
#include <dos.h> // for idk
#include <conio.h> //for getch
#include <time.h> //for time
#include "bot.h" //for bot
#include <iostream> // for things
#include <windows.h>

using namespace std;


void bullet(int x, int y);

int hp = 100;
int temp; //bullet range
int x = 280/*280*/, y = 370/*370*/, csize = 10; //player position and size
bool isShooting = false; // player is shooting or no u know
bool one = false;
int bulletx, bullety;
bool dead = false;
bool playing = true;

void spawnPlayer()
{
    if(!dead) circle(x,y,csize);
}


void GameOver()
{
    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(225,100,"Game Over You Lost");
    getch();
}

void GameWin()
{
    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(225,100,"Game Over You WON");
    getch();
}

void printmap()
{
    for(int i = 0 ; i < i+1; i++)
    {
        bool botdead = isbotdead();
         if(botdead == true)
         {
             playing = false;
             GameWin();
             break;
         }
         else if(dead == true)
         {
             playing = false;
             GameOver();
             break;
         }
      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
      outtextxy(225,100,"PRESS WASD");
      spawnPlayer();
      SpawnAi();
      AiMove();
      if(!one)
      {
          changeX(150);
          changeY(150);
          one = true;
      }
      cout << "------------------------------------------------" << endl;
      cout << "Player X : " << x << " Player Y : " << y << endl;
      cout << "HP : " << hp << endl;
      cout << "------------------------------------------------" << endl;
      cout << "Bot X : " << retBx() << " Bot Y : " << retBy() << endl;
      cout << "------------------------------------------------" << endl;
      //rectangle(120, 335, 170, 400);
      char ch = getch();
      switch(ch)
      {
      case 'd':
        for(int i = 0; i <= 30; i+=10)
        {
            circle(x+i,y,csize);
            delay(10);
        }
        x += 30;
        break;
      case 'e':
          bullet(x, y);
          isShooting = true;
        break;
      case 'a':
        for(int i = 30; i >= 0; i-=10)
        {
            circle(x-i,y,csize);
            delay(10);
        }
        x -= 30;
        break;
      case 'w':
          for(int i = 30; i >= 0; i-=10)
          {
              circle(x, y-i, csize);
              delay(10);
          }
          y -= 30;
          break;
      case 's':
        for(int i = 0; i <= 30; i+=10)
        {
            circle(x, y+i, csize);
            delay(10);
        }
        y += 30;
        break;
      }

      //BOT WALLING
        int botx = retBx();
        int boty = retBy();
        if(botx == 660)
          {
              for(int i = 60; i >= 0; i-=10)
              {
                  circle(botx-i, boty, csize);
                  delay(10);
              }
              botx -= 60;
          }
          else if(boty == 0)
          {
            for(int i = 0; i <= 60; i+=10)
            {
                circle(botx,boty+i,csize);
                delay(10);
            }
            boty += 60;
          }
          else if(boty == 480)
          {
               for(int i = 60; i >= 0; i-=10)
                {
                circle(botx, boty-i, csize);
                delay(10);
                }
                boty -= 60;
          }
          else if(botx == 0)
            {
            for(int i = 0; i <= 60; i+=10)
            {
                circle(botx+i, boty, csize);
                delay(10);
            }
            botx += 60;
            }


          //BOT WALLING



      if(x == 610)
      {
            for(int i = 60; i >= 0; i-=10)
            {
                circle(x-i,y,csize);
                delay(10);
            }
            x -= 60;
      }
      else if(y == 460)
      {
              for(int i = 60; i >= 0; i-=10)
              {
                  circle(x, y-i, csize);
                  delay(10);
              }
              y -= 60;

      }
      else if(x == 40)
      {
            for(int i = 0; i <= 60; i+=10)
            {
            circle(x+i,y,csize);
            delay(10);
            }
            x += 60;


      }
      else if(y == 10)
      {


            for(int i = 0; i <= 60; i+=10)
            {
            circle(x, y+i, csize);
            delay(10);
            }
            y += 60;


      }

     int tempx = x - botx;
     int tempy = y - boty;
     if(tempx <= 5 && tempy <= 2)
     {
         hp -= 10;
         system("Color 0A");
         if(hp <= 0)
         {
             dead = true;
         }
     }

      changeX(botx);
      changeY(boty);
      cleardevice(); // clear screen
   }

   getch();
   closegraph();

    }



void setup()
{
    int i, gd = DETECT, gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
}


void bullet(int x, int y)
{
    for(int i = 25; i < 25 * 15; i = i + 25)
    {
        circle(x + i, y, 5);
        delay(10);
        bulletx = x + i;
        bullety = y;
        int botx = retBx();
        int boty = retBy();
        if(bulletx + 1 == botx || bulletx + 2 == botx || bulletx + 3 == botx || bulletx + 4 == botx || bulletx + 5 == botx)
        {
            if(y - boty <= 31)
            {
                killbot();
            }
        }
    }
}




int main()
{
    setup();
    while(playing == true)
    {
        printmap();
    }
   return 0;
}
