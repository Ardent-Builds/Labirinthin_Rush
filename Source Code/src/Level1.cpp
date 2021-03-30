#include "Level1.h"

Level1::Level1()
{
    //ctor
}

Level1::~Level1()
{
    //dtor
}

void Level1::create(int winWidth, int winHight,int lvl)
{
    std::string str="Level "+its(lvl);
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *temp=IMG_Load("assets/loading.jpg");
    SDL_Surface *cir=IMG_Load("assets/loading.png");
    SDL_Texture *tp=SDL_CreateTextureFromSurface(g.renderer, temp);
    SDL_Texture *lo=SDL_CreateTextureFromSurface(g.renderer, cir);
    SDL_FreeSurface(temp);
    SDL_FreeSurface(cir);
    SDL_Rect cirl;
    cirl.h=350;
    cirl.w=350;
    cirl.x=630-175;
    cirl.y=360-175;
    int ang=0,frameStart,frameTime,frameDelay=1000/300;

    str="assets/"+its(lvl)+".lvl";
    std::cout<<"\n"<<str<<"\n";
    int x=0,y=0;
    FILE *fp;
    fp=fopen(str.c_str(),"r");
    char ch;
    int port[10][2]={};
    int Dport[10][2]={};
    g.lvl=lvl;
    while(1)
    {
        frameStart=SDL_GetTicks();
        SDL_RenderClear(g.renderer);
        SDL_RenderCopy(g.renderer,tp,NULL,NULL);
        SDL_RenderCopyEx(g.renderer,lo,NULL,&cirl,ang,NULL,SDL_FLIP_NONE);
        SDL_RenderPresent(g.renderer);
        ang+=5;
        if(ang>=360)
            ang=0;
        ch=fgetc(fp);
        if(ch==' ')x+=30;
        if(ch== ',')
        {
            y+=30;
            x=0;
        }
        if(ch=='.')
            {g.makeWall(x,y);
            x+=30;}

       if(ch== 'x')
            {g.makeMonster(x,y,up);
            x+=30;}
        if(ch== 'X')
            {g.makeMonster(x,y,left);
            x+=30;}
        if(ch=='k')
        {
            g.key.create(x,y,g.renderer);
            x+=30;
        }
        if(ch=='c')
        {
            g.door.create(x,y,g.renderer);
            x+=30;
        }
        if(ch>='0'&&ch<='9')
        {
            if(port[ch-'0'][0])
            {
                g.makePortal(port[ch-'0'][0],port[ch-'0'][1],x,y,0);
                x+=30;
            }
            else
            {port[ch-'0'][0]=x; port[ch-'0'][1]=y;x+=30;}
        }
        if(ch>='A'&&ch<='J')
        {
            if(Dport[ch-'A'][0])
            {
                g.makePortal(Dport[ch-'A'][0],Dport[ch-'A'][1],x,y,1);
                x+=30;
            }
            else
            {Dport[ch-'A'][0]=x; Dport[ch-'A'][1]=y;x+=30;}
        }

        if(ch==EOF)break;

        frameTime=SDL_GetTicks()-frameStart;

        if(frameTime<frameDelay)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }
    SDL_DestroyTexture(lo);
    SDL_DestroyTexture(tp);
    fclose(fp);

}

int Level1::update()
{

        g.handleEvent();
      int i=  g.handleKeyboard();
        g.update();
        g.render();
        return i;

}
void Level1::destroy()
{
    g.destroy();
    //delete &g;
}
