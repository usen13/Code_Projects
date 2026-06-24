#include <iostream>
#include <string>

class Playlist {
private:
    std::string name;
    std::string* songs;
    int songCount;

public:
    // Constructor
    Playlist(const std::string& name, const std::string* songs, int count) {
        this->name = name;
        this->songs = new std::string[count];
        for (int i = 0; i < count; i++) {
            this->songs[i] = songs[i];
        }
        this->songCount = count;
    };

    // Copy constructor
    Playlist(const Playlist& other) {
        name = other.name;
        songs = new std::string[other.songCount];
        for (int i = 0; i < other.songCount; i++) {
            songs[i] = other.songs[i];
        }
        songCount = other.songCount;
    };

    // Destructor
    ~Playlist() {
        delete[] songs;
        std::cout << "Destructor called for playlist: " << name << std::endl;
    };

    // Print playlist details
    void print() const {
        for (int i = 0; i < songCount; i++) {
            std::cout << "Song name is: " << songs[i] << std::endl;
        }
    };

    // Add song (optional extension)
    void setSong(int index, const std::string& newTitle) {
        if (index < 0 || index >= songCount) {
            std::cout << "Index overflow when setting song" << std::endl;
            return;
        }
        songs[index] = newTitle;
    };
};

// int main () {
//     std::string SongName[] = {"Elevation", "Beautiful Day"};
//     Playlist* exampleList = new Playlist("Example Playlist", SongName, 2);

//     Playlist exampleList2 = *exampleList;

//     exampleList->setSong(1, "Love and Peace");
//     exampleList2.print();
//     exampleList->print();
//     delete exampleList;
//     return 0;
// }