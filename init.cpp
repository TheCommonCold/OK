#include "init.h"
#include "genePool.h"
#include <iostream>

double zachlannyArtura(map &towns, genePool &generations) {
    double worstLength=0;
    int minNeighbour=0;
    bool odwiedzone[towns.getSize()];
    for (int i=0;i<towns.getSize() && i<generationSize ;i++)
    {
        for (int j=0;j<towns.getSize();j++) odwiedzone[j]=false;
        odwiedzone[i]=true;
        double minDist=0,curDist=0;
        std::vector<int> path={i};
        for (int j=1;j<towns.getSize();j++){
            minDist=0;
            for(int k=0;k<towns.getSize();k++){
                if(!odwiedzone[k]){
                    curDist=towns.getDistance(path[j-1],k);
                    if(curDist<minDist||minDist==0){
                        minDist=curDist;
                        minNeighbour=k;
                    }
                }
            }
            odwiedzone[minNeighbour]=true;
            path.push_back(minNeighbour);
        }

        route curRoute;

        //for (int &it:path) std::cout<<it<<std::endl;

        curRoute.setRoute(path,towns);
        generations.addSpeciman(curRoute, towns);
        generations.setBestRoute(curRoute,towns,!i);
        generations.setCurrentBestLength(curRoute.getLength(),!i);

        double length=curRoute.getLength();
        if (length>worstLength) worstLength=length;
    }
    generations.calcFitnessAll(towns);
    return generations.getBestLength();
}

unsigned long long getRandomNumber(unsigned long long max){
    static std::mt19937 mt(1729);
    std::uniform_int_distribution<unsigned long long> dist(0, max);
    return dist(mt);
}

void populateGeneration( map &town, genePool &generation) {
    int i=town.getSize();
    route child;
    while(i<generationSize){
        child.clearRoute();
        breedCross(generation.getSpeciman(generation.findParent()), generation.getSpeciman(generation.findParent()),
                   *&child, *&town);
        mutate(child);
        generation.addSpeciman(child,*&town);
        i++;
    }
}

bool checkVector(std::vector<int> vec,double length,map &town, genePool generation){
    double len=0;
    //std::cout<<vec.size()<<std::endl;
    for (auto it=vec.begin();it<vec.end()-1;it++){
        len+=town.getDistance(*it,*(it+1));
    }
    len+=town.getDistance(*vec.begin(),*(vec.end()-1));
    std::cout<<len<<" "<<length<<"\n";
    if(len>length+0.00001||len<length-0.00001){
        std::cout<<"Skopalem liczenie dlugosci "<<len<<" "<<length<<std::endl;
        return false;
    }
    bool odwiedzone[vec.size()];
    for(int i=0;i<vec.size();i++){
        odwiedzone[i]=false;
    }
    for(int i=0;i<vec.size();i++){
        odwiedzone[vec[i]]=true;
    }
    for(int i=0;i<vec.size();i++){
        if(!odwiedzone[i]){
            std::cout<<"Nie odwiedza wszystkich miast\n";
            return false;
        }
    }
    //std::cout<<"Skopałem liczenie dlugosci\n";
    return false;
}