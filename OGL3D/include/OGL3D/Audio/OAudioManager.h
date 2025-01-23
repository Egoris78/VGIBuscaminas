#pragma once
#include <vector>

#include <SDL.h>
#undef main
#include <SDL_mixer.h>

class OAudioManager
{
public:
    OAudioManager();
    ~OAudioManager();

    void addSoundEffect(const char* path);

    void playSoundEffect(const int which, const int loops) const;

private:
    std::vector<Mix_Chunk*> mSoundEffectBank;
};
