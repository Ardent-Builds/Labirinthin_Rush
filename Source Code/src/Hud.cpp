#include "Hud.h"

Hud::Hud()
{
    TTF_Init();
    font=TTF_OpenFont("assets/font.ttf",20);
}

Hud::~Hud()
{
    //dtor
}
void Hud::display(SDL_Renderer* renderer,std::list<std::string> *str,int x,int y)
{
    pos.x=x-(x/42)*6;
    pos.y=0;
    pos.h=y/25;
    pos.w=6*x/42;
for(auto i:*str)
{
    SDL_DestroyTexture(icon);
    SDL_Surface *textsurface=NULL;

    textsurface=TTF_RenderText_Solid(font,i.c_str(),textcolor);
    icon=SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_FreeSurface(textsurface);
    SDL_RenderCopy(renderer,icon,NULL,&pos);
    pos.y+=2*y/25;
}
}
