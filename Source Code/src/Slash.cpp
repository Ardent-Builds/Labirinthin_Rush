#include "Slash.h"




Slash::Slash()
{

}

Slash::~Slash()
{
    //dtor
}

void Slash::newSlash(Direction d, int a, int b, SDL_Renderer *renderer)
{
    IMG_Init(IMG_INIT_PNG);
    pos.x=a;
    pos.y=b;
    pos.h=30;
    pos.w=30;
    SDL_Surface *temp=NULL;
    if(d==up)
    {
        //pos.y-=10;
        temp=IMG_Load("assets/slash_up.png");

    }
    else if(d==down)
    {
        //pos.y+=10;
        temp=IMG_Load("assets/slash_down.png");
    }
    else if(d==left)
    {
        //pos.x-=10;
        temp=IMG_Load("assets/slash_left.png");
    }
    else{
        //pos.x+=10;
        temp=IMG_Load("assets/slash_right.png");
    }

        icon=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_FreeSurface(temp);


    dir=d;

    SDL_RenderCopy(renderer,icon,NULL,&pos);


}



int Slash::move()
{
    health--;
    if(health<=0)return 0;

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
                if(i->type==ob_player && friendly==false)
                {
                    damageBuffer*dmg=new damageBuffer;
                    dmg->player=true;
                    damage.push_back(dmg);
                    damageBuffer*dmg1=new damageBuffer;
                    dmg1->player=true;
                    damage.push_back(dmg1);
                    damageBuffer*dmg2=new damageBuffer;
                    dmg2->player=true;
                    damage.push_back(dmg2);
                }
                else if(i->type==ob_monster)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    damageBuffer* db1=new damageBuffer;
                    db1->player=false;
                    db1->x=i->x1;
                    db1->y=i->y1;
                    damage.push_back(db1);
                    damageBuffer* db2=new damageBuffer;
                    db2->player=false;
                    db2->x=i->x1;
                    db2->y=i->y1;
                    damage.push_back(db2);
                }

                return 0;

        }
        else if((i->x1)<(pos.x+x+w1)&&(i->y1)<(pos.y+y+h1)&&(i->x2)>(pos.x+x+w1)&&(i->y2)>(pos.y+y+h1))
        {
                if(i->type==ob_player && friendly==false)
                {
                    damageBuffer*dmg=new damageBuffer;
                    dmg->player=true;
                    damage.push_back(dmg);
                    damageBuffer*dmg1=new damageBuffer;
                    dmg1->player=true;
                    damage.push_back(dmg1);
                    damageBuffer*dmg2=new damageBuffer;
                    dmg2->player=true;
                    damage.push_back(dmg2);
                }
                else if(i->type==ob_monster)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    damageBuffer* db1=new damageBuffer;
                    db1->player=false;
                    db1->x=i->x1;
                    db1->y=i->y1;
                    damage.push_back(db1);
                    damageBuffer* db2=new damageBuffer;
                    db2->player=false;
                    db2->x=i->x1;
                    db2->y=i->y1;
                    damage.push_back(db2);
                }

                return 0;
        }
        else if((i->x1)<(pos.x+x+w2)&&(i->y1)<(pos.y+y+h2)&&(i->x2)>(pos.x+x+w2)&&(i->y2)>(pos.y+y+h2))
        {
                if(i->type==ob_player && friendly==false)
                {
                    damageBuffer*dmg=new damageBuffer;
                    dmg->player=true;
                    damage.push_back(dmg);
                    damageBuffer*dmg1=new damageBuffer;
                    dmg1->player=true;
                    damage.push_back(dmg1);
                    damageBuffer*dmg2=new damageBuffer;
                    dmg2->player=true;
                    damage.push_back(dmg2);
                }
                else if(i->type==ob_monster)
                {
                    damageBuffer* db=new damageBuffer;
                    db->player=false;
                    db->x=i->x1;
                    db->y=i->y1;
                    damage.push_back(db);
                    damageBuffer* db1=new damageBuffer;
                    db1->player=false;
                    db1->x=i->x1;
                    db1->y=i->y1;
                    damage.push_back(db1);
                    damageBuffer* db2=new damageBuffer;
                    db2->player=false;
                    db2->x=i->x1;
                    db2->y=i->y1;
                    damage.push_back(db2);
                }
                return 0;
        }
    }

        pos.x+=x;
        pos.y+=y;
        return true;

}


void Slash::draw(SDL_Renderer *renderer)
{


    SDL_RenderCopy(renderer,icon,NULL,&pos);
}

void Slash::destroy()
{

    SDL_DestroyTexture(icon);
    delete this;
}

