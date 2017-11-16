#include "route.h"

void route::addRoute(int a){
    this->route.push_back (a);
}

int route::getRoute(int i) {    return this->route[i];}

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
        distance=distance+town.getDistance(getRoute(i), getRoute(i + 1));
    }
    this->length=distance+town.getDistance(getRoute(0), getRoute(town.getSize() - 1));
    return length;
}

void route::setLength(double a){    this->length=a;}

double route::getLength(){    return this->length;}

void route::setFitness(double a) {     this->fitness=a; }
double route::getFitness() {    return this->fitness; }