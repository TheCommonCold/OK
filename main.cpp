#include <iostream>
#include <fstream>
#include "map.h"
#include "route.h"
#include "mutate.h"
#include "init.h"

int main() {
    map town;
    route path;
    route generation[generationSize];
    town.load();
    //town.createMeme(80);
    //town.CreateMapFile();
    double min_zachlanny;
    //std::cout<<zachlanny_artura_pojedynczy(0,town,path);
    min_zachlanny=zachlanny_artura(*&town, *&path);
    std::cout<<min_zachlanny<<" "<<path.getRoute(0)<<std::endl;
    populateGeneration(*&town,*&generation);
    mutateCross(*&generation[0],*&generation[1],*&generation[25],*&town);
    //std::cout<<generation[20].getRoute(0)<<"  "<<generation[20].getFitness();
    return 0;
}