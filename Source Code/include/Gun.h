#ifndef GUN_H
#define GUN_H
#include"Bullet.h"
#include<bits/stdc++.h>
#include<sdl.h>
#include<SDL_image.h>
#include"Slash.h"
#include"Sound.h"

class Gun
{
    public:
        Gun();
        ~Gun();

       // void initialize();

        void shoot(int x, int y,SDL_Renderer *renderer,bool friendly=1);
        int slash(int x, int y,SDL_Renderer *renderer,bool friendly=1);
        void update(SDL_Renderer* renderer);
        Direction dir=up;

        //Sound sound;
        int scooldown=0;
        int cooldown=0;

std::list<Bullet*>bullets;
std::list<Slash*>slashes;


};

#endif // GUN_H
