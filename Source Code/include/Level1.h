#ifndef LEVEL1_H
#define LEVEL1_H
#include "game.h"


class Level1
{
    public:
        Level1();
        ~Level1();
        void create(int winWidth, int winHight,int lvl);
        int update();
        void destroy();



         game g;
};

#endif // LEVEL1_H
