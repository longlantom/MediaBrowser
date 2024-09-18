/*
Create a CLI application for Linux that serves as a basic media files and video files browser/player(advance) using C/C++
[BASIC]
1. Your application should be able to runs :
	1- From any directory on your computer
	2- From external: USB ( must to mount device and parse file in USB) 
2. Avaiable options:
	1 - View list of media files in that folder and all sub-folder (audio and video)
		+ Pagination, 25 per page
	2 - Playlists:
		+ List of playlist
		+ View a playlist
		+ Create/Update/Delete a playlist
	3 - Metadata of a file (Taglib): [MAIN FEATURE]
		+ Available from either media list or a playlist
		+ Show metadata of a media file (pretty much anything you can think of as metadata): 
			Audio: Track name, Album, Artist, Duration, Genre, Publisher, Publish Year,...
			Video: Name, Size, Duration, Bitrate, Codec, 
		+ Edit metadata: change value, add new keys,...
 
 
	4 - Play music from your application using SDL2 libary on other thread.
		+ Play/Pause
		+ Next/Previous
		+ automatically move to the next song when current song finish
		+ Display current time and duration time
 
 
	5 - Can change volume of device
*/

/*
g++ -o MediaBrowser main.cpp MediaManager.cpp PlaylistManager.cpp Player.cpp -ltag -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_mixer -std=c++17 && ./MediaBrowser
*/ 

#include <iostream>
#include "MediaManager.h"
#include "PlaylistManager.h"
#include "Player.h"

void showMenu() {
    std::cout << "1. View list of media files\n";
    std::cout << "2. Playlists\n";
    std::cout << "3. Show Metadata of a file\n";
    std::cout << "4. Edit Metadata of a file\n";
    std::cout << "5. Play music\n";
    std::cout << "6. Change volume\n";
    std::cout << "7. Exit\n";
}

int main() {
    MediaManager mediaManager;
    PlaylistManager playlistManager;
    Player player;
    int choice;
    
    do {
        showMenu();
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                mediaManager.listMediaFiles();
                break;
            case 2:
                playlistManager.managePlaylists();
                break;
            case 3:
                mediaManager.showMetadata();
                break;
            case 4:
                mediaManager.editMetadata();
                break;
            case 5:
                player.playMusic();
                break;
            case 6:
                player.changeVolume();
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}
