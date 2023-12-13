#include "Osun.h"
Osun::Osun(const std::string& characterName)
    : Character(characterName) {
}

void Osun::WaterBall(Character& opponent) {
    opponent.takeDamage(20);
    charge += 10;
    UpdateStats();
}

void Osun::HellRaise(Character& opponent) {
    opponent.takeDamage(12);
    charge += 10;
    mana += 10;
    UpdateStats();
}

void Osun::Divination() {
    // Logic for divination
    if (turnCount % 5 == 0) {
        health += 35;
        UpdateStats();
    }

    else {
        cout << " Cannot perform Divination" << endl;
    }
    
}

void Osun::WaterBurial(Character& opponent) {
    if (CanActivateSpecialAttack()) {
        opponent.takeDamage(40);
        mana -= 75;
        UpdateStats();
    }
}

void Osun::UpdateStats() {
    ++turnCount;
    health = health;
    mana = mana;
    charge = charge;
    displayStats();
    cout << turnCount;
    // This function is called after each turn
}

bool Osun::CanActivateSpecialAttack() const {
    return (health > 50 && mana >= 100);
}