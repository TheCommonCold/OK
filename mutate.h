#ifndef OK_PROJEKT_MUTATE_H
#define OK_PROJEKT_MUTATE_H

#include "map.h"
#include <random>
#include "route.h"
#include <time.h>
#include "init.h"
void breedCross(route a, route b, route *out, map *town);
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis);
void mutate(route* a);
void test(route a, route b, route out, map town);

#endif //OK_PROJEKT_MUTATE_H
