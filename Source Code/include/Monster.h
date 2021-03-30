#ifndef MONSTER_H
#define MONSTER_H
#include"Gun.h"


class Monster
{
    public:
        Monster();
        ~Monster();
        void create(int x, int y, Direction d, SDL_Renderer *renderer );
        int update(SDL_Renderer * renderer,SDL_Rect *ppos);
        void destroy();
        void move();
        void draw(SDL_Renderer* renderer);

        Object *tracker=new Object;
        Gun gun;
        SDL_Rect pos;
        SDL_Texture *icon[4];
        int speed=3;
        Direction dir;
        int h=30,w=30;
        int health;

};

#endif // MONSTER_H
extern std::list<Monster*>monsters;
