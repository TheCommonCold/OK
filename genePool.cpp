#include "genePool.h"

void genePool::setMaxFitness(double a)
{
    this->maxFitness=a;
}

double genePool::getMaxFitness(){
    return this->maxFitness;
}
double genePool::calcMaxFitness(route generation[generationSize], map &town)
{
    for(int i =0; i<town.getSize();i++)
    {
        this->maxFitness=this->maxFitness+generation[i].getFitness();
    }
    return this->maxFitness;
}
void genePool::setPool(short int a,short int i){
    this->pool[i]=a;
}
short int genePool::getPool(short int i){
    return this->pool[i];
}

void genePool::createPool(route generation[generationSize], map &town){
    std::cout<<generation[0].getFitness()/this->maxFitness;
}