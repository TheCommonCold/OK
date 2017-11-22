#ifndef OK_PROJEKT_MUTATE_H
#define OK_PROJEKT_MUTATE_H

#include "map.h"
#include <random>
#include "route.h"
#include <time.h>
#include "init.h"
void breedCross(route a, route b, route *out, map *town,int overDrive,double chance);
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis);
void mutate(route* a,double mutationChance);
void fix(route* a,map town);

#endif //OK_PROJEKT_MUTATE_H
