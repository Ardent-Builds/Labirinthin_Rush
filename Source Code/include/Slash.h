#ifndef SLASH_H
#define SLASH_H
#include "Bullet.h"

class Slash
{
    public:
        Slash();
        ~Slash();

        void newSlash(Direction d,int a, int b,SDL_Renderer *renderer);
        int move();
        void draw(SDL_Renderer *renderer);
        void destroy();


        SDL_Rect pos;
        int health=12;
        int speed=6;
        Direction dir=up;
        SDL_Texture *icon;
        bool friendly;
};

#endif // SLASH_H
