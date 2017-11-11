#ifndef OK_PROJEKT_GENEPOOL_H
#define OK_PROJEKT_GENEPOOL_H

#include "route.h"
#include "map.h"
#include "init.h"
class genePool {
private:
    double maxFitness;
    short int pool[10000];
public:
    void setMaxFitness(double a);
    double getMaxFitness();
    double calcMaxFitness(route generation[generationSize], map &town);
    void setPool(short int a,short int i);
    short int getPool(short i);
    void createPool(route generation[generationSize], map &town);
};


#endif //OK_PROJEKT_GENEPOOL_H
