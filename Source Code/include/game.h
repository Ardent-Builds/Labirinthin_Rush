#ifndef GAME_H
#define GAME_H
#include<bits/stdc++.h>
#include<sdl.h>
#include<SDL_image.h>
#include<Player.h>
#include<SDL_mixer.h>
#include"Wall.h"
#include"Monster.h"
#include"Key.h"
#include"Door.h"
#include"Hud.h"
#include"Sound.h"
class game
{
    public:
        int lvl;
        game();
        ~game();
        void initialize(const char * title, int x, int y, int w, int h, int flag=0);
        void handleEvent();
        int handleKeyboard();
        void update();
        void render();
        void destroy();
        bool running(){return isRunning;}
        void makeWall(int x, int y);
        void makeMonster(int x, int y, Direction d);
        void makePortal(int x1, int y1, int x2, int y2, bool d=false);
        bool progRunning(){return pRunning;}

        Key key;
        Door door;
        Player player;

        SDL_Window *window=NULL;
        SDL_Renderer *renderer=NULL;
        int winWidth,winHight;
        bool isRunning;
        SDL_Texture *background;
        std::list<Wall*>walls;
        //Monster monster;
        int score=0,kill=0;
        long long int frames=0;
        bool keydestroyed=0;
        Hud hud;
        std::list<std::string> HUD;
        bool win_created=0;
        bool pRunning=true;

};

#endif // GAME_H
extern std::string its(int n);
