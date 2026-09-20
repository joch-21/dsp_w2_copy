#pragma once
#include "Entity.h"

class Enemy : public Entity {
private:
    int fAggroRange;
    string fBehaviorType;

public:
    Enemy();
    Enemy(string aID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack, int aAggroRange, string aBehavior);

    int GetAggroRange() const;
    void SetAggroRange(int aRange);

    string GetBehaviorType() const;
    void SetBehaviorType(const std::string& aBehavior);

    void Patrol() const;
};