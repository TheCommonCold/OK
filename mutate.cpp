#include "mutate.h"
#include "init.h"

void breedCross(route a, route b, route &out, map &town){
    int i=1;
    int target=getRandomNumber(1);
    if(target)out.addRoute(a.getTown(0));
    else out.addRoute(b.getTown(0));
    while(i<town.getSize()){
        target=getRandomNumber(1);
        int j=0;
        if(target)
        {
            while(a.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.addRoute(a.getTown(j + 1));
        }else
        {
            while(b.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.addRoute(b.getTown(j + 1));
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
                        if(target)out.setTown(a.getTown(h),i);
                        else out.setTown(b.getTown(h),i);
                        break;
                    }
                }
                break;
            }
        }
        std::cout<< out.getTown(i)<<" ";
        i++;
    }
    std::cout<< out.getTown(0)<<" ";
    std::cout<<std::endl;
}

void mutate(route &a) {
    float chance = mutationChance;
    chance=(chance*1000);
    int mutate=0;
    int swapA,swapB,j;
    for(int i=0;i<a.getSize();i++){
        mutate=getRandomNumber(999)+1;
        if(mutate<=chance){
            j=getRandomNumber(a.getSize()-1);
            swapA=a.getTown(i);
            swapB=a.getTown(j);
            a.setTown(swapB,i);
            a.setTown(swapA,j);

        }
    }
}
void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis){
    for(int i=0;i<100;i++) std::cout<<dis(mt)<<std::endl;
}