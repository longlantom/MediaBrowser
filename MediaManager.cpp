// MediaManager.cpp
#include "MediaManager.h"
#include <iostream>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>

namespace fs = std::__fs::filesystem;

void MediaManager::listMediaFiles() {
    std::string path;
    std::cout << "Enter directory path: ";
    std::cin >> path;

    // Check if the path exists and is a directory
    if (!fs::exists(path) || !fs::is_directory(path)) {
        std::cerr << "Error: Directory does not exist." << std::endl;
        return;
    }

    auto files = getMediaFiles(path);

    int page = 1, perPage = 25;
    int total = files.size();
    int totalPages = (total + perPage - 1) / perPage;

    while (page <= totalPages) {
        for (int i = (page - 1) * perPage; i < page * perPage && i < total; ++i) {
            std::cout << files[i] << "\n";
        }
        std::cout << "Page " << page << " of " << totalPages << "\n";
        std::cout << "Enter next page number or 0 to exit: ";
        std::cin >> page;
        if (page == 0) break;
    }
}

void MediaManager::showMetadata() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::cin >> filePath;

    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();
        std::cout << "Title:  " << tag->title() << "\n";
        std::cout << "Artist: " << tag->artist() << "\n";
        std::cout << "Album:  " << tag->album() << "\n";
        std::cout << "Year:   " << tag->year() << "\n";
        std::cout << "Track:  " << tag->track() << "\n";
        std::cout << "Genre:  " << tag->genre() << "\n";
    }
}

void MediaManager::editMetadata() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::cin >> filePath;

    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();

        std::string newTitle;
        std::cout << "Enter new Title (leave empty to keep current): ";
        std::getline(std::cin >> std::ws, newTitle);
        if (!newTitle.empty()) tag->setTitle(newTitle);

        std::string newArtist;
        std::cout << "Enter new Artist (leave empty to keep current): ";
        std::getline(std::cin, newArtist);
        if (!newArtist.empty()) tag->setArtist(newArtist);

        std::string newAlbum;
        std::cout << "Enter new Album (leave empty to keep current): ";
        std::getline(std::cin, newAlbum);
        if (!newAlbum.empty()) tag->setAlbum(newAlbum);

        unsigned int newYear;
        std::cout << "Enter new Year (0 to keep current): ";
        std::cin >> newYear;
        if (newYear != 0) tag->setYear(newYear);

        unsigned int newTrack;
        std::cout << "Enter new Track (0 to keep current): ";
        std::cin >> newTrack;
        if (newTrack != 0) tag->setTrack(newTrack);

        std::string newGenre;
        std::cout << "Enter new Genre (leave empty to keep current): ";
        std::getline(std::cin >> std::ws, newGenre);
        if (!newGenre.empty()) tag->setGenre(newGenre);

        // Save changes
        if (!file.save()) {
            std::cerr << "Failed to save changes!\n";
        } else {
            std::cout << "Metadata updated successfully.\n";
        }
    } else {
        std::cerr << "Failed to open file or retrieve tag!\n";
    }
}


std::vector<std::string> MediaManager::getMediaFiles(const std::string& directory) {
    std::vector<std::string> files;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                std::string extension = entry.path().extension().string();
                if (extension == ".mp3" || extension == ".mp4" || extension == ".wav") { // Check ext
                    files.push_back(entry.path().string());
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
    return files;
}