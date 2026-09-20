#pragma once
#include <string>
#include "Position.h"
using namespace std;

class Entity {
private: 
	string fMemory;

protected:
	string fID;
	Position fPosition;
	int fMaxHP, fCurrentHP, fAttack;

public:
	Entity();
	Entity(string fID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack);

	virtual ~Entity();

	string GetID() const;
	void SetID(const string& aID);

	Position GetPosition() const;
	void SetPosition(Position aPos);

	int GetMaxHP() const;
	void SetMaxHP(int aMaxHP);

	int GetCurrentHP() const;
	void SetCurrentHP(int aCurrentHP);

	int GetAttack() const;
	void SetAttack(int aAttack);

	string PrintStatus() const;

	friend ostream& operator<<(ostream& os, const Entity& aEntity);

	friend istream& operator>>(istream& is, Entity& aEntity);

	string GetMemory() const;

	virtual int Tick();
};