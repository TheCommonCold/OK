#include "mutate.h"
#include "init.h"

void mutateCross(route a, route b, route &out, map &town){
    int i=1;
    int target=getRandomNumber(2);
    if(target)out.setTown(a.getTown(0), 0);
    else out.setTown(b.getTown(0), 0);
    while(i<town.getSize()){
        target=getRandomNumber(2);
        int j=0;
        if(target)
        {
            while(a.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.setTown(a.getTown(j + 1), i);
        }else
        {
            while(b.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.setTown(b.getTown(j + 1), i);
        }
        for(j=0;j<i;j++)
        {
            if(out.getTown(j)== out.getTown(i)){
                for(int h=0;h<town.getSize();h++){
                    bool alreadyIn=0;
                    for(int g=0;g<i;g++){
                        if(target){
                            if(a.getTown(h)== out.getTown(g))alreadyIn=1;
                        }
                        else{
                            if(b.getTown(h)== out.getTown(g))alreadyIn=1;
                        }
                    }
                    if(!alreadyIn){
                        if(target)out.setTown(a.getTown(h), i);
                        else out.setTown(b.getTown(h), i);
                        break;
                    }
                }
                break;
            }
        }
        //std::cout<<out.getTown(i)<<" ";
        i++;
    }
    //std::cout<<std::endl;
}
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis){
    for(int i=0;i<100;i++) std::cout<<dis(mt)<<std::endl;
}