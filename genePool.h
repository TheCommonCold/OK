#ifndef OK_PROJEKT_GENEPOOL_H
#define OK_PROJEKT_GENEPOOL_H

#include "route.h"
#include "map.h"
#include "init.h"
#include<vector>
class genePool{
private:
    //2 rzeby an zmiane byly aktualna i nowa
    std::vector<route> pool[2];
    double currentMaxFitness,currentBestLength;
    route bestRoute;
    unsigned long long currentFitnessSum;
    int currentGeneration;

public:

    //currentBestLength
    void setCurrentBestLength(double a);
    double getCurrentBestLength();

    //currentMaxFitness
    void setMaxFitness(double a);
    double getMaxFitness();
    //double calcMaxFitness(route generation[generationSize], map &town);

    //bestLength
    double getBestLength();

    //bestRoute
    void setBestRoute(route a);
    route getBestRoute();

    //currentFitnessSum
    void setCurrentFitnessSum(unsigned long long a);
    unsigned long long getCurrentFitnessSum();

    //Pool
    void setPool(route a,int number, int whichPopulaton);
    route getPool(int number, int whichPopulaton);
    void createPool(route generation[generationSize], map &town);

    //currentGenration
    void setCurrentGeneration(short a);
    int getCurrentGeneration();
    int switchGenerations();


};


#endif //OK_PROJEKT_GENEPOOL_H
