#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public:
    Character(string id, string n, int lvl, int hp, string weapon) 
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    
    virtual void attack() {
        cout << name << " performs a basic attack using " << weaponType << endl;
    }
    
    virtual void defend() {
        cout << name << " takes a defensive position" << endl;
    }
    
    virtual void displayStats() {
        cout << "ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage) 
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    
    void attack() override {
        cout << name << " delivers aswing with " << weaponType << " dealing " << meleeDamage << " damage!" << endl;
    }
    
    void displayStats() override {
        Character::displayStats();
        cout << "Armor: " << armorStrength << endl;
        cout << "Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int lvl, int hp, string weapon, int mana, int power) 
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}
    
    void defend() override {
        cout << name << " conjures a shimmering arcane shield (" << manaPoints << " mana remaining)" << endl;
    }
    
    void displayStats() override {
        Character::displayStats();
        cout << "Mana: " << manaPoints << endl;
        cout << "Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) 
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    
    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires a precise shot (" << rangedAccuracy 
            << "% hit chance) - " << --arrowCount << " arrows remaining" << endl;
        } else {
            cout << name << " reaches for arrows but finds the quiver empty!" << endl;
        }
    }
    
    void displayStats() override {
        Character::displayStats();
        cout << "Arrows: " << arrowCount << endl;
        cout << "Accuracy: " << rangedAccuracy << "%" << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int lvl, int hp, string weapon, int stealth, int agi) 
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}
    
    void attack() override {
        cout << name << " strikes from the shadows with " << weaponType << endl;
    }
    
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth: Level " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior conan("W001", "Burair", 12, 180, "Greatsword", 75, 45);
    Mage gandalf("M001", "Maaz", 15, 120, "Elder Staff", 200, 80);
    Archer legolas("A001", "Zahran", 14, 130, "Elven Bow", 30, 95);
    Rogue garrett("R001", "raahim", 18, 110, "Shadow Blades", 85, 90);

    conan.attack();
    conan.displayStats();
    cout << endl;

    gandalf.defend();
    gandalf.displayStats();
    cout << endl;

    legolas.attack();
    legolas.attack();
    legolas.displayStats();
    cout << endl;

    garrett.attack();
    garrett.displayStats();

    return 0;
}s