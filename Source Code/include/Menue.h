#ifndef MENUE_H
#define MENUE_H
#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include"PlayButton.h"
#include "game.h"

class Menue
{
    public:
        Menue();
        ~Menue();
        void initialize(SDL_Renderer * renderer,bool p=1,bool c=0, bool n=0, bool lo=0);
        void handleEvent(game *g,int max_lvl,int *l=NULL);
        void handleKeyboard();
        //void update();
        void render(SDL_Renderer* renderer);
        void destroy();
        bool menueEnd;
       bool pb,cb,nb, lb;
        bool lmenue=false;
       void display_lvls(int n,SDL_Renderer*renderer);


    private:
       // SDL_Renderer* renderer;
        SDL_Texture* background;
        std::list<PlayButton*>lvls;
        PlayButton play;
        PlayButton cont;
        PlayButton next;
        PlayButton loading;
};

#endif // MENUE_H
