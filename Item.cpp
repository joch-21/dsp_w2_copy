#include "Item.h"
#include <iostream>

Item::Item()
    : Entity("Health_Potion", { 2, 2 }, 1, 1, 0), fDurability(1), fEffect("Heal_50_HP") {}

Item::Item(string aID, Position aPos, int aDurability, string aEffect) : Entity(aID, aPos, 1, 1, 0), fDurability(aDurability), fEffect(aEffect) {}

int Item::GetDurability() const { 
    return fDurability; 
}

void Item::SetDurability(int aDurability) { 
    fDurability = aDurability; 
}

string Item::GetEffect() const { 
    return fEffect; 
}

void Item::SetEffect(const string& aEffect) { 
    fEffect = aEffect; 
}

void Item::Use() {
    if (fDurability > 0) {
        fDurability--;
        cout << "Used " << fID << "! Triggered effect: " << fEffect << " (Remaining uses: " << fDurability << ")" << endl;
    }
    else {
        cout << fID << " is depleted and cannot be used." << endl;
    }
}