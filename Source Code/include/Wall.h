#ifndef WALL_H
#define WALL_H
#include<SDL.h>
#include<SDL_image.h>
#include"player.h"

class Wall
{
    public:
        Wall();
        ~Wall();
        void create(int x, int y,SDL_Renderer* renderer);
        int h=30;
        int w=30;
        void draw(SDL_Renderer* renderer);

        SDL_Rect dimentions;
        SDL_Texture* icon;
};


#endif // WALL_H
