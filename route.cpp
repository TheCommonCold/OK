#include "route.h"

void route::setRoute(int a,int i){
    this->route[i]=a;
}

int route::getRoute(int i) {
    return this->route[i];
}

double route::calcFitness(map &town){
    double distance=0;
    for(int i=0;i<town.getSize()-1;i++)
    {
        distance=distance+town.getDistance(getRoute(i),getRoute(i+1));
    }
    this->fitness=distance+town.getDistance(getRoute(0),getRoute(town.getSize()-1));
    return fitness;
}

void route::setFitness(double a){
    this->fitness=a;
}

double route::getFitness(){
    return fitness;
}