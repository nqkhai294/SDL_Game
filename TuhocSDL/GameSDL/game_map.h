
#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include "CommonFun.h"
#include "BaseObject.h"

#define MAX_TILES 20 // dạng map

// su dung ke thua

class TileMat : public BaseObject
{
public:
    //TileMat();
    //~TileMat();
};

class GameMap
{
public:
   // GameMap();
    //~GameMap();

    void LoadMap(char* name);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);


private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];

};


#endif // GAME_MAP_H_
