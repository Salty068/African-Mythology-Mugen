#pragma once

#ifndef OGUN_H
#define OGUN_H

#include "character.h"

using namespace std;
class Ogun : public Character
{
protected:
	int turnCount = 0;
public:
	Ogun(const string& name);
	void ShieldBash(Character& opponent);
	void Taunt(Character& opponent);
	void DefenceOverload();
	void IronSlash(Character& opponent);
private:
	bool extraTurn;
	void PerformExtraTurn();
	bool CanActivateSpecialAttack() const;
};

#endif
