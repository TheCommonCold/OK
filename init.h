//
// Created by Luker on 09.11.2017.
//
#include <time.h>
#include "map.h"
#include "route.h"
#include "mutate.h"
#define generationSize 50

#ifndef OK_PROJEKT_INIT_H
#define OK_PROJEKT_INIT_H

double zachlanny_artura_pojedynczy(int start,map &town, route &path);
double zachlanny_artura( map &town, route &path);
void populateGeneration( map &town, route generation[generationSize]);

#endif //OK_PROJEKT_INIT_H
