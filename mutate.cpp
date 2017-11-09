#include "mutate.h"

void mutateCross(route a, route b, route &out, map &town){
    int i=1;
    srand (time(NULL));
    int target=rand()%2;
    if(target)out.setRoute(a.getRoute(0),0);
    else out.setRoute(b.getRoute(0),0);
    while(i<town.getSize()){
        target=rand()%2;
        int j=0;
        if(target)
        {
            while(a.getRoute(j)!=out.getRoute(i-1))
            {
                j++;
            }
            out.setRoute(a.getRoute(j+1),i);
        }else
        {
            while(b.getRoute(j)!=out.getRoute(i-1))
            {
                j++;
            }
            out.setRoute(b.getRoute(j+1),i);
        }
        for(j=0;j<i;j++)
        {
            if(out.getRoute(j)==out.getRoute(i)){
                for(int h=0;h<town.getSize();h++){
                    bool alreadyIn=0;
                    for(int g=0;g<i;g++){
                        if(target){
                            if(a.getRoute(h)==out.getRoute(g))alreadyIn=1;
                        }
                        else{
                            if(b.getRoute(h)==out.getRoute(g))alreadyIn=1;
                        }
                    }
                    if(!alreadyIn){
                        if(target)out.setRoute(a.getRoute(h),i);
                        else out.setRoute(b.getRoute(h),i);
                        break;
                    }
                }
                break;
            }
        }
        //std::cout<<out.getRoute(i)<<" ";
        i++;
    }
    //std::cout<<std::endl;
}