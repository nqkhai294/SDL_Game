#include "game.h"
#include "lib.h"
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>


const short int FPS = 60;
const short int frameDelay = 1000 / FPS;

using namespace std;

int main(int argc, char** argv)
{
    int frameStart;
    short int frameTime;
    game game_;
    bool isMenu = 0;
    bool isPause = 0;

    while(!game_.isQuit())
    {
        frameStart = SDL_GetTicks();

        if (game_.isDie())
        {
           /* if (isMenu) {           //?
                game_.thief_.render();
            }*/
            game_.playerInput.Type = game::input::NONE;
            while(game_.isDie())
            {
                game_.takeInput();
                if (isMenu == 1 && game_.playerInput.Type == game::input::PLAY)
                {
                    if (game_.checkReplay())
                    {
                        isMenu = 0;
                    }
                    game_.playerInput.Type = game::input::NONE;
                }
                game_.renderBackground();
                game_.pile_.render();
                game_.land_.render();
                if (isMenu)
                {
                    game_.thief_.render();
                    game_.thief_.fall();
                    game_.renderGameOver();
                    game_.renderScoreSmall();
                    game_.renderBestScore();
                    game_.replay();
                }
                else
                {
                    game_.pile_.init();
                    game_.thief_.init();
                    game_.thief_.render();
                    game_.renderReady();
                    game_.renderGuide();
                    if (game_.playerInput.Type == game::input::PLAY)
                    {
                        game_.Restart();
                        isMenu = 1;
                        game_.playerInput.Type = game::input::NONE;
                    }
                    game_.land_.update();
                }
                game_.display();
            }
            game_.pile_.init();
        }
        else
        {
            game_.takeInput();

            if (game_.playerInput.Type == game::input::PAUSE)
            {
                isPause = 1 - isPause;
                game_.playerInput.Type = game::input::NONE;
            }

            if (isPause == 0 && game_.playerInput.Type == game::input::PLAY)
            {
                game_.thief_.resetTime();
                game_.playerInput.Type = game::input::NONE;
            }

            game_.renderBackground();
            game_.pile_.render();
            game_.land_.render();
            game_.thief_.render();
            game_.renderScoreLarge();

            if (!isPause)
            {
                game_.thief_.update(game_.getPileWidth(), game_.getPileHeight());
                game_.pile_.update();
                game_.land_.update();
                game_.pause();
            }
            else
            {
                game_.resume();
                game_.renderPauseTab();
                game_.renderScoreSmall();
                game_.renderBestScore();
                game_.replay();

                if (game_.playerInput.Type == game::input::PLAY)
                {
                    if (game_.checkReplay())
                    {
                        isPause = 0;
                    }

                    game_.playerInput.Type = game::input::NONE;
                }
            }
            game_.display();
        }

        //Limit FPS
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}

