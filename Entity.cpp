#include "Entity.h"
#include <iostream>
#include <sstream>


Entity::Entity() : fID("001"), fPosition{ 0 , 0 }, fMaxHP(100), fCurrentHP(100), fAttack(0) {}

Entity::Entity(string aID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack) : fID(aID), fPosition(aPos), fMaxHP(aMaxHP), fCurrentHP(aCurrentHP), fAttack(aAttack) {}

Entity::~Entity() {}

string Entity::GetID() const {
	return fID; 
}
void Entity::SetID(const string& aID) {
	fID = aID;
} 

Position Entity::GetPosition() const { 
	return fPosition; 
}
void Entity::SetPosition(Position aPos) { 
	fPosition = aPos; 
}

int Entity::GetMaxHP() const { 
	return fMaxHP; 
}
void Entity::SetMaxHP(int aMaxHP) { 
	fMaxHP = aMaxHP; 
}

int Entity::GetCurrentHP() const { 
	return fCurrentHP; 
}
void Entity::SetCurrentHP(int aCurrentHP) { 
	fCurrentHP = aCurrentHP; 
}

int Entity::GetAttack() const { 
	return fAttack; 
}
void Entity::SetAttack(int aAttack) { 
	fAttack = aAttack; 
}

// a) PrintStatus implementation
string Entity::PrintStatus() const {
    ostringstream oss;
        oss << "ID:" << GetID()
        << " Position: X=" << GetPosition().x << " Y=" << GetPosition().y
        << " HP:" << GetCurrentHP() << "/" << GetMaxHP()
        << " Attack:" << GetAttack();
    return oss.str();
}

// b) Friend Insertion Operator (<<) using accessors
ostream& operator<<(ostream& os, const Entity& aEntity) {
        os << "ID:" << aEntity.GetID()
        << " Position: X=" << aEntity.GetPosition().x << " Y=" << aEntity.GetPosition().y
        << " HP:" << aEntity.GetCurrentHP() << "/" << aEntity.GetMaxHP()
        << " Attack:" << aEntity.GetAttack();
    return os;
}

// c) Friend Extraction Operator (>>) using accessors
istream& operator>>(istream& is, Entity& aEntity) {
    string id;
    int x, y, maxHP, curHP, attack;

    // Read input values sequentially
    if (is >> id >> x >> y >> maxHP >> curHP >> attack) {
        aEntity.SetID(id);
        aEntity.SetPosition({ x, y });
        aEntity.SetMaxHP(maxHP);
        aEntity.SetCurrentHP(curHP);
        aEntity.SetAttack(attack);
    }
    return is;
}

string Entity::GetMemory() const {
    return fMemory;
}

//  Tick parses fMemory and executes the corresponding action 
int Entity::Tick() {
    if (fMemory.empty()) {
        return 0;
    }

    stringstream ss(fMemory);
    string command;
    ss >> command;

    int returnValue = 0;

    if (command == "Damaged") {
        int damageValue = 0;
        if (ss >> damageValue) {
            fCurrentHP -= damageValue;
            if (fCurrentHP < 0) fCurrentHP = 0;
        }
    }
    else if (command == "Heal") {
        int healValue = 0;
        if (ss >> healValue) {
            fCurrentHP += healValue;
            if (fCurrentHP > fMaxHP) fCurrentHP = fMaxHP;
        }
    }
    else if (command == "Move") {
        int dx = 0, dy = 0;
        if (ss >> dx >> dy) {
            fPosition.x += dx;
            fPosition.y += dy;
        }
    }
    else if (command == "Attack") {
        returnValue = fAttack;
    }
    else {
        cout << "[Warning] Unknown command: " << command << "\n";
    }

    // Clear memory after processing so it doesn't trigger again next tick
    fMemory.clear();

    return returnValue;
}