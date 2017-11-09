//
// Created by Luk3r on 2017-10-25.
//

#ifndef OK_PROJEKT_DROGA_H
#define OK_PROJEKT_DROGA_H
#include <iostream>
#include <fstream>
#include "map.h"
class route {
private:
    int route[1000];
    double fitness;
public:
    void setRoute(int a,int i);
    int getRoute(int i);
    double getFitness();
    void setFitness(double a);
    double calcFitness(map &town);
};
#endif //OK_PROJEKT_DROGA_H
