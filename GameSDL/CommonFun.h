#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

static SDL_Window* g_window = NULL;    // Biến static dùng trong lớp
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Screen
const int FRAME_PER_SECOND = 40; //fps
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;         // chỉ số pixel

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

#define TILE_SIZE 64     // kich thước của 1 mắt lưới

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};

typedef struct Map // lay vi tri cua o trong map
{
    int start_x_;
    int start_y_;

    int max_x_;
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X]; // mảng lưu trạng thái của các ô
    char* file_name_; // tên file chứa map



};

#endif // COMMON_FUNCTION_H_
