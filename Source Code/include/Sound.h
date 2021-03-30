#ifndef SOUND_H
#define SOUND_H
#include<SDL_mixer.h>


class Sound
{
    public:
        Sound();
        virtual ~Sound();

        void Load_all_sound();
        void Play_hit();
        void Play_bgmus();
        void Play_win();
        void Play_gunshot();
        void Play_spgunshot();
        void Play_death();

        void Free_audio();



    protected:

    public:
        Mix_Music *bgmus=NULL;
        Mix_Chunk *gunshot=NULL;
        Mix_Chunk *spgunshot=NULL;
        Mix_Chunk *hit=NULL;
        Mix_Chunk *death=NULL;
        Mix_Chunk *win=NULL;

};

#endif // SOUND_H
