#ifndef BULLET_H
#define BULLET_H
#include "Portal.h"
#include<bits/stdc++.h>
#include<sdl.h>
#include<SDL_image.h>


class Bullet
{
    public:
        Bullet();
        ~Bullet();

        void newBullet(Direction d,int a, int b,SDL_Renderer *renderer);
        int move();
        void draw(SDL_Renderer *renderer);
        void destroy();



        SDL_Rect pos;

        int speed=8;
        Direction dir=up;
        SDL_Texture *icon;
        bool friendly;

};

#endif // BULLET_H
//extern std::list<Bullet*>bullets;
