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
    route out;
    std::ifstream wczytaj("C:\\Users\\Luker\\Documents\\GitHub\\OK\\test.txt");
    for(int i=0;i<town.getSize();i++)
    {
        int temp;
        wczytaj>>temp;
        a.addRoute(temp);
    }
    for(int i=0;i<town.getSize();i++)
    {
        int temp;
        wczytaj>>temp;
        b.addRoute(temp);
    }
    breedER(a, b, &out, &town,0);

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
        std::cout<<j<<std::endl;
        previousLengthSum=generations.getCurrentLengthSum();
        if(failCounter>=overdDriveThreshhold){
            failCounter=0;
            chance=chance+0.1;
            //generations.improve(town);
        }
        generations.createNewGeneration(*&town,chance,true);
        generations.calcFitnessAll(*&town);
        if(generations.getCurrentLengthSum()==previousLengthSum)failCounter++;
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