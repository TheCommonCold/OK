//
// Created by artur on 11/16/17.
//
#include "genePool.h"
#include "init.h"
int genePool::findParent(){
    auto FitnessSum=this->getCurrentFitnessSum();
    int wylosowana=getRandomNumber(FitnessSum);
    int i=0;
    while(true){
        wylosowana-=this->pool[i].getFitness();
        if (wylosowana<=0)return i;
        i++;
    }
}

void genePool::calcFitnessAll(map &town) {
    int length;
    for (route &it: this->pool){
        length=it.getLength();
        if(length>this->currentWorstLength)this->currentWorstLength=length;
        if(length<this->currentBestLength){
            this->currentBestLength=length;
            if(length<this->bestRoute.getLength()) this->bestRoute.setRoute(it.getRoute(),town);
        }
    }
    unsigned long long FitnessSum=0;
    for (route &it: this->pool){
        it.setFitness(1.1*this->currentWorstLength-it.getLength());
        FitnessSum+=it.getFitness();
    }
    this->currentFitnessSum=FitnessSum;
}