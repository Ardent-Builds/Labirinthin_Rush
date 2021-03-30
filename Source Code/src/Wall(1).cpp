#include "Wall.h"

Wall::Wall()
{
    //ctor
}

Wall::~Wall()
{
    //dtor
}
void Wall::create(int x, int y, SDL_Renderer *renderer)
{


        SDL_Surface *temp;
        IMG_Init(IMG_INIT_JPG);
        temp=IMG_Load("assets/wall.jpg");

        icon=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_FreeSurface(temp);


    dimentions.x=x;
    dimentions.y=y;
    dimentions.h=h;
    dimentions.w=w;

    Object *wa=new Object;
    wa->type=ob_wall;
    wa->x1=x;
    wa->y1=y;
    wa->x2=x+w;
    wa->y2=y+h;
    Map.push_back(wa);

}
void Wall::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,icon,NULL,&dimentions);
}
