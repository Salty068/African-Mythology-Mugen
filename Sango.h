#pragma once

#ifndef SANGO_H
#define SANGO_H

#include "Character.h"

class Sango : public Character {
protected:
    int turnCount = 0;
public:
    Sango(const string& characterName);

    // Additional functions unique to Sango
    void LightningPunch(Character& opponent);
    void LightningKick(Character& opponent);
    void Berserk(Character& opponent);
    void LightningArmament(Character& opponent);
private:
    bool CanActivateSpecialAttack() const;
};

#endif


