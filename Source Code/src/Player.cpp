#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::initialize(SDL_Renderer *renderer)
{

    SDL_Surface *temp;

    IMG_Init(IMG_INIT_PNG);

    temp=IMG_Load("assets/player_up.png");

    icon[up]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

       temp=IMG_Load("assets/player_down.png");

    icon[down]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

       temp=IMG_Load("assets/player_left.png");

    icon[left]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

       temp=IMG_Load("assets/player_right.png");

    icon[right]=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    pos.h=30;
    pos.w=30;
    pos.x=0;
    pos.y=0;

    track->x1=pos.x;
    track->x2=pos.x+pos.w;
    track->y1=pos.y;
    track->y2=pos.y+pos.h;
    track->type=ob_player;
    Map.push_back(track);

}

void Player::port(int x,int y)
{

//    int l=0,m=0;
//
//
//    if(dir==left)
//    l=-30;
//    else if(dir==right) l=+30;
//    else if(dir==up) m=-30;
//    else m=+30;

    pos.x=x;
    pos.y=y;
    track->x1=x;
    track->y1=y;
    track->x2=track->x1+pos.w;
    track->y2=track->y1+pos.h;
}

void Player::draw(SDL_Renderer *renderer)
{

    //std::cout<<health<<'\n';
    if(gun.dir==up)
    SDL_RenderCopy(renderer,icon[up],NULL,&pos);
    else if(gun.dir==down)
    SDL_RenderCopy(renderer,icon[down],NULL,&pos);
    else if(gun.dir==left)
    SDL_RenderCopy(renderer,icon[left],NULL,&pos);
    else if(gun.dir==right)
    SDL_RenderCopy(renderer,icon[right],NULL,&pos);
}

void Player::move()
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
                return;
            case ob_key:
                key=true;
                break;
            case ob_door:
                if(key)complete=true;
                    return;
            case ob_monster:
                return;
            case ob_portal:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  &&  j->pos.y==i->y1)
                    {
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            case ob_portal2:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  && j->pos.y==i->y1)
                    {
                        j->countdown++;
                        j->next->countdown++;
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            }
        }
        else if((i->x1)<(pos.x+x+w1)&&(i->y1)<(pos.y+y+h1)&&(i->x2)>(pos.x+x+w1)&&(i->y2)>(pos.y+y+h1))
        {
            switch(i->type)
            {
            case ob_wall:
                return;
            case ob_key:
                key=true;
                break;
            case ob_door:
                if(key)complete=true;
                return;
            case ob_monster:
                return;
            case ob_portal:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  &&  j->pos.y==i->y1)
                    {
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            case ob_portal2:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  && j->pos.y==i->y1)
                    {
                        j->countdown++;
                        j->next->countdown++;
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            }
        }
        else if((i->x1)<(pos.x+x+w2)&&(i->y1)<(pos.y+y+h2)&&(i->x2)>(pos.x+x+w2)&&(i->y2)>(pos.y+y+h2))
        {
            switch(i->type)
            {
            case ob_wall:
                return;
            case ob_key:
                key=true;
                break;
            case ob_door:
                if(key)complete=true;
                    return;
            case ob_monster:
                return;
            case ob_portal:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  &&  j->pos.y==i->y1)
                    {
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            case ob_portal2:
                for(auto j:portals)
                {
                    if(j->pos.x==i->x1  && j->pos.y==i->y1)
                    {
                        j->countdown++;
                        j->next->countdown++;
                        port(j->next->pos.x,j->next->pos.y);
                        break;
                    }
                }
                return;
            }
        }
    }



        //if(complete==true)std::cout<<"key";

        pos.x+=x;
        pos.y+=y;
        track->x1+=x;
        track->x2+=x;
        track->y1+=y;
        track->y2+=y;

        //std::cout<<track->x1<<' '<<track->x2<<' '<<track->y1<<' '<<track->y2<<std::endl;


}



