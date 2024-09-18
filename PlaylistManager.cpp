// PlaylistManager.cpp
#include "PlaylistManager.h"
#include <iostream>

void PlaylistManager::managePlaylists() {
    int choice;
    std::string name;

    std::cout << "1. List playlists\n";
    std::cout << "2. View a playlist\n";
    std::cout << "3. Create a playlist\n";
    std::cout << "4. Update a playlist\n";
    std::cout << "5. Delete a playlist\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            listPlaylists();
            break;
        case 2:
            std::cout << "Enter playlist name: ";
            std::cin >> name;
            viewPlaylist(name);
            break;
        case 3:
            std::cout << "Enter new playlist name: ";
            std::cin >> name;
            createPlaylist(name);
            break;
        case 4:
            std::cout << "Enter playlist name: ";
            std::cin >> name;
            updatePlaylist(name);
            break;
        case 5:
            std::cout << "Enter playlist name: ";
            std::cin >> name;
            deletePlaylist(name);
            break;
        default:
            std::cout << "Invalid choice\n";
    }
}

void PlaylistManager::listPlaylists() {
    std::cout << "Playlists:\n";
    for (const auto& playlist : playlists) {
        std::cout << " - " << playlist << "\n";
    }
}

void PlaylistManager::viewPlaylist(const std::string& name) {
    if (playlistContents.find(name) != playlistContents.end()) {
        std::cout << "Playlist: " << name << "\n";
        for (const auto& song : playlistContents[name]) {
            std::cout << " - " << song << "\n";
        }
    } else {
        std::cout << "Playlist " << name << " not found.\n";
    }
}

void PlaylistManager::createPlaylist(const std::string& name) {
    playlists.push_back(name);
    playlistContents[name] = {};
    std::cout << "Playlist " << name << " created.\n";
}

void PlaylistManager::updatePlaylist(const std::string& name) {
    if (playlistContents.find(name) != playlistContents.end()) {
        std::string song;
        std::cout << "Enter the name of the song you want to add: ";
        std::cin >> song;
        playlistContents[name].push_back(song);
        std::cout << "The song " << song << " added to playlist " << name << ".\n";
    } else {
        std::cout << "Playlist " << name << " not found.\n";
    }
}

void PlaylistManager::deletePlaylist(const std::string& name) {
    playlists.erase(std::remove(playlists.begin(), playlists.end(), name), playlists.end());
    playlistContents.erase(name);
    std::cout << "Playlist " << name << " has been deleted.\n";
}
