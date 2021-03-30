#include "Monster.h"

Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}
void Monster::destroy()
{
    SDL_DestroyTexture(icon[0]);
    SDL_DestroyTexture(icon[1]);
    SDL_DestroyTexture(icon[2]);
    SDL_DestroyTexture(icon[3]);
    Map.remove(tracker);
    monsters.remove(this);
    delete this;
}
void Monster::create(int x, int y,Direction d,SDL_Renderer* renderer)
{
    pos.x=x;
    pos.y=y;
    pos.h=h;
    pos.w=w;
    dir=d;
    gun.dir=up;
    SDL_Surface *temp;
    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/monster_up.png");
    icon[0]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/monster_down.png");
    icon[1]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/monster_left.png");
    icon[2]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    IMG_Init(IMG_INIT_PNG);
    temp=IMG_Load("assets/monster_right.png");
    icon[3]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);


    tracker->x1=x;
    tracker->x2=x+w;
    tracker->y1=y;
    tracker->y2=y+h;
    tracker->type=ob_monster;
    health=5;
    Map.push_back(tracker);
}



void Monster::move()
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

                if(dir==up)dir=down;
                else if(dir==down)dir=up;
                else if(dir==left)dir=right;
                else if(dir==right)dir=left;
                return;
        }
        else if((i->x1)<(pos.x+x+w1)&&(i->y1)<(pos.y+y+h1)&&(i->x2)>(pos.x+x+w1)&&(i->y2)>(pos.y+y+h1))
        {

                if(dir==up)dir=down;
                else if(dir==down)dir=up;
                else if(dir==left)dir=right;
                else if(dir==right)dir=left;
                return;
        }
        else if((i->x1)<(pos.x+x+w2)&&(i->y1)<(pos.y+y+h2)&&(i->x2)>(pos.x+x+w2)&&(i->y2)>(pos.y+y+h2))
        {


                if(dir==up)dir=down;
                else if(dir==down)dir=up;
                else if(dir==left)dir=right;
                else if(dir==right)dir=left;
                return;
        }
    }





        pos.x+=x;
        pos.y+=y;
        tracker->x1+=x;
        tracker->x2+=x;
        tracker->y1+=y;
        tracker->y2+=y;

        //std::cout<<track->x1<<' '<<track->x2<<' '<<track->y1<<' '<<track->y2<<std::endl;


}


void Monster::draw(SDL_Renderer* renderer)
{
        switch (gun.dir)
    {
    case up:
        SDL_RenderCopy(renderer,icon[0],NULL,&pos);
        break;
    case down:
        SDL_RenderCopy(renderer,icon[1],NULL,&pos);
        break;
    case left:
        SDL_RenderCopy(renderer,icon[2],NULL,&pos);
        break;
    case right:
        SDL_RenderCopy(renderer,icon[3],NULL,&pos);
        break;
    default:
        SDL_RenderCopy(renderer,icon[0],NULL,&pos);

    }
}





std::list<Monster*>monsters;



int Monster::update(SDL_Renderer * renderer,SDL_Rect* ppos)
{

    if(health<=0)return 1;

    double dist=sqrt(fabs(ppos->x-pos.x)*fabs(ppos->x-pos.x)+fabs(ppos->y-pos.y)*fabs(ppos->y-pos.y));

    if(dist>300)
    {
        //gun.dir=dir;
        move();
        return 0;
    }



    double inf=9999;
    double slope=ppos->y-pos.y;
    double dev=ppos->x-pos.x;
    if(dev==0)slope=inf;
    else slope=slope/dev;
    double comp=1;



    if(slope<comp&&slope>-comp)
    {
        if(ppos->x<pos.x)
            gun.dir=left;
        else
            gun.dir=right;
    }
    else
    {
        if(ppos->y<pos.y)
            gun.dir=up;
        else  gun.dir=down;
    }

    if(dist<=80&&gun.scooldown==0)
    {
        gun.slash(pos.x,pos.y,renderer,false);
    }
    gun.shoot(pos.x,pos.y,renderer,false);

    move();




    //std::cout<<health<<'\n';
    return 0;
}
