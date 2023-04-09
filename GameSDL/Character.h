#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CommonFun.h"
#include"BaseObject.h"

#define GRAVITY_SPEED 0  // trọng lực rơi cua nhân vật
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define PLAYER_JUMP_VAL 8

#define BLANK_TILE 0

class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();

    enum WalkTye
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);

    void set_clip();

    void DoPlayer(Map& map_data);
    void CheckToMap(Map& map_data); // Kiểm tra va chạm
    void SetMapXY(const int map_x, const int map_y){map_x_ = map_x; map_y_ = map_y;};
    void CenterEntityOnMap(Map& map_data);

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8];
    Input input_type_;
    int frame_;
    int status_;
    bool on_ground_;

    int map_x_;
    int map_y_;
};

#endif // CHARACTER_H_
