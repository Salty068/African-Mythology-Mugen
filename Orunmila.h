#pragma once
#ifndef ORUNMILA_H
#define ORUNMILA_H

#include "Character.h"

using namespace std;

class Orunmila : public Character {
protected:
    int turnCount;

public:
    // Constructor
    Orunmila(const string& characterName);

    
    void FireBall(Character& opponent);
    void skyFall(Character& opponent) ;
    void Divination();
    void EarthBurial(Character& opponent) ;
    void UpdateStats() override;

private:
    bool CanActivateSpecialAttack() const;
};

#endif

