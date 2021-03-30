#include "Bullet.h"
#include<SDL_mixer.h>


std::list<damageBuffer*> damage;
std::list<Object*>Map;
Sound sound;
Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::newBullet(Direction d, int a, int b, SDL_Renderer *renderer)
{
    IMG_Init(IMG_INIT_PNG);
    pos.x=a;
    pos.y=b;
     SDL_Surface *temp=NULL;
    if(d==up||d==down)
    {
        pos.h=13;
        pos.w=9;



        temp=IMG_Load("assets/bullet_up.png");

        if(d==up)
        {
            pos.x+=16;
            pos.y-=10;
        }
        else
        {
            pos.y+=15;
            pos.x+=6;
        }
    }
    else
    {
        pos.h=6;
        pos.w=18;

        if(d==left)
        {

            pos.x-=10;
            pos.y+=6;
        }
        else
        {

            pos.x+=15;
            pos.y+=16;
        }

        temp=IMG_Load("assets/bullet_left.png");

    }

    icon=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_FreeSurface(temp);


    dir=d;
    SDL_RenderCopy(renderer,icon,NULL,&pos);


}



int Bullet::move()
{
    int y=0,x=0,h=0,w=0,h1=0,w1=0;


    switch(dir)
    {
    case up:
        y-=speed;
        w1=pos.w;
        break;
    case down:
        y+=speed;
        h=pos.h;
        h1=pos.h;
        w1=pos.w;
        break;
    case left:
        x-=speed;
        h1=pos.h;
        break;
    case right:
        x+=speed;
        w=pos.w;
        w1=pos.w;
        h1=pos.h;
        break;
    }

    int h2=(h1+h)/2.0, w2=(w1+w)/2.0;
    for(auto i:Map)
    {
        if((i->x1)<(pos.x+x+w)&&(i->y1)<(pos.y+y+h)&&(i->x2)>(pos.x+x+w)&&(i->y2)>(pos.y+y+h))
        {
            switch(i->type)
            {
            case ob_wall:
                return 0;
            case ob_key:
                return 0;
            case ob_door:
                    return 0;
            case ob_monster:

                if(friendly==1)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }
                return 0;
            case ob_portal:
                return 0;
            case ob_portal2:
                return 0;
            case ob_player:
                if(friendly==0)
                {
                    damageBuffer*db=new damageBuffer;
                    db->player=true;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }

                return 0;
            }
        }
        else if((i->x1)<(pos.x+x+w1)&&(i->y1)<(pos.y+y+h1)&&(i->x2)>(pos.x+x+w1)&&(i->y2)>(pos.y+y+h1))
        {
            switch(i->type)
            {
            case ob_wall:
                return 0;
            case ob_key:
                return 0;
            case ob_door:
                    return 0;
            case ob_monster:
                if(friendly==1)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }
                return 0;
            case ob_portal:
                return 0;
            case ob_portal2:
                return 0;
            case ob_player:
                if(friendly==0)
                {
                    damageBuffer*db=new damageBuffer;
                    db->player=true;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }
                return 0;
            }
        }
        else if((i->x1)<(pos.x+x+w2)&&(i->y1)<(pos.y+y+h2)&&(i->x2)>(pos.x+x+w2)&&(i->y2)>(pos.y+y+h2))
        {
            switch(i->type)
            {
            case ob_wall:
                return 0;
            case ob_key:
                return 0;
            case ob_door:
                    return 0;
            case ob_monster:
                if(friendly==1)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }
                return 0;
            case ob_portal:
                return 0;
            case ob_portal2:
                return 0;
            case ob_player:
                if(friendly==0)
                {
                    damageBuffer*db=new damageBuffer;
                    db->player=true;
                    damage.push_back(db);
                    Mix_PlayChannel(-1, sound.hit, 0);
                }
                return 0;
            }
        }
    }

        pos.x+=x;
        pos.y+=y;
        return true;

}


void Bullet::draw(SDL_Renderer *renderer)
{


    SDL_RenderCopy(renderer,icon,NULL,&pos);
}

void Bullet::destroy()
{

    SDL_DestroyTexture(icon);
    delete this;
}

