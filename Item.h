#pragma once
#include "Entity.h"

class Item : public Entity {
private:
    int fDurability;
    string fEffect;

public:
    Item();
    Item(string aID, Position aPos, int aDurability, string aEffect);

    int GetDurability() const;
    void SetDurability(int aDurability);

    string GetEffect() const;
    void SetEffect(const string& aEffect);

    void Use();
};