//
// Created by Luk3r on 2017-10-25.
//

#ifndef OK_PROJEKT_DROGA_H
#define OK_PROJEKT_DROGA_H
#include <iostream>
#include <fstream>
#include <vector>
#include "map.h"

class route {

private:
    std::vector<int> route;
    double length, fitness;

public:
    void setTown(int a, int i);
    int getTown(int i);

    void setRoute(std::vector<int> vec);
    std::vector<int> getRoute();

    double getLength();
    void setLength(double a);
    double calcLength(map &town);

    void setFitness(double a);
    double getFitness();
};
#endif //OK_PROJEKT_DROGA_H
