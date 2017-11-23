//
// Created by artur on 11/16/17.
//
#include "genePool.h"
#include "misc.h"
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

int genePool::findParentNormalized(){
    int sum=0;
    int i=0;
    for(i=0;i<this->getSpeciman(0).getSize();i++)
    {
        sum=sum+i;
    }
    int wylosowana=getRandomNumber(sum);
    i--;
    while(true){
        wylosowana=wylosowana-i;
        if (wylosowana<=0)return i;
        i--;
    }
}

void genePool::calcFitnessAll(map &town) {
    int length;
    bool pierwszy=true;
    for (route &it: this->pool){
        length=it.getLength();
        if(length>this->currentWorstLength)this->currentWorstLength=length;
        if(length<this->currentBestLength||pierwszy){
            this->currentBestLength=length;
            pierwszy=false;
            if(length<this->bestRoute.getLength()) this->bestRoute.setRoute(it.getRoute(),town);
        }
    }
    unsigned long long FitnessSum=0,LengthSum=0;
    for (route &it: this->pool){
        it.setFitness(1.1*this->currentWorstLength-it.getLength());
        FitnessSum+=it.getFitness();
        LengthSum+=it.getLength();
    }
    this->currentLengthSum=LengthSum;
    this->currentFitnessSum=FitnessSum;
}