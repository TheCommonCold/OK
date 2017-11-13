#include <iostream>
#include <fstream>
#include <vector>
#include "map.h"
#include "route.h"
#include "mutate.h"
#include "init.h"
#include "genePool.h"

int main() {
    map town;
    town.load();
    genePool generations;
    std::cout<<zachlannyArtura(*&town, generations)<<std::endl;
    //generations.printAllSpecimen();
    //std::cout<< generations.getWorstLength();
//    populateGeneration(*&town,*&generation);
//    genePool pool;
//    pool.calcMaxFitness(*&generation,*&town);
//    pool.createPool(*&generation,*&town);
    //std::cout<<generation[20].getTown(0)<<"  "<<generation[20].getFitness();
    return 0;
}