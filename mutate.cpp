#include "mutate.h"
#include "misc.h"

void breedCross2(route a, route b, route &out, map &town){
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

void breedCrossadolf(route a, route b, route &out, map &town) {
out=b;
}

void breedCross(route a, route b, route* out, map* town,double chance){
    bool visited[town->getSize()];
    for (int j=0;j<town->getSize();j++) visited[j]=false;
    int ratio=getRandomNumber(town->getSize());
    int i=0;
    for(;i<ratio;i++){
        out->addRoute(a.getTown(i));
        visited[a.getTown(i)]=true;
    }
    int j=0;
    while(i<town->getSize()){
        if(visited[b.getTown(j)]==false){
            out->addRoute(b.getTown(j));
            visited[b.getTown(j)]=true;
            i++;
        }
        j++;
    }
    mutate(out,chance,*town);
}

void breedER(route a, route b,route* out, map* town,double chance){
    bool neighbourList[town->getSize()][town->getSize()];
    neighbourList[a.getTown(0)][a.getTown(town->getSize()-1)]=1;
    neighbourList[a.getTown(a.getTown(town->getSize()-1))][0]=1;
    neighbourList[b.getTown(0)][b.getTown(town->getSize()-1)]=1;
    neighbourList[b.getTown(b.getTown(town->getSize()-1))][0]=1;
    for(int i=0;i<town->getSize();i++){
        for(int j=1;j<town->getSize()-1;j++)
        {
            if(a.getTown(j-1)==i)
            {
                neighbourList[i][a.getTown(j-1)]=1;
            }
            if(b.getTown(j-1)==1)
            {
                neighbourList[i][b.getTown(j-1)]=1;
            }
            if(a.getTown(j+1)==i)
            {
                neighbourList[i][a.getTown(j+1)]=1;
            }
            if(b.getTown(j+1)==1)
            {
                neighbourList[i][b.getTown(j+1)]=1;
            }
        }
    }
    //mutate(out,chance,*town);
}

void generateRandomMember(route &child,map &town){
    for(int i=0;i<town.getSize();i++)
    {
        child.addRoute(i);
    }
    int swapA,swapB,j;
    for(int i=0;i<child.getSize();i++){
        j=getRandomNumber(child.getSize()-1);
        swapA=child.getTown(i);
        swapB=child.getTown(j);
        child.setTown(swapB,i);
        child.setTown(swapA,j);
    }
}

void fix(route* a,map* town, bool* change) {
    change=0;
    for(int i=0;i<a->getSize();i++)
    {
        for(int j=i+1;j<a->getSize();j++)
        {
            double originalLength=a->calcLength(*town);
            int temp = a->getTown(i);
            a->setTown(a->getTown(j),i);
            a->setTown(temp,j);
            if(originalLength<a->calcLength(*town)){
                temp = a->getTown(i);
                a->setTown(a->getTown(j),i);
                a->setTown(temp,j);
            }else *change=true;
        }
    }
}

void mutate(route* a,double MutationChance,map &town) {
    route b;
    b.setRoute(a->getRoute(),town);
    double chance=(MutationChance/(a->getSize())*1000000);
    long long mutate=0;
    int swapA,swapB,j;
    for(int i=0;i<a->getSize();i++){
        mutate=getRandomNumber(1000000-1)+1;
        if(mutate<=chance){
            j=getRandomNumber(a->getSize()-1);
            swapA=a->getTown(i);
            swapB=a->getTown(j);
            a->setTown(swapB,i);
            a->setTown(swapA,j);
        }
    }
    if(a->calcLength(town)>b.calcLength(town))a=&b;
}


void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis){
    for(int i=0;i<100;i++) std::cout<<dis(mt)<<std::endl;
}

