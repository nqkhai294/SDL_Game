#include<iostream>
#include<string>
#include <SDL.h>
#include <SDL_image.h>

// di chuyen
struct INPUT
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};




class MainObject
{
public:
    MainObject();
    ~MainObject();



    enum WalkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();

    SDL_Texture* character = NULL;

private:

    float x_val;
    float y_val;

    float x_pos;
    float y_pos;

    int width_frame;
    int height_frame;

    SDL_Rect frame_clip[8]; // luu frame
    INPUT input_type;
    int frame;
    int status;

    SDL_Rect rect_;

};
