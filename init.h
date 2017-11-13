//
// Created by Luker on 09.11.2017.
//
#include <ctime>
#include<random>
#include <vector>
#include "map.h"
#include "route.h"
#include "mutate.h"
#include "genePool.h"

#define generationSize 50

#ifndef OK_PROJEKT_INIT_H
#define OK_PROJEKT_INIT_H

double zachlannyArtura(map &towns, genePool &generations);
int randomArtura(int min,int max,std::mt19937 mt);

#endif //OK_PROJEKT_INIT_H
