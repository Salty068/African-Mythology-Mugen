#include "Orunmila.h"
Orunmila::Orunmila(const std::string& characterName)
    : Character(characterName) {
    turnCount = 0;
}

void Orunmila::FireBall(Character& opponent) {
    // Implement Orunmila's main attack logic
    opponent.takeDamage(20);
    charge += 10;
    UpdateStats();
}

void Orunmila::skyFall(Character& opponent) {
    // Implement Orunmila's secondary attack logic
    opponent.takeDamage(12);
    charge += 10;
    mana += 10;
    UpdateStats();
}

void Orunmila::Divination() {
    // Implement Orunmila's auxiliary skill logic
    if (turnCount % 5 == 0) {
        health += 35;
        UpdateStats();
    }

    else {
        cout << " Cannot perform Divination" << endl;
    }
    
}

void Orunmila::EarthBurial(Character& opponent) {
    if (CanActivateSpecialAttack()) {
        opponent.takeDamage(40);
    }
    mana -= 75;
    UpdateStats();
    // Additional logic for special attack, if needed
}

bool Orunmila::CanActivateSpecialAttack() const
{
    return (health > 50 && mana >= 100);
}

void Orunmila::UpdateStats() {
    ++turnCount;
    health = health;
    mana = mana;
    charge = charge;
    displayStats();
    cout << turnCount;
}