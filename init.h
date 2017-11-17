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
#define mutationChance 0.001

#ifndef OK_PROJEKT_INIT_H
#define OK_PROJEKT_INIT_H

double zachlannyArtura(map &towns, genePool &generations);
int randomArtura(int min,int max,std::mt19937 mt);
unsigned long long getRandomNumber( unsigned long long max);
void populateGeneration( map &town, genePool &generation);
bool checkVector(std::vector<int> vec,double length,map &town, genePool generation);
#endif //OK_PROJEKT_INIT_H
