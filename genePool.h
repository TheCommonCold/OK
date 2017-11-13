#ifndef OK_PROJEKT_GENEPOOL_H
#define OK_PROJEKT_GENEPOOL_H

#include "route.h"
#include "map.h"
#include<vector>
class genePool{
private:
    //2 rzeby an zmiane byly aktualna i nowa
    std::vector<route> pool;
    double currentMaxFitness,currentWorstLength,currentBestLength;
    route bestRoute;
    unsigned long long currentFitnessSum;


public:

    //currentBestLength
    void setCurrentBestLength(double a);
    double getCurrentBestLength();

    //currentMaxFitness
    void setMaxFitness(double a, bool force);
    double getMaxFitness();
    //double calcMaxFitness(route generation[generationSize], map &town);

    //currentWorstLength
    void setWorstLength(double a, bool force);
    double getWorstLength();

    //bestLength
    double getBestLength();

    //bestRoute
    void setBestRoute(route a, map &town, bool force);
    route getBestRoute();

    //currentFitnessSum
    void setCurrentFitnessSum(unsigned long long a);
    unsigned long long getCurrentFitnessSum();

    //Pool
    void addSpeciman(route a, map &town);
    route getSpeciman(int number);
    std::vector<route> getPool();
    void createPool(route generation[100], map &town);
    void printSpeciman(int number);
    void printAllSpecimen();




};


#endif //OK_PROJEKT_GENEPOOL_H
