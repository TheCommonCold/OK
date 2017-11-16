#include "mutate.h"
#include "init.h"

void mutateCross(route a, route b, route &out, map &town){
    int i=1;
    int target=getRandomNumber(1);
    if(target)out.addRoute(a.getRoute(0));
    else out.addRoute(b.getRoute(0));
    while(i<town.getSize()){
        target=getRandomNumber(1);
        int j=0;
        if(target)
        {
            while(a.getRoute(j)!= out.getRoute(i - 1))
            {
                j++;
            }
            out.addRoute(a.getRoute(j + 1));
        }else
        {
            while(b.getRoute(j)!= out.getRoute(i - 1))
            {
                j++;
            }
            out.addRoute(b.getRoute(j + 1));
        }
        for(j=0;j<i;j++)
        {
            if(out.getRoute(j)== out.getRoute(i)){
                for(int h=0;h<town.getSize();h++){
                    bool alreadyIn=0;
                    for(int g=0;g<i;g++){
                        if(target){
                            if(a.getRoute(h)== out.getRoute(g))alreadyIn=1;
                        }
                        else{
                            if(b.getRoute(h)== out.getRoute(g))alreadyIn=1;
                        }
                    }
                    if(!alreadyIn){
                        if(target)out.addRoute(a.getRoute(h));
                        else out.addRoute(b.getRoute(h));
                        break;
                    }
                }
                break;
            }
        }
        std::cout<< out.getRoute(i)<<" ";
        i++;
    }
    std::cout<<std::endl;
}
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis){
    for(int i=0;i<100;i++) std::cout<<dis(mt)<<std::endl;
}