#include "Gun.h"
#include<SDL_mixer.h>


Gun::Gun()
{
    //ctor
}

Gun::~Gun()
{
    //dtor
}


void Gun::shoot(int x, int y, SDL_Renderer *renderer,bool friendly)
{

    if(cooldown>0) return;
    cooldown++;
     sound.Play_spgunshot();

    Bullet *temp=new Bullet();
    temp->friendly=friendly;
    temp->newBullet(dir,x,y,renderer);
    bullets.push_back(temp);
}


int Gun::slash(int x, int y, SDL_Renderer *renderer,bool friendly)
{
    if(scooldown>0)return 1;
    scooldown++;
    sound.Play_gunshot();

    Slash *temp=new Slash();
    temp->friendly=friendly;
    temp->newSlash(dir,x,y,renderer);
    slashes.push_back(temp);
    return 0;
}




void Gun::update(SDL_Renderer *renderer)
{

    if(cooldown>=30)
        cooldown=0;
    if(cooldown!=0)
        cooldown++;

    if(scooldown>=80)scooldown=0;
    if(scooldown!=0)scooldown++;


    for(auto i:bullets)
    {
        int j=i->move();
        if(j==0)
        {
            bullets.remove(i);
            i->destroy();
            continue;
        }

        i->draw(renderer);
    }

        for(auto i:slashes)
    {
        int j=i->move();
        if(j==0)
        {
            slashes.remove(i);
            i->destroy();
            continue;
        }

        i->draw(renderer);
    }
}
