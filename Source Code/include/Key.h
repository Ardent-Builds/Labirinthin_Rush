#ifndef KEY_H
#define KEY_H
#include<SDL.h>
#include<SDL_image.h>
#include"Portal.h"

class Key
{
    public:
        Key();
        ~Key();
        void create(int x, int y, SDL_Renderer * renderer);

        void destroy();
        void draw(SDL_Renderer* renderer);

        int h=20;
        int w=20;
        SDL_Texture *icon;
        Object *tracker=new Object;
        SDL_Rect pos;

};

#endif // KEY_H
