#ifndef PORTAL_H
#define PORTAL_H
#include<SDL.h>
#include<SDL_image.h>
#include "../direction.h"


class Portal
{
    public:
        Portal();
        ~Portal();
        bool destructable=false;
        int countdown=0;
        void create(int x,int y,SDL_Renderer *renderer,bool des=false);
        void connect(Portal *port);
        void display(SDL_Renderer*renderer);
        void destroy();
        Portal *next;
        int h=30;
        int w=30;
        SDL_Rect pos;
        SDL_Texture *icon;
        Object *tracker=new Object;


};



#endif // PORTAL_H
extern std::list<Portal*>portals;
