#include <iostream>
#include <string>

using namespace std;

const int MAX_SONGS = 100;

class MusicPlayer {
private:
    string playlist[MAX_SONGS];
    int songCount;
    string currentlyPlayingSong;

public:
    MusicPlayer() : songCount(0), currentlyPlayingSong("") {}

    void addSong(string songName) {
        if (songCount >= MAX_SONGS) {
            cout << "Playlist is full!" << endl;
            return;
        }
        playlist[songCount++] = songName;
    }

    void removeSong(string songName) {
        for (int i = 0; i < songCount; ++i) {
            if (playlist[i] == songName) {
                for (int j = i; j < songCount - 1; ++j) {
                    playlist[j] = playlist[j + 1];
                }
                songCount--;
                cout << "Song removed: " << songName << endl;
                return;
            }
        }
        cout << "Song not found!" << endl;
    }

    void playSong(string songName) {
        for (int i = 0; i < songCount; ++i) {
            if (playlist[i] == songName) {
                currentlyPlayingSong = songName;
                cout << "Now playing: " << songName << endl;
                return;
            }
        }
        cout << "Song not found!" << endl;
    }

    void displayPlaylist() {
        cout << "Playlist:" << endl;
        for (int i = 0; i < songCount; ++i) {
            cout << playlist[i] << endl;
        }
    }
};

int main() {
    MusicPlayer imranPlayer;
    imranPlayer.addSong("Song 1");
    imranPlayer.addSong("Song 2");
    imranPlayer.playSong("Song 1");
    imranPlayer.displayPlaylist();
    imranPlayer.removeSong("Song 1");
    imranPlayer.displayPlaylist();
    return 0;
}
