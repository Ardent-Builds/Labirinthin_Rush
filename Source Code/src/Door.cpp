#include "Door.h"

Door::Door()
{
    //ctor
}

Door::~Door()
{
    //dtor
}
void Door::create(int x, int y,SDL_Renderer *renderer)
{
    pos.x=x;
    pos.y=y;
    pos.w=w;
    pos.h=h;

    SDL_Surface *temp;
    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/chest.png");
    icon=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);
    tracker->x1=x;
    tracker->y1=y;
    tracker->x2=x+w;
    tracker->y2=y+h;
    tracker->type=ob_door;
    Map.push_back(tracker);
}
void Door::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer,icon,NULL,&pos);
}
void Door::destroy()
{
    Map.remove(tracker);
    delete tracker;
    delete this;
}
