#include<bits/stdc++.h>
#include"Sound.h"
enum Direction
{
    up,down,left,right
};

enum Objects
{
   ob_empty, ob_player, ob_wall,ob_monster, ob_bullet, ob_portal, ob_key, ob_door, ob_portal2
};


struct Object
{
    int x1,y1,x2,y2;
    Objects type;
};

struct damageBuffer
{
    bool player;//if true player takes damage, else monster
    int x,y;

};



extern Sound sound;

extern std::list<damageBuffer*> damage;
extern std::list<Object*> Map;

