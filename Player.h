// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    void playMusic();
    void changeVolume();
private:
    void playThread();
    std::string currentTrack;
    int volume;
};

#endif // PLAYER_H
