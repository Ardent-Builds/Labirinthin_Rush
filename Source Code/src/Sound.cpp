#include "Sound.h"
#include<SDL_mixer.h>
#include<iostream>

Sound::Sound()
{
    //ctor
}

Sound::~Sound()
{
    //dtor
}

void Sound::Load_all_sound()
{
    Sound::bgmus=Mix_LoadMUS("assets/bgmus.mp3");
    Sound::gunshot=Mix_LoadWAV("assets/gunshot.wav");
    Sound::spgunshot=Mix_LoadWAV("assets/spgunshot.wav");
    Sound::hit=Mix_LoadWAV("assets/hit.wav");
    Sound::win=Mix_LoadWAV("assets/win.wav");
    Sound::death=Mix_LoadWAV("assets/death.wav");
}

void Sound::Play_bgmus()
{
    Mix_PlayMusic(Sound::bgmus,-1);
}

void Sound::Play_gunshot()
{
    if(Sound::gunshot==NULL)
        std::cout<<"gun error";
    Mix_PlayChannel(-1,Sound::gunshot, 0);
}

void Sound::Play_spgunshot()
{
    if(Sound::gunshot==NULL)
        std::cout<<"spgun error";
    Mix_PlayChannel(-1,Sound::spgunshot,0);
}

void Sound::Free_audio()
{
    Mix_FreeMusic(Sound::bgmus);
    Mix_FreeChunk(Sound::gunshot);
    Mix_FreeChunk(Sound::spgunshot);
    Mix_FreeChunk(Sound::hit);
    Mix_FreeChunk(Sound::win);
    Mix_FreeChunk(Sound::death);
}


