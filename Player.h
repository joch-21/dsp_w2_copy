#pragma once
#include "Entity.h"

class Player : public Entity {
private:
    int fLives;
    int fXP;

public:
    Player();
    Player(std::string aID, Position aPos, int aMaxHP, int aCurrentHP, int aAttack, int aLives, int aXP);

    int GetLives() const;
    void SetLives(int aLives);

    int GetXP() const;
    void GainXP(int aXP);
};