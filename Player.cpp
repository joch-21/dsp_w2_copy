#include "Player.h"
#include <iostream>


Player::Player()
    : Entity("Player1", { 0, 0 }, 100, 100, 15), fLives(3), fXP(0) {
}

Player::Player(std::string aID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack, int aLives, int aXP)
    : Entity(aID, aPos, aMaxHP, aCurrentHP, aAttack), fLives(aLives), fXP(aXP) {
}

int Player::GetLives() const { 
    return fLives; 
}

void Player::SetLives(int aLives) { 
    fLives = aLives; 
}

int Player::GetXP() const { 
    return fXP; 
} 
void Player::GainXP(int aXP) {
    fXP += aXP;
    cout << fID << " earned " << aXP << " XP! Total XP: " << fXP << endl;
}