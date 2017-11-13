#include <iostream>
#include <fstream>
#include <vector>
#include "map.h"
#include "route.h"
#include "mutate.h"
#include "init.h"
#include "genePool.h"

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dis(0, 100000000); //aby wywołać losową liczbę dis(mt) np. cout<<dis(mt);
    map town;
    town.load();
    genePool generations;
    std::cout<<zachlannyArtura(*&town, generations)<<std::endl;
    generations.calcFitnessAll();
    int i=0;
    for (route &it: generations.getPool()){
        std::cout<<i<<" "<<it.getLength()<<" "<<it.getFitness()<<std::endl;
    }
    //generations.printAllSpecimen();
    //std::cout<< generations.getWorstLength();
//    populateGeneration(*&town,*&generation);
//    genePool pool;
//    pool.calcMaxFitness(*&generation,*&town);
//    pool.createPool(*&generation,*&town);
    //std::cout<<generation[20].getTown(0)<<"  "<<generation[20].getFitness();
    return 0;
}