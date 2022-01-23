#include <graphics.h>
#include <dos.h>
#include <conio.h>


int main()
{
   int i, gd = DETECT, gm;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   int x = 280, y = 370, csize = 10;
   for( i = 0 ; i < i+1; i++)
   {
      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
      outtextxy(225,100,"PRESS WASD");
      circle(x,y,csize);
      //rectangle(30, 335, 80, 400);
      rectangle(120, 335, 170, 400);
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
      }
      else if(x == 190)
      {
          if(y == 370 || y == 400 || y == 340)
          {
              for(int i = 0; i <= 60; i+=10)
            {
                circle(x+i,y,csize);
                delay(10);
            }
                x += 60;
          }
      }
      else if(y == 310)
      {
          if(x == 160 || x == 130)
          {
          for(int i = 60; i >= 0; i-=10)
          {
              circle(x, y-i, csize);
              delay(10);
          }
          y -= 60;
          }
      }


      cleardevice(); // clear screen
   }

   getch();
   closegraph();
   return 0;
}
