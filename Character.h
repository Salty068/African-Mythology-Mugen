#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
	string name;
	int level;
	int health;
	int mana;
	int charge;
	virtual void UpdateStats();

public:
	Character(const string& name);
	Character(const string& name, int health, int mana, int charge);
	void rest();
	void useManaToHeal();
	void takeDamage(int);
	void displayStats() const;
	void SaveToFile(const string& fileName) const;
	static Character* LoadFromFile(const string& filename);
	int getHealth() const;
	string getName() const;


};



#endif
