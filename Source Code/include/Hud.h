#ifndef HUD_H
#define HUD_H
#include<SDL.h>
#include<SDL_ttf.h>
#include<bits/stdc++.h>

class Hud
{
    public:
        Hud();
        ~Hud();

        void display(SDL_Renderer* renderer,std::list<std::string>* str,int x,int y);


        SDL_Rect pos;

        SDL_Texture*icon;

        TTF_Font *font=NULL;
        SDL_Color textcolor={255,255,255};
};

#endif // HUD_H
