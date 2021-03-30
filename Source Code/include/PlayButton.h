#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
class PlayButton
{
    public:
        PlayButton();
        ~PlayButton();

        void init(int sh, int sw,SDL_Renderer* renderer,const char* text,int y=0);
        void display(SDL_Renderer* renderer);

        int h=60,w=200;
        SDL_Rect pos;

        SDL_Texture*background;
        SDL_Texture*icon;
        bool lvl_menue=false;

        TTF_Font *font=NULL;
        SDL_Color textcolor={255,255,255};

};

#endif // PLAYBUTTON_H
