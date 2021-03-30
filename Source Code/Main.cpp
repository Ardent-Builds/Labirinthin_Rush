#include"game.h"
#include"Menue.h"
#include<SDL_mixer.h>

const int winWidth=1260;
const int winHight= 720;
#include"level1.h"
inline void init();
Menue m;

int a=1;
int main(int argc, char* argv[])
{

    int max_lvl;
    FILE* fp;
    fp=fopen("assets/unlocked.lvl","r");
    fscanf(fp,"%d",&max_lvl);
    fclose(fp);

    const int fps=60;
    const int frameDelay=1000/60;

    Uint32 frameStart;
    int frameTime;

    bool running=true;



while(running)
{

    Level1 lv;
    init();

    lv.g.initialize("Labyrinthine Rush",1,22,winWidth,winHight,0);

    m.initialize(lv.g.renderer);
     int l;

    m.display_lvls(max_lvl,lv.g.renderer);
    while(!m.menueEnd&&lv.g.progRunning())
    {
        m.handleEvent(&lv.g,max_lvl,&l);
        m.render(lv.g.renderer);
    }
    m.destroy();

    //m.initialize(lv.g.renderer,0,0,0,1);

    //m.render(lv.g.renderer);



    lv.create(winWidth,winHight,l);



    //Mix_HaltMusic();
    if(lv.g.progRunning()==false)break;

    while(lv.g.running())
    {
        frameStart=SDL_GetTicks();


       if( lv.update())
       {
            m.initialize(lv.g.renderer,0,1,0,0);

            while(!m.menueEnd&&lv.g.progRunning())
            {
                m.handleEvent(&lv.g,max_lvl);
                m.render(lv.g.renderer);
            }
            m.destroy();
       }



        frameTime=SDL_GetTicks()-frameStart;

        if(frameTime<frameDelay)
        {
            SDL_Delay(frameDelay-frameTime);
        }

    }
    if(lv.g.player.complete)
    {
        l++;
        if(l>max_lvl&&l<=7)
        {
            max_lvl=l;
            fp=fopen("assets/unlocked.lvl","w");
            fprintf(fp,"%d",max_lvl);
            fclose(fp);
        }
    }


    running=lv.g.progRunning();
    Mix_CloseAudio();
    Mix_Quit();
    lv.destroy();
}
    return 0;
}



inline void init()
{
    Object bndUp, bndDn, bndLt, bndRt;
    bndDn.x1=-1000;
    bndDn.y1=winHight;
    bndDn.x2=1700;
    bndDn.y2=11000;
    bndUp.x1=-1000;
    bndUp.y1=-1000;
    bndUp.x2=winWidth+1000;
    bndUp.y2=0;
    bndLt.x1=-1000;
    bndLt.y1=-1000;
    bndLt.x2=0;
    bndLt.y2=2000;
    bndRt.x1=winWidth;
    bndRt.y1=-1000;
    bndRt.x2=1700;
    bndRt.y2=11000;

    bndDn.type=ob_wall;
    bndLt.type=ob_wall;
    bndUp.type=ob_wall;
    bndRt.type=ob_wall;

    Map.push_back(&bndDn);
    Map.push_back(&bndUp);
    Map.push_back(&bndLt);
    Map.push_back(&bndRt);
}
