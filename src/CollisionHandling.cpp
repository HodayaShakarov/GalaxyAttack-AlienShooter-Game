#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "SpaceShip.h"
#include "BulletProofGift.h"
#include "LifeGift.h"
#include "ScoreGift.h"

namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    void spaceShipBulletProofGift(GameObject& spaceShip, GameObject& bulletProofGift) //התנגשות בין שחקן למתנה של חסין כדורים
    {
        SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
        BulletProofGift& bulletProof = static_cast<BulletProofGift&> (bulletProofGift);
        ship.setProtected(true);
    }

    void spaceShipLifeGift(GameObject& spaceShip, GameObject& lifeGift) //התנגשות בין שחקן למתנה של העלאת חיים
    {
        SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
        LifeGift& life = static_cast<LifeGift&> (lifeGift);
        ship.setLife(1);
    }

    void spaceShipScoreGift(GameObject& spaceShip, GameObject& scoreGift) //התנגשות בין שחקן למתנה של העלאת ניקוד
    {
        SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
        ScoreGift& score = static_cast<ScoreGift&> (scoreGift);
        ship.addScore();
    }

    using HitFunctionPtr = void (*)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(SpaceShip), typeid(BulletProofGift))] = &spaceShipBulletProofGift;
        phm[Key(typeid(SpaceShip), typeid(LifeGift))] = &spaceShipLifeGift;
        phm[Key(typeid(SpaceShip), typeid(ScoreGift))] = &spaceShipScoreGift;

        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
