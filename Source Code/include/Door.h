#ifndef DOOR_H
#define DOOR_H
#include"Player.h"

class Door
{
    public:
        Door();
        ~Door();
        void create(int x, int y, SDL_Renderer *renderer);
        void destroy();
        void draw(SDL_Renderer *renderer);

        SDL_Texture *icon;
        int h=30, w=30;
        Object *tracker=new Object;
        SDL_Rect pos;



};

#endif // DOOR_H
