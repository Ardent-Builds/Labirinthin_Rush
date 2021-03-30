#include "Menue.h"
#include<SDL_mixer.h>


Menue::Menue()
{
    lmenue=false;
}

Menue::~Menue()
{
    //dtor
}
void Menue::initialize(SDL_Renderer * renderer,bool p,bool c, bool n, bool lo)
{
    int i=p+c+n;
    IMG_Init(IMG_INIT_JPG);
    SDL_Surface *temp=IMG_Load("assets/background.jpg");
    background=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    int b=0;
    if(p)
    {
        play.init(750/i,1250,renderer,"play");
        b++;
    }
    if(c)
    {
        cont.init(750/i,1250,renderer,"continue",750*b);
        b++;
    }
    if(n)
    {
        cont.init(750/i,1250,renderer,"new game",750*b);
        b++;
    }
    /*if(lo)
    {
        loading.init(750/i,1250,renderer,"Loading",750*b);
        b++;
        std::cout<<"check";
    }*/
    pb=b,cb=c,nb=n;

    menueEnd=false;
    lmenue=false;

//    pRunning=true;
    //  isRunning=true;
}

void Menue::handleEvent(game*g,int max_lvl,int *l)
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
    case SDL_QUIT:
        g->pRunning=false;
        break;
    case SDL_KEYDOWN:
        if(e.key.keysym.sym==SDLK_ESCAPE)
            lmenue=false;
        break;

    case SDL_MOUSEBUTTONDOWN:


        int x,y;
        SDL_GetMouseState(&x,&y);

        if(!lmenue)
        {
            if(x>play.pos.x&&x<(play.pos.x+play.pos.w)&&y>play.pos.y&&y<(play.pos.y+play.pos.h))
                lmenue=true;

            if(x>cont.pos.x&&x<(cont.pos.x+cont.pos.w)&&y>cont.pos.y&&y<(cont.pos.y+cont.pos.h))
                menueEnd=true;
            if(x>next.pos.x&&x<(next.pos.x+next.pos.w)&&y>next.pos.y&&y<(next.pos.y+next.pos.h))
                menueEnd=true;
        }
        else
        {
            int ss=0;
            //std::cout<<ss;
            for(auto i:lvls)
            {
                ss++;
                std::cout<<ss;
                if(x>i->pos.x&&x<(i->pos.x+i->pos.w)&&y>i->pos.y&&y<(i->pos.y+i->pos.h))
                {
                    *l=ss;
                    std::cout<<ss;

                    menueEnd=true;
                    ss=0;
                    break;
                    //lmenue=false;
                }

            }

        }
    }

}

void Menue::display_lvls(int n,SDL_Renderer*renderer)
{
    lvls.clear();
    for(int i=0; i<n; i++)
    {

        IMG_Init(IMG_INIT_JPG);
        SDL_Surface *temp=IMG_Load("assets/background.jpg");
        background=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_FreeSurface(temp);
        PlayButton*tempb=new PlayButton;
        std::string str="Level "+its(i+1);
        tempb->init(720/n,1250,renderer,str.c_str(),(720*i)/n*2);
        lvls.push_back(tempb);
    }
}







void Menue::destroy()
{
    SDL_DestroyTexture(background);
    if(lmenue==false)
    {
        for(auto i:lvls)
            delete i;
        lvls.clear();
    }
}


void Menue::render(SDL_Renderer* renderer)
{

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    if(lmenue==false)
    {
        if(pb)
            play.display(renderer);
        if(cb)
            cont.display(renderer);
        if(nb)
            next.display(renderer);
        if(lb)
            loading.display(renderer);
    }
    else

        for(auto i:lvls)
        {
            i->display(renderer);
        }

    SDL_RenderPresent(renderer);
}
