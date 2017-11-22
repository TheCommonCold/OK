#include <iostream>
#include <fstream>
#include <vector>
#include "map.h"
#include "route.h"
#include "mutate.h"
#include "misc.h"
#include "genePool.h"

int main() {
    map town;
    town.load();
    genePool generations;
    std::cout<<zachlannyArtura(*&town, generations)<<std::endl;
    populateGeneration(*&town,*&generations);
    generations.calcFitnessAll(*&town);
    //generations.improve(town);
    int i=1;
    for (route &it: generations.getPool()){
        checkVector(it.getRoute(),it.getLength(),town,generations);
        //std::cout<<i<<" "<<it.getLength()<<" "<<it.getFitness()<<std::endl;
        i++;
    }
    int j=0;
    int failCounter=0;
    int previousLengthSum;
    double chance=genomMutationChance;
    while(j<numberOfGenerations){
        previousLengthSum=generations.getCurrentLengthSum();
        if(failCounter>=overdDriveThreshhold){
            failCounter=0;
            chance=chance+0.1;
            //generations.improve(town);
        }
        generations.createNewGeneration(*&town,chance,true);
        generations.calcFitnessAll(*&town);
        if(generations.getCurrentLengthSum()==previousLengthSum)failCounter++;
        //for (route &it: generations.getPool()){
        //    checkVector(it.getRoute(),it.getLength(),town,generations);
        //}
        if(j%100==0){
            std::cout<<generations.getBestLength()<<" "<<generations.getCurrentBestLength()<<" "<<generations.getCurrentLengthSum()<<std::endl;
            for(auto it:generations.getBestRoute().getRoute()){
                std::cout<<it<<" ";
            }
            std::cout<<std::endl;
        }
        j++;
    }
//    std::cout<<generations.getMaxFitness()<<" "<<generations.getCurrentBestLength()<<" "<<generations.getCurrentFitnessSum()<<" "<<generations.getWorstLength()<<std::endl;
//    int arej[generations.getPool().size()];
//    for (int i=0;i<generations.getPool().size();i++) arej[i]=0;
//    for (int i=0;i<generations.getCurrentFitnessSum();i++)
//    {
//        int x=generations.findParent();
//        arej[x]++;
//    }
//    for (int i=0;i<generations.getPool().size();i++){
//        std::cout<<i+1<<" "<<arej[i]<<" "<<generations.getPool()[i].getFitness()<<std::endl;
//    }
    //generations.printAllSpecimen();
    //std::cout<< generations.getWorstLength();
//    populateGeneration(*&town,*&generation);
//    genePool pool;
//    pool.calcMaxFitness(*&generation,*&town);
//    pool.createPool(*&generation,*&town);
    //std::cout<<generation[20].getTown(0)<<"  "<<generation[20].getFitness();
    return 0;
}