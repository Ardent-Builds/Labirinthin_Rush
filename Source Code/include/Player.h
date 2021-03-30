#ifndef PLAYER_H
#define PLAYER_H
#include<bits/stdc++.h>
#include<sdl.h>
#include<SDL_image.h>
#include"Gun.h"





class Player
{
    public:
        Player();
        ~Player();
        void move();
        void initialize(SDL_Renderer *renderer);
        void draw(SDL_Renderer *renderer);
        void port(int x,int y);

        Gun gun;
        SDL_Texture *icon[4]={};
        SDL_Rect pos;
        int speed=5;
        Direction dir=up;
        int health=50;
        bool key=false;
        int kills=0;
        Object *track=new Object;
        bool complete=false;
        bool shooting=false;


};

#endif // PLAYER_H
