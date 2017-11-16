#include "genePool.h"
#include "mutate.h"
#include "init.h"

void genePool::setMaxFitness(double a, bool force=false) {if (force||a>this->currentMaxFitness) this->currentMaxFitness=a;}



double genePool::getMaxFitness(){    return this->currentMaxFitness; }
//currentWorstLength
void genePool::setWorstLength(double a, bool force = false){    if(force||a<this->currentWorstLength)this->currentWorstLength=a; }
double genePool::getWorstLength(){     return this->currentWorstLength; }

//double genePool::calcMaxFitness(route generation[generationSize], map &town){
//    this->currentMaxFitness=0;
//    for(int i =0; i<town.getSize();i++)
//    {
//        this->currentMaxFitness+=+generation[i].getFitness();
//    }
//    return this->currentMaxFitness;
//}
void genePool::addSpeciman(route a, map &town){
    //ogarnąć
    this->pool.push_back(a);
    double length=this->pool.back().getLength();
    if (length<this->currentBestLength)
    {
        this->currentBestLength=length;
        this->currentMaxFitness=this->pool.back().getFitness();
    }
}
route genePool::getSpeciman(int number){    return this->pool[number]; }

void genePool::setBestRoute(route a, map &town, bool force) { if (force||a.getLength()<this->bestRoute.getLength())this->bestRoute.setRoute(a.getRoute(), town); }

route genePool::getBestRoute(){    return this->bestRoute;}

void genePool::setCurrentFitnessSum(unsigned long long a){        this->currentFitnessSum=a;}

unsigned long long genePool::getCurrentFitnessSum(){    return this->currentFitnessSum;}

void genePool::createPool(route generation[100], map &town){
    std::cout<<"[genePool::createPool] funkcja nie dostosowana pod vector i trzymanie wszystkiego w genepoolu"<<std::endl;
    std::cout<<generation[0].getFitness()/this->currentMaxFitness;
}

void genePool::setCurrentBestLength(double a, bool force) {if (force||a<this->currentBestLength)this->currentBestLength=a;}

double genePool::getBestLength(){ return this->bestRoute.getLength();}

double genePool::getCurrentBestLength(){ return this->currentBestLength;}

std::vector<route> genePool::getPool(){ return this->pool;}



//Printy
void genePool::printSpeciman(int number){
    for( int &it: this->getSpeciman(number).getRoute()){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl<<this->getSpeciman(number).getLength()<<std::endl ;
}

void genePool::printAllSpecimen() {
    int i=0;
    for (route &ite: this->pool){
        this->printSpeciman(i);
        i++;
    }
}

int genePool::getPoolSize(){return this->pool.size();}

void genePool::createNewGeneration(map &town){
    int size=this->getPoolSize();
    route child;
    for(int i=0;i<size;i++){
        mutateCross(this->getSpeciman(findParent()),this->getSpeciman(findParent()),child,*&town);
        this->addSpeciman(child,*&town);
        this->pool.erase(this->pool.begin(),this->pool.begin()+generationSize);
    }

}