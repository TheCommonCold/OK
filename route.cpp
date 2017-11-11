#include "route.h"

void route::setTown(int a, int i){
    this->route[i]=a;
}

int route::getTown(int i) {
    return this->route[i];
}

double route::calcFitness(map &town){
    double distance=0;
    for(int i=0;i<town.getSize()-1;i++)
    {
        distance=distance+town.getDistance(getTown(i), getTown(i + 1));
    }
    this->fitness=distance+town.getDistance(getTown(0), getTown(town.getSize() - 1));
    return fitness;
}

void route::setFitness(double a){
    this->fitness=a;
}

double route::getFitness(){
    return fitness;
}