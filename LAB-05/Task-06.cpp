#include <iostream>
using namespace std;

class Level {
public:
    string stageName;
    int challenge;

    Level(string name, int diff) : stageName(name), challenge(diff) {}

    void showDetails() {
        cout << "Stage Name: " << stageName << ", Challenge Level: " << challenge << endl;
    }
};

class VideoGame {
private:
    string gameTitle;
    string category;
    Level* stages[100]; 
    int stageCount;

public:
    VideoGame(string t, string c) : gameTitle(t), category(c), stageCount(0) {}

    ~VideoGame() {
        for (int i = 0; i < stageCount; ++i) {
            delete stages[i];
        }
    }

    void addStage(string name, int diff) {
        if (stageCount < 100) {
            stages[stageCount++] = new Level(name, diff);
        }
    }

    void showGameInfo() {
        cout << "Game Title: " << gameTitle << ", Category: " << category << endl;
        cout << "Stages:" << endl;
        for (int i = 0; i < stageCount; ++i) {
            stages[i]->showDetails();
        }
    }
};

int main() {
    VideoGame adventureGame("Mystic Quest", "RPG");
    adventureGame.addStage("Enchanted Forest", 1);
    adventureGame.addStage("Shadow Cave", 2);
    adventureGame.addStage("Royal Fortress", 3);

    adventureGame.showGameInfo();

    return 0;
}
