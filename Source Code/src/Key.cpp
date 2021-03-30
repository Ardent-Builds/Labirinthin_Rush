#include "Key.h"

Key::Key()
{
    //ctor
}

Key::~Key()
{
    //dtor
}

void Key::create(int x, int y,SDL_Renderer *renderer)
{
    pos.x=x;
    pos.y=y;
    pos.w=w;
    pos.h=h;

    SDL_Surface *temp;
    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/key.png");
    icon=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);
    tracker->x1=x;
    tracker->y1=y;
    tracker->x2=x+w;
    tracker->y2=y+h;
    tracker->type=ob_key;
    Map.push_back(tracker);
}
void Key::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer,icon,NULL,&pos);
}
void Key::destroy()
{
    Map.remove(tracker);
    delete tracker;
    delete this;
}
