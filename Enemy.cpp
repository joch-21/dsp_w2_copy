#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
    : Entity("Enemy_Minion", { 5, 5 }, 50, 50, 8), fAggroRange(4), fBehaviorType("Patrol") {
}

Enemy::Enemy(string aID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack, int aAggroRange, string aBehavior) : Entity(aID, aPos, aMaxHP, aCurrentHP, aAttack), fAggroRange(aAggroRange), fBehaviorType(aBehavior) {} 


int Enemy::GetAggroRange() const { 
    return fAggroRange; 
}

void Enemy::SetAggroRange(int aRange) { 
    fAggroRange = aRange; 

}

string Enemy::GetBehaviorType() const { 
    return fBehaviorType; 

}

void Enemy::SetBehaviorType(const std::string& aBehavior) { 
    fBehaviorType = aBehavior; 
}

void Enemy::Patrol() const {
    cout << fID << " is patrolling with an aggro radius of " << fAggroRange << " tiles." << endl;
}

