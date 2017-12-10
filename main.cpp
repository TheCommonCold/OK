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
    route a;
    route b;
    std::vector<int> veca={'A', 'B', 'F', 'E','D','G','C'};
    std::vector<int> vecb={'G','F','A','B','C','D','E'};
    for(int i=0;i<7;i++)
    {
        veca[i]-=65;
        vecb[i]-=65;
        a.addTown(veca[i]);
        b.addTown(vecb[i]);
       // printf("%d %d %d\n",i,veca[i],vecb[i]);
    }
    route out;
    std::cout<<"ERBOI\n";

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
    while(true){
        if(j%10==0)std::cout<<"generacja: "<<j<<" postep: "<<generations.getCurrentLengthSum()<<" best: "<<generations.getBestLength()<<std::endl;
        previousLengthSum=generations.getCurrentBestLength();
        if(failCounter>=overdDriveThreshhold){
            failCounter=0;
            chance=chance+0.1;
            generations.improve(town);
        }
        else{
            chance=genomMutationChance;
            failCounter=0;
        }
        generations.createNewGeneration(*&town,chance,true);
        generations.calcFitnessAll(*&town);
        if(generations.getCurrentBestLength()==previousLengthSum)failCounter++;
        if(j%100==0){
            std::cout<<generations.getBestLength()<<" "<<generations.getCurrentBestLength()<<" "<<generations.getCurrentLengthSum()<<std::endl;
            for(auto it:generations.getBestRoute().getRoute()){
                std::cout<<it<<" ";
            }
            std::cout<<std::endl;
        }
        j++;
    }
    return 0;
}