#include "pile.h"
#include "stdio.h"

vector<position> posPile;

bool pile::init()
{
    posPile.clear();
    for (signed char i = 0; i < TOTAL_PILE; i++)
    {
        position temp;
        temp.setPos(SCREEN_WIDTH + i * PILE_DISTANCE + 350, (rand() % (randMax - randMin + 1)) + randMin);
        posPile.push_back(temp);
    }
    if (isNULL())
    {
        if (Load( "res/image/pile.png", 1 ))
        {
            return true;
        }
    }
    return false;
}

void pile::Free()
{
    free();
}

void pile::render()
{
    for (signed char i = 0; i < TOTAL_PILE; i++)
    {
        if (posPile[i].x <= SCREEN_WIDTH && posPile[i].x > -getWidth())
        {
            Render(posPile[i].x, posPile[i].y);
        }
        Render(posPile[i].x, posPile[i].y + getHeight() + PILE_SPACE, 180);
    }
}

void pile::update()
{
    if (!die)
    {
        for (signed char i = 0; i < TOTAL_PILE; i++)
        {
            if (posPile[i].x < - getWidth())
            {
                posPile[i].y = (rand() % (randMax - randMin + 1)) + randMin;
                posPile[i].x = posPile[(i + TOTAL_PILE - 1) % TOTAL_PILE].x + PILE_DISTANCE;
            }
            else
            {
                posPile[i].x -= 3;
            }
        }
    }
}


