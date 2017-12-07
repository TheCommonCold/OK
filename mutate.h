#ifndef OK_PROJEKT_MUTATE_H
#define OK_PROJEKT_MUTATE_H

#include "map.h"
#include <random>
#include "route.h"
#include <time.h>
#include "misc.h"
void breedCross(route a, route b, route *out, map *town,double chance);
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis);
void mutate(route* a,double mutationChance,map &town);
void fix(route* a,map* town, bool* change);
void generateRandomMember(route &child,map &town);
void breedER(route a, route b,route* out, map* town,double chance);
void TwoOpt(route a, route b,route* out, map* town,double chance);
void TwoOptSwap( const int& i, const int& k, route a, route &b);
void PMXboi(route a, route b,route* out, map* town,double chance);

#endif //OK_PROJEKT_MUTATE_H
