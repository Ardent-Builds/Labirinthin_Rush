#include "game.h"


std::string its(int n)
{
    std::stringstream out;
    std::string s;
    out<<n;
    out>>s;
    return s;
}



game::game()
{
}

game::~game()
{
}
void game::makePortal(int x1, int y1, int x2, int y2,bool d)
{
    Portal* p1=new Portal;
    p1->create(x1,y1,renderer,d);
    Portal* p2=new Portal;
    p2->create(x2,y2,renderer,d);
    p1->connect(p2);
    portals.push_back(p1);
    portals.push_back(p2);

}
void game::makeWall(int x,int y)
{
    Wall *wall=new Wall;
    wall->create(x,y,renderer);
    walls.push_back(wall);
}
void game::makeMonster(int x,int y, Direction d)
{
    Monster *mon=new Monster;
    mon->create(x,y,d,renderer);
    monsters.push_back(mon);
}


void game::initialize(const char * title, int x, int y, int w, int h, int flag)
{


        winWidth=w,winHight=h;


        SDL_Init(SDL_INIT_EVERYTHING);
        if(flag==1)
            flag=SDL_WINDOW_FULLSCREEN;

        window = SDL_CreateWindow(title,x,y,w,h,flag);
        win_created=1;
        renderer=SDL_CreateRenderer(window,-1,0);



    //audio
    if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 16000)<0)
        std::cout<<"Audio opening failed\n";
    Mix_Init(MIX_INIT_MP3);
    sound.Load_all_sound();

    Mix_AllocateChannels(6);
    sound.Play_bgmus();

    //Mix_FreeMusic( bgmus );


    IMG_Init(IMG_INIT_JPG);
    SDL_Surface *temp=IMG_Load("assets/background.jpg");
    background=SDL_CreateTextureFromSurface(renderer,temp);
    SDL_FreeSurface(temp);

    //makeWall(1050,0,750,20,0);

    isRunning=true;
    player.initialize(renderer);

//    key.create(300,300,renderer);
//    door.create(300,400,renderer);
    pRunning=true;


}
void game::update()
{
    std::string temp;
    temp="Health: "+its(player.health);
    HUD.push_back(temp);

    temp="Kills: "+its(kill);
    HUD.push_back(temp);

    temp="Time: "+its(frames/(60*60))+":"+its((frames/60)%60);
    HUD.push_back(temp);

    temp="Key: ";
    if(player.key)
        temp+="Yes";
    else temp+="No";
    HUD.push_back(temp);
    temp="Instruction: ";
    HUD.push_back(temp);
    temp=" Up    = arrow_up";
    HUD.push_back(temp);
    temp=" Down  = arrow_down";
    HUD.push_back(temp);
    temp=" Left  = arrow_left";
    HUD.push_back(temp);
    temp=" Right = arrow_right";
    HUD.push_back(temp);
    temp=" Shoot = 'x'";
    HUD.push_back(temp);
    temp=" Close Shot = 'z'";
    HUD.push_back(temp);


    frames++;
    for(auto i:damage)
    {
        if(i->player)
            player.health--;
        else
        {
            //std::cout<<"else";
            for(auto j:monsters)
            {
                if(j->pos.x==i->x && j->pos.y==i->y)
                {
                    j->health--;
                }
            }
        }
        damage.remove(i);
    }

    if(player.key==true &&keydestroyed==0)
    {
        key.destroy();
        keydestroyed=1;
    }
    if(player.complete==true)
    {
        //std::cout<<lvl;
        std::string path="assets/"+its(lvl)+".score";
        //std::cout<<"\n"<<path;
        Mix_PlayChannel(-1,sound.win,0);
        FILE *fp=fopen(path.c_str(),"r");
        int high;
        fscanf(fp,"%d",&high);
        frames=frames/60;
        fclose(fp);
        frames=ceil(frames/30.0);
        if(frames<=1)frames=1;

        score=(kill*100+(player.health*8)/frames);
        if(high<score)high=score;
        std::string text;
        text="Congratulations!!! Level completed!!! \nYou scored: ";
        text=text+its(score);
        text+="\nHigh Score: ";
        text+=its(high);

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Level completed",
                         text.c_str(),
                         window);
        isRunning=false;
        fp=fopen(path.c_str(),"w");
        fprintf(fp,"%d",high);
        fclose(fp);

    }
    if(player.health<=0)
    {
        Mix_PlayChannel(-1,sound.death,0);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Game Over",
                         "Noob!!! You died!!!",
                         window);
        isRunning=false;
    }


}
void game::render()
{

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);

    hud.display(renderer,&HUD,winWidth,winHight);

    HUD.clear();


    for(auto i:walls)
    {
        i->draw(renderer);
    }





    for(auto i:portals)
        i->display(renderer);
//    monster.update(renderer);
//    monster.gun.update(renderer);

    player.draw(renderer);


    for(auto i:monsters)
    {
        i->draw(renderer);
        if(i->update(renderer,&player.pos)==1)
        {
            i->destroy();
            kill++;
            continue;

        }
        i->gun.update(renderer);

    }




    if(!player.key)
    key.draw(renderer);
    door.draw(renderer);

    player.gun.update(renderer);

    SDL_RenderPresent(renderer);
}

int game::handleKeyboard()
{
    const Uint8 *state=SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_UP])
    {
        player.dir=up;
        if(player.shooting==false)
            player.gun.dir=player.dir;

        player.move();
    }
    if(state[SDL_SCANCODE_DOWN])
    {
        player.dir=down;
        if(player.shooting==false)
            player.gun.dir=player.dir;
        player.move();
    }
    if(state[SDL_SCANCODE_LEFT])
    {
        player.dir=left;
        if(player.shooting==false)
            player.gun.dir=player.dir;
        player.move();
    }
    if(state[SDL_SCANCODE_RIGHT])
    {
        player.dir=right;
        if(player.shooting==false)
            player.gun.dir=player.dir;
        player.move();
    }
    if(state[SDL_SCANCODE_X])
    {
        player.shooting=true;
        player.gun.shoot(player.pos.x,player.pos.y,renderer);

    }
    else
        player.shooting=false;

    if(state[SDL_SCANCODE_Z])
       {
           player.gun.slash(player.pos.x,player.pos.y,renderer,1);
       }

    if(state[SDL_SCANCODE_ESCAPE])
        return 1;

    return 0;

}






void game::handleEvent()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
    case SDL_QUIT:
        isRunning=false;
        pRunning=false;
        break;
    }

}

void game::destroy()
{
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    for(auto i:monsters)
    {
        monsters.remove(i);
        delete i;
        //std::cout<<"done";
    }
    for(auto i:damage)
    {
        damage.remove(i);
        delete i;
        //std::cout<<"done";
    }
    for(auto i:Map)
    {
        Map.remove(i);
        delete i;
        //std::cout<<"done";
    }
    for(auto i:portals)
    {
        portals.remove(i);
        delete i;
        //std::cout<<"done";
    }
    for(auto i:walls)
    {
        walls.remove(i);
        delete i;
        //std::cout<<"done";
    }

    SDL_DestroyTexture(player.icon[0]);
    SDL_DestroyTexture(player.icon[1]);
    SDL_DestroyTexture(player.icon[2]);
    SDL_DestroyTexture(player.icon[3]);
    SDL_DestroyTexture(key.icon);
    SDL_DestroyTexture(door.icon);
    delete &key;
    delete &player;
    delete &door;
    //std::cout<<"done";

    SDL_Quit();
}
