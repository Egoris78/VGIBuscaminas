#include <OGL3D/Audio/OAudioManager.h>

#include <assert.h>

#include <SDL.h>
#undef main
#include <SDL_mixer.h>

OAudioManager::OAudioManager()
{
    // init sound
    SDL_Init(SDL_INIT_AUDIO);

    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 2048;

    assert(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) == 0);
}

OAudioManager::~OAudioManager()
{
    SDL_Quit();
}

void OAudioManager::addSoundEffect(const char* path)
{
    Mix_Chunk* tmpChunk = Mix_LoadWAV(path);

    if (tmpChunk != nullptr)
        mSoundEffectBank.push_back(tmpChunk);
    else
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init audio: %s", Mix_GetError());
}

void OAudioManager::playSoundEffect(const int which, const int loops) const
{
    if (mSoundEffectBank.empty())
        return;
    if (which <= mSoundEffectBank.size() - 1)
        Mix_PlayChannel(-1, mSoundEffectBank[which], loops);
}
