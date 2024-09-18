// MediaManager.h
#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <vector>
#include <string>

class MediaManager {
public:
    void listMediaFiles();
    void showMetadata();
    void editMetadata();
private:
    std::vector<std::string> getMediaFiles(const std::string& directory);
};

#endif // MEDIAMANAGER_H
