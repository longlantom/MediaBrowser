// PlaylistManager.h
#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <vector>
#include <string>
#include <map>

class PlaylistManager {
public:
    void managePlaylists();
private:
    std::vector<std::string> playlists;
    std::map<std::string, std::vector<std::string>> playlistContents;
    void listPlaylists ();
    void viewPlaylist  (const std::string& name);
    void createPlaylist(const std::string& name);
    void updatePlaylist(const std::string& name);
    void deletePlaylist(const std::string& name);
};

#endif // PLAYLISTMANAGER_H
