#include "MainObject.h"

MainObject::MainObject()
{
    frame = 0;
    x_pos = 0;
    y_pos = 0;
    x_val = 0;
    y_val = 0;
    width_frame = 0;
    height_frame = 0;
    status = -1;
    rect_.x = 0;
    rect_.y = 0;
}

MainObject::~MainObject()
{


}


bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if (load_surface != NULL)
    {
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if (new_texture != NULL)
        {
            width_frame = load_surface->w;
            height_frame = load_surface->h;

            width_frame = width_frame/8;

        }

        SDL_FreeSurface(load_surface);
    }
    return new_texture;
}


void MainObject::set_clips()
{
    if (width_frame > 0 & height_frame >0)
    {
        frame_clip[0].x = 0;
        frame_clip[0].y = 0;
        frame_clip[0].w = width_frame;
        frame_clip[0].h = height_frame;

        frame_clip[1].x = width_frame;
        frame_clip[1].y = 0;
        frame_clip[1].w = width_frame;
        frame_clip[1].h = height_frame;

        frame_clip[2].x = 2*width_frame;
        frame_clip[2].y = 0;
        frame_clip[2].w = width_frame;
        frame_clip[2].h = height_frame;

        frame_clip[3].x = 3*width_frame;
        frame_clip[3].y = 0;
        frame_clip[3].w = width_frame;
        frame_clip[3].h = height_frame;

        frame_clip[4].x = 4*width_frame;
        frame_clip[4].y = 0;
        frame_clip[4].w = width_frame;
        frame_clip[4].h = height_frame;

        frame_clip[5].x = 5*width_frame;
        frame_clip[5].y = 0;
        frame_clip[5].w = width_frame;
        frame_clip[5].h = height_frame;

        frame_clip[6].x = 6*width_frame;
        frame_clip[6].y = 0;
        frame_clip[6].w = width_frame;
        frame_clip[6].h = height_frame;

        frame_clip[7].x = 7*width_frame;
        frame_clip[7].y = 0;
        frame_clip[7].w = width_frame;
        frame_clip[7].h = height_frame;
    }
}

void MainObject::Show(SDL_Renderer* des)
{
    if (status == WALK_LEFT)
    {
        LoadImg("Run_Right.png", des);
    }
    else
    {
        LoadImg("Run_Rigth.png", des);
    }

    if (input_type.left_ == 1 || input_type.right_ == 1)
    {
        frame ++;
    }
    else frame =0;

    rect_.x = x_pos;
    rect_.y = y_pos;

    SDL_Rect current_clip = frame_clip[frame];

    SDL_Rect* renderQuad = {rect_.x, rect_.y, width_frame, height_frame};

    SDL_RenderCopy(des, character, current_clip, &renderQuad);
}

void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                status = WALK_RIGHT;
                input_type.right_ = 1;
            }
            break;
        case SDLK_LEFT:
            {
                status = WALK_LEFT;
                input_type.left_ = 1;
            }
            break;
        default:
            break;
        }
    }
}












