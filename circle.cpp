#include <graphics.h> // for the game texture
#include <dos.h> // for idk
#include <conio.h> //for getch
#include <time.h> //for time
#include "bot.h" //for bot
#include <iostream> // for things


using namespace std;


void bullet(int x, int y);

int temp; //bullet range
int x = 150/*280*/, y = 150/*370*/, csize = 10; //player position and size
bool isShooting = false; // player is shooting or no u know
bool one = false;



void printmap()
{
    for(int i = 0 ; i < i+1; i++)
    {

      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
      outtextxy(225,100,"PRESS WASD");
      circle(x,y,csize);
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



      /*if(x == 610)
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
      else if(x == 70)
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


      }*/
      if(x == 660)
          {
              for(int i = 60; i >= 0; i-=10)
              {
                  circle(x-i, y, csize);
                  delay(10);
              }
              x -= 60;
          }
          else if(y == 0)
          {
            for(int i = 0; i <= 60; i+=10)
            {
                circle(x,y+i,csize);
                delay(10);
            }
            y += 60;
          }
          else if(y == 480)
          {
               for(int i = 60; i >= 0; i-=10)
                {
                circle(x, y-i, csize);
                delay(10);
                }
                y -= 60;
          }
          else if(x == 0)
            {
            for(int i = 0; i <= 60; i+=10)
            {
                circle(x+i, y, csize);
                delay(10);
            }
            x += 60;
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
    }
}




int main()
{
    setup();
    while(true)
    {
        printmap();
    }
   return 0;
}
