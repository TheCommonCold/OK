#include "init.h"

double zachlanny_artura_pojedynczy(int start,map &town, route &path) {
    bool odwiedzone[town.getSize()];
    for (int i=0;i<town.getSize();i++) odwiedzone[i]=false;
    int min_neighbour;
    double min_dist,cur_dist;
    double sum_dist=0;
    path.setRoute(start,0);
    odwiedzone[start]=true;
    for (int i=1;i<town.getSize();i++) {
        min_dist=0;
        for (int j=0;j<town.getSize();j++) {
            if(path.getRoute(i-1)==j) continue;
            cur_dist=town.getDistance(path.getRoute(i-1),j);
            if(!odwiedzone[j]&&(cur_dist<min_dist||min_dist==0)) {
                min_dist = cur_dist;
                min_neighbour = j;
            }
        }
        //std::cout<<min_neighbour<<" "<<min_dist<<std::endl;
        path.setRoute(min_neighbour,i);
        sum_dist+=min_dist;
        odwiedzone[min_neighbour]=true;
    }
//    std::cout<<sum_dist;
    sum_dist+=town.getDistance(path.getRoute(0),path.getRoute(town.getSize()-1));
//    std::cout<<" "<<sum_dist;
//    std::cout<<" "<<town.getSize()-1;
//    std::cout<<" "<<path[0];
//    std::cout<<" "<<path[town.getSize()-1];
//    std::cout<<" "<<town.getDistance(path[0],path[town.getSize()-1]);
//    std::cout<<std::endl;
    return sum_dist;
}

double zachlanny_artura( map &town, route &path) {
    route path_cur;
    route path_min;
    double min_dist,cur_dist;
    for (int i=0;i<town.getSize();i++)
    {
        cur_dist=zachlanny_artura_pojedynczy(i,town,path_cur);
        //std::cout << cur_dist;
        //std::cout<<std::endl;
        //for(int j=0;j<town.getSize();j++) {
        //    std::cout << path_cur.getRoute(j) << " ";
        //}
        //std::cout<<" "<< cur_dist<<std::endl;
        if(cur_dist<min_dist||i==0)
        {
            min_dist=cur_dist;
            for(int j=0;j<town.getSize();j++)
            {
                path_min.setRoute(path_cur.getRoute(j),j);
            }
        }
    }
    for(int j=0;j<town.getSize();j++) {
        path.setRoute(path_min.getRoute(j),j);
    }
    return min_dist;
}

void populateGeneration( map &town, route generation[generationSize]) {
    int i;
    for (i=0;i<town.getSize() && i<generationSize ;i++)
    {
        generation[i].setFitness(zachlanny_artura_pojedynczy(i,town,*&generation[i]));
    }
    srand (time(NULL));
    while(i<generationSize){
        int targetA=rand()%i;
        int targetB=rand()%i;
        mutateCross(generation[targetA],generation[targetB],*&generation[i],*&town);
        generation[i].calcFitness(*&town);
        i++;
    }
}

