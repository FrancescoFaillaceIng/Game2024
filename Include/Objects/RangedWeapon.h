//
// Created by erosp on 07/07/2021.
//

#ifndef MAIN_CPP_RANGEDWEAPON_H
#define MAIN_CPP_RANGEDWEAPON_H

#include "Weapon.h"
#include "../Projectile.h"

class RangedWeapon: public Weapon {
public:
    enum RangedWeaponType {
        aoeWeapon,
        stWeapon
    };

    RangedWeapon(const TextureHolder& textures, RangedWeapon::RangedWeaponType rangedWeaponType);
    void update() override;
    void changeType(RangedWeaponType rangedWeaponType);

    RangedWeaponType weaponType;
    Projectile::ProjectileType projectileType;
private:
    const TextureHolder& textures;
};
#endif //MAIN_CPP_RANGEDWEAPON_H
