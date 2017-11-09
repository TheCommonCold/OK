#include "mutate.h"

void mutateCross(route a, route b, route &out, map &town){
    int i=1;
    srand (time(NULL));
    int target=rand()%2;
    if(target)out.setRoute(a.getRoute(0),0);
    else out.setRoute(b.getRoute(0),0);
    while(i<town.getSize()){
        target=rand()%2;
        int search;
        while(search!=b.getRoute(i-1))
        {

        }
        i++;
    }
}