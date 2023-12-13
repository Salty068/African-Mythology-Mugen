#pragma once
#ifndef OSUN_H
#define OSUN_H

#include "Character.h"

class Osun : public Character {
protected:
    int turnCount = 0;

public:
    Osun(const string& characterName);

    void WaterBall(Character& opponent);
    void HellRaise(Character& opponent);
    void Divination();
    void WaterBurial(Character& opponent);
    void UpdateStats() override;

private:
    bool CanActivateSpecialAttack() const;
};

#endif

