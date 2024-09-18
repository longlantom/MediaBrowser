// Player.cpp
#include "Player.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <thread>

void Player::playMusic() {
    std::cout << "Enter track path: ";
    std::cin >> currentTrack;

    std::thread playThread(&Player::playThread, this);
    playThread.detach();
}

void Player::playThread() {
    if (SDL_Init(SDL_INIT_AUDIO) != 0) { // Initialize SDL
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) { // Initialize SDL_mixer
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        SDL_Quit();
        return;
    }

    Mix_Music *music = Mix_LoadMUS(currentTrack.c_str());
    if (music == NULL) {
        fprintf(stderr, "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // Set volume to 50%
    
    Mix_PlayMusic(music, -1);

    //Mix_FreeMusic(music);
    //Mix_CloseAudio();
    //SDL_Quit();
}

void Player::changeVolume() {
    std::cout << "Enter new volume (0-128): ";
    std::cin >> volume;
    // Set SDL volume
    Mix_VolumeMusic(volume);
}
