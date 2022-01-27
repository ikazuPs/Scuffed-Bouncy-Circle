#include <time.h>
#include <cstdlib>
#include <graphics.h>
int bx = 150, by = 150;
bool generated = false;
bool isdead = false;
void changeX(int x)
{
    bx = x;
}
void changeY(int y)
{
    by = y;
}

bool isbotdead()
{
    return isdead;
}

void killbot()
{
    isdead = true;
}

int retBx()
{
    return bx;
}
int retBy()
{
    return by;
}

void SpawnAi()
{
    if(isdead == true) return;
    srand(time(0));
    if(!generated)
    {
        circle(bx, by, 10);
        generated = true;
    }
    else{
        circle(bx, by, 10);
    }
}

void AiMove()
{
    if(isdead) return;
    srand(time(0));
    int pick = rand() % 4;
    if(pick == 1)
    {
        bx -= 30;
    }
    else if(pick == 2)
    {
        bx += 30;
    }
    else if(pick == 3)
    {
        by -= 30;
    }
    else{
        by += 30;
    }
}

