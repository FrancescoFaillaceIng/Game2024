//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_CHARACTERS_H
#define GAME_CHARACTERS_H

#include <SFML\System.hpp>
#include "..\Entity.h"
#include "..\ResourceHolder.h"
#include "..\ResourceIdentifier.h"

class Characters: public Entity{
public:
    enum CharacterType{
        goodboy,
        badguy,
    };

    Characters();
    virtual void Update();
    virtual void changeDirection();
    virtual void die();

    const sf::Vector2f &getPosition() const;

    void setHp(int hp);
    void setHpMax(int hpMax);
    void setAttackDamage(int attackDamage);
    void setSpeedBasic(int speedBasic);

    int getHp() const;
    int getHpMax() const;
    int getAttackDamage() const;
    int getSpeedBasic() const;

    void setIsMovingUp(bool isMovingUp);
    void setIsMovingDown(bool isMovingDown);
    void setIsMovingLeft(bool isMovingLeft);
    void setIsMovingRight(bool isMovingRight);

    bool active;

protected:
    CharacterType characterType;

    sf::Vector2f position;

    int hp;
    int hpMax;
    int attackDamage;
    int speedBasic;
    int counterWalking = 0;

    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;

};


#endif //GAME_CHARACTERS_H
