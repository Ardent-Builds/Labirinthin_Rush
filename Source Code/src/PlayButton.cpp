#include "PlayButton.h"



PlayButton::PlayButton()
{
    //ctor
}

PlayButton::~PlayButton()
{
    SDL_DestroyTexture(icon);
}

void PlayButton::init(int sh,int sw,SDL_Renderer*renderer,const char*text,int y)
{
    pos.x=(sw/2)-w/2;
    pos.y=((y+sh)/2)-h/2;
    pos.h=h;
    pos.w=w;
    SDL_Surface *textsurface=NULL;
    TTF_Init();
    font=TTF_OpenFont("assets/font.ttf",50);
    textsurface=TTF_RenderText_Solid(font,text,textcolor);
    icon=SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_FreeSurface(textsurface);

    IMG_Init(IMG_INIT_JPG);

    SDL_Surface *temp=IMG_Load("assets/background.jpg");
    background=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);
    delete &font;
}

void PlayButton::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,background,NULL,&pos);
    SDL_RenderCopy(renderer,icon,NULL,&pos);

}
