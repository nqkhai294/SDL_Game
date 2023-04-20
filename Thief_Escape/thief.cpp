

#include "thief.h"
#include <stdio.h>
#include <iostream>

bool thief::init()
{
    string thief_path = "res/image/thief.png";

    if (saved_path == thief_path)
    {
        posThief.setPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != thief_path)
    {
        saved_path = thief_path;
        if ( Load(thief_path.c_str() , 1) )
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void thief::Free()
{
    free();
}

void thief::render()
{
    Render(posThief.x, posThief.y, angle);
}

void thief::fall()
{
    if (die && posThief.y < SCREEN_HEIGHT - LAND_HEIGHT - THIEF_HEIGHT - 5)
    {
        if (time == 0)
        {
            y0 = posThief.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posThief.y = y0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void thief::update(int pileWidth, int pileHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            y0 = posThief.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posThief.y = y0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ( (posThief.x + THIEF_WIDTH > posPile[ahead].x + 5) && (posThief.x + 5 < posPile[ahead].x + pileWidth) &&
             (posThief.y + 5 < posPile[ahead].y + pileHeight || posThief.y  + THIEF_HEIGHT > posPile[ahead].y + pileHeight + PILE_SPACE + 5) )
        {
            die = true;
        }
        else if (posThief.x > posPile[ahead].x + pileWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PILE;
            score++;
        }

        if (posThief.y > SCREEN_HEIGHT - LAND_HEIGHT -  THIEF_HEIGHT - 5 || posThief.y < - 10 )
        {
            die = true;
        }
    }
}

