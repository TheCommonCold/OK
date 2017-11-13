#include "init.h"

double zachlannyArtura(map &towns, genePool &generations) {
    double worstLength=0;
    int minNeighbour=0;
    bool odwiedzone[towns.getSize()];
    for (int i=0;i<towns.getSize();i++)
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
        generations.setBestRoute(generations.getPool().back(),towns,!i);
        double length=curRoute.getLength();
        if (length>worstLength) worstLength=length;
    }
    generations.setWorstLength(worstLength, true);
    return generations.getBestLength();
}

