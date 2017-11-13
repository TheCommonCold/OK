#include "route.h"

void route::setTown(int a, int i){
    this->route[i]=a;
}

int route::getTown(int i) {
    return this->route[i];
}

void route::setRoute(std::vector<int> vec, map &town){
        this->route=vec;
        this->calcLength(town);
}

std::vector<int> route::getRoute(){
    return this->route;
}

double route::calcLength(map &town){
    double distance=0;
    for(int i=0;i<town.getSize()-1;i++)
    {
        distance=distance+town.getDistance(getTown(i), getTown(i + 1));
    }
    this->length=distance+town.getDistance(getTown(0), getTown(town.getSize() - 1));
    return length;
}

void route::setLength(double a){
    this->length=a;
}

double route::getLength(){
    return this->length;
}

void route::setFitness(double a) {
    this->fitness=a;
}
double route::getFitness() {
    return this->fitness;
}