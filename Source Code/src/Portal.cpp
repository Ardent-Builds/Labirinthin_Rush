#include "Portal.h"

Portal::Portal()
{
    //ctor
}

Portal::~Portal()
{
    //dtor
}

void Portal::create(int x,int y,SDL_Renderer *renderer,bool des)
{
    pos.x=x;
    pos.y=y;
    pos.h=h;
    pos.w=w;

    destructable=des;

    SDL_Surface *temp;
    IMG_Init(IMG_INIT_PNG);
    if(des)
    temp=IMG_Load("assets/portal_2.png");
    else temp=IMG_Load("assets/portal.png");

    icon=SDL_CreateTextureFromSurface(renderer,temp);

    tracker->x1=x;
    tracker->x2=x+w;
    tracker->y1=y;
    tracker->y2=y+h;
    if(des)
    tracker->type=ob_portal2;
    else tracker->type=ob_portal;
    Map.push_back(tracker);

}
void Portal::display(SDL_Renderer*renderer)
{
    if(countdown>180)
    {destroy();return;}
    else if(countdown>0)
        countdown++;
    SDL_RenderCopy(renderer,icon,NULL,&pos);
}

void Portal::connect(Portal* port)
{
    next=port;
    port->next=this;
}
std::list<Portal*>portals;



void Portal::destroy()
{
    SDL_DestroyTexture(icon);
    Map.remove(tracker);
    portals.remove(this);
    delete this;
}
