#include "Sango.h"
#include <iostream>

Sango::Sango(const std::string& characterName)
    : Character(characterName) {
    // Additional initialization for Sango
}

void Sango::LightningPunch(Character& opponent) {
    // Logic for Lightning Punch attack
    opponent.takeDamage(20);
    charge += 10;
    mana += 10;
    UpdateStats();
    ++turnCount;
    cout << turnCount;
}

void Sango::LightningKick(Character& opponent) {
    // Logic for Lightning Kick attack
    opponent.takeDamage(25);
    charge += 10;
    mana -= 20;
    UpdateStats();
    ++turnCount;
    cout << turnCount;
}

void Sango::Berserk(Character& opponent) {
    // Logic for activating Berserk ability
    if (health <= 30 && mana < 30) {
        opponent.takeDamage(50);
        health -= 15;
        UpdateStats();
        ++turnCount;
        cout << turnCount;
    }
    else {
        cout << "Cannot activate Berserk" << endl;
        cout << "need health and mana to be less than 30" << endl;
    }
}

void Sango::LightningArmament(Character& opponent) {
    // Logic for activating Lightning Armament special attack
    if (health <= 10 && mana < 10 && charge >= 100) {
        opponent.takeDamage(80);
        health += 50;
        UpdateStats();
        ++turnCount;
        cout << turnCount;
    }

    else {
        cout << "cannot activate Lightning Arnament" << endl;
    }

}

bool Sango::CanActivateSpecialAttack() const
{
    return false;
}
