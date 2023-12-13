#include "Character.h"
#include <iostream>
#include <fstream>

using namespace std;


void Character::UpdateStats()
{
    health = health;
    mana = mana;
    charge = charge;
    displayStats();
}

Character::Character(const string& characterName)
    : name(characterName), health(100), mana(100), charge(0){
   
}

Character::Character(const std::string& name,int health, int mana, int charge) : name(name), health(health), mana(mana), charge(charge)
{

}

void Character::rest() {
    health += 10;
    cout << name << " rested. Health increased by 10.\n";
    UpdateStats();
}

void Character::useManaToHeal() {
    if (mana >= 25) {
        mana -= 10;
        health += 15;
        cout << name << " used mana to heal. Health increased by 15.\n";
        UpdateStats();
    }

    else {
        cout << name << " does not have enough mana to heal.\n";
    }

    if (health > 100) {
        health = 100;
        return;
    }
}


void Character::takeDamage(int damage) {

    if (damage > health) {
        health = 0;
        return;
    }

    health -= damage;
    cout << name << " took " << damage << " damage. Health reduced to " << health << ".\n";
}

void Character::displayStats() const
{
    cout << "Name: " << name << "\nHealth: " << health
        << "\nMana: " << mana << "\nCharge: " << charge << "\n";
}

void Character::SaveToFile(const string& fileName) const {
    ofstream file(fileName);  
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    file << name << " " << " " << health << " " << mana << " " << charge << "\n";
    file.close();
}

Character* Character::LoadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr; // Return nullptr to indicate failure
    }

    string name;
    int health, mana, charge;
    file >> name >> health >> mana >> charge;

    file.close();

    // Create a new Character instance using the loaded data
    Character* loadedCharacter = new Character(name, health, mana, charge);

    return loadedCharacter;
}

int Character::getHealth() const
{
    return health;
}

string Character::getName() const
{
    return name;
}

