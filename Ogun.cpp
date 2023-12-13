#include "Ogun.h"
#include <iostream> // Include necessary headers

Ogun::Ogun(const string& name): Character(name) {
  
}

void Ogun::ShieldBash(Character& opponent) {
    // Implement Shield Bash logic
    opponent.takeDamage(15);
    charge += 10;
    mana += 5;
    UpdateStats();
    ++turnCount;
    cout << turnCount;
}

void Ogun::Taunt(Character& opponent) {
    // This could be a special move that allows Ogun to go an extra turn
    opponent.takeDamage(5);  
    extraTurn = true;
    PerformExtraTurn();
    charge += 10;
    mana += 5;
    UpdateStats();
    ++turnCount;
    cout << turnCount;
}

void Ogun::DefenceOverload() {
    // Implement Defence Overload logic
    if (turnCount > 10) {
        extraTurn = true;
        PerformExtraTurn();
        health += 10;
        mana += 5;
        ++turnCount;
        UpdateStats();
        cout << turnCount;
    }
    else {
        cout << "Defence Overload cannot be activated yet" << endl;
    }
}

void Ogun::IronSlash(Character& opponent) {
    // Implement Iron Slash logic
    if (CanActivateSpecialAttack()) {
        opponent.takeDamage(35);
        // Reset charge to 0 after using the special attack
        mana -= 75;
        UpdateStats();
        ++turnCount;
        cout << turnCount;
    }
    else {
        cout << "Not enough mana to activate Iron Slash." << endl;
    }
}



bool Ogun::CanActivateSpecialAttack() const {
    return (mana >= 100);
}

void Ogun::PerformExtraTurn()
{
    if (extraTurn) {
        cout << name << " has an extra turn!" << endl;

        mana -= 5;  
        health += 20;  

        extraTurn = false;
    }
}

