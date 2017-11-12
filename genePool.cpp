#include "genePool.h"

void genePool::setMaxFitness(double a)
{
    this->currentMaxFitness=a;
}

double genePool::getMaxFitness(){
    return this->currentMaxFitness;
}

//double genePool::calcMaxFitness(route generation[generationSize], map &town){
//    this->currentMaxFitness=0;
//    for(int i =0; i<town.getSize();i++)
//    {
//        this->currentMaxFitness+=+generation[i].getFitness();
//    }
//    return this->currentMaxFitness;
//}
void genePool::setPool(route a,int number, int whichPopulaton){
    //ogarnąć
    this->pool[number][whichPopulaton].setRoute(a.getRoute());
}
route genePool::getPool(int number, int whichPopulaton){
    //ogarnąć
    return this->pool[number][whichPopulaton];
}
void genePool::setBestRoute(route a) {
    this->bestRoute.setRoute(a.getRoute());
}
route genePool::getBestRoute(){
    return this->bestRoute;
}
void genePool::setCurrentFitnessSum(unsigned long long a){
        this->currentFitnessSum=a;
}
unsigned long long genePool::getCurrentFitnessSum(){
    return this->currentFitnessSum;
}
void genePool::createPool(route generation[generationSize], map &town){
    std::cout<<generation[0].getFitness()/this->currentMaxFitness;
}
void genePool::setCurrentBestLength(double a){
    this->currentBestLength=a;
}
double genePool::getBestLength(){
    return this->bestRoute.getLength();
}
double genePool::getCurrentBestLength(){
    return this->currentBestLength;
}

//currentGenration
void genePool::setCurrentGeneration(short a){
    this->currentGeneration=a;
}
int genePool::getCurrentGeneration(){
    return this->currentGeneration;
}
int genePool::switchGenerations(){
    this->currentGeneration=1-this->currentGeneration;
    return this->currentGeneration;

}
