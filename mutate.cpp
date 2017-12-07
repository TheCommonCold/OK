#include "mutate.h"
#include "misc.h"

void breedCross2(route a, route b, route &out, map &town){
    int i=1;
    int target=getRandomNumber(1);
    if(target)out.addTown(a.getTown(0));
    else out.addTown(b.getTown(0));
    while(i<town.getSize()){
        target=getRandomNumber(1);
        int j=0;
        if(target)
        {
            while(a.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.addTown(a.getTown(j + 1));
        }else
        {
            while(b.getTown(j)!= out.getTown(i - 1))
            {
                j++;
            }
            out.addTown(b.getTown(j + 1));
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
        out->addTown(a.getTown(i));
        visited[a.getTown(i)]=true;
    }
    int j=0;
    while(i<town->getSize()){
        if(visited[b.getTown(j)]==false){
            out->addTown(b.getTown(j));
            visited[b.getTown(j)]=true;
            i++;
        }
        j++;
    }
    mutate(out,chance,*town);
}

void PMXboi(route a, route b,route* out, map* town,double chance) {
//    for (auto i:a.getRoute()){
//        std::cout<<i<<" ";
//    }
//    std::cout<<std::endl;
//    for (auto i:b.getRoute()){
//        std::cout<<i<<" ";
//    }
//    std::cout<<std::endl;
    int iloscMiast=town->getSize();
    int liczba[2]={3,7};
    do {
       for (int i = 0; i < 2; i++) liczba[i] = getRandomNumber(iloscMiast);

    }while(liczba[0]==liczba[1]);
    if(liczba[0]>liczba[1]){
        int tmp=liczba[0];
        liczba[0]=liczba[1];
        liczba[1]=tmp;
    }
    std::vector<int> child;
    bool uzyte[iloscMiast];
    int pozycje[2][iloscMiast];
    for(int i=0;i<iloscMiast;i++){
        child.emplace_back();
        uzyte[i]=false;
        pozycje[0][a.getTown(i)]=i;
        pozycje[1][b.getTown(i)]=i;
    }

    for (int i=liczba[0];i<liczba[1];i++)
    {
        child[i]=a.getTown(i);
        uzyte[child[i]]=true;
    }
    int townToPlace, currentTown, indeks;
    for (int i=liczba[0];i<liczba[1];i++) {
        townToPlace = b.getTown(i);
        if (!uzyte[townToPlace]) {
            currentTown = townToPlace;
            do {
                indeks = pozycje[1][currentTown];
                currentTown = a.getTown(indeks);
//                std::cout<<currentTown<<" "<<indeks<<" "<<townToPlace<<std::endl;
            } while (indeks>=liczba[0]&&indeks<liczba[1]);
            child[indeks] = townToPlace;
            uzyte[townToPlace]=true;
        }
//        for (auto i:child){
//            std::cout<<i<<" ";
//        }
//        std::cout<<std::endl;
    }
    for(int i=0;i<iloscMiast;i++){
        if (!uzyte[b.getTown(i)]){
            child[i]=b.getTown(i);
        }
    }
//    for (auto i:child){
//        std::cout<<i<<" ";
//    }
//    std::cout<<std::endl;
    out->setRoute(child,*town);
}


void breedER(route a, route b,route* out, map* town,double chance){
    int n=a.getTown(0);
//    for(int i=0;i<town->getSize();i++){
//        std::cout<<a.getTown(i)<<" ";
//    }
//    std::cout<<std::endl;
//    for(int i=0;i<town->getSize();i++){
//        std::cout<<b.getTown(i)<<" ";
//    }
//    std::cout<<std::endl;
//    std::cout<<std::endl;
    bool neighbourList[town->getSize()][town->getSize()];
    bool visited[town->getSize()];
    int neighbourCount[town->getSize()];
    for(int i=0;i<town->getSize();i++)
    {
        visited[i]=false;
        neighbourCount[i]=0;
        for(int j=0;j<town->getSize();j++){
            neighbourList[i][j]=false;
        }
    }
    neighbourCount[a.getTown(0)]++;
    neighbourCount[a.getTown(town->getSize()-1)]++;
    neighbourList[a.getTown(town->getSize()-1)][a.getTown(0)]=true;
    neighbourList[a.getTown(0)][a.getTown(town->getSize()-1)]=true;
    if(neighbourList[b.getTown(0)][b.getTown(town->getSize()-1)]==false)
    {
        neighbourCount[b.getTown(0)]++;
        neighbourCount[b.getTown(town->getSize()-1)]++;
        neighbourList[b.getTown(town->getSize()-1)][b.getTown(0)]=true;
        neighbourList[b.getTown(0)][b.getTown(town->getSize()-1)]=true;
    }
    for(int i=0;i<town->getSize()-1;i++){
        if(a.getTown(i)!=a.getTown(i+1) && neighbourList[a.getTown(i)][a.getTown(i+1)]==false){
            neighbourCount[a.getTown(i)]++;
            neighbourCount[a.getTown(i+1)]++;
            neighbourList[a.getTown(i)][a.getTown(i+1)]=true;
            neighbourList[a.getTown(i+1)][a.getTown(i)]=true;
        }
        if(b.getTown(i)!=b.getTown(i+1) && neighbourList[b.getTown(i)][b.getTown(i+1)]==false){
            neighbourCount[b.getTown(i)]++;
            neighbourCount[b.getTown(i+1)]++;
            neighbourList[b.getTown(i)][b.getTown(i+1)]=true;
            neighbourList[b.getTown(i+1)][b.getTown(i)]=true;
        }
        //std::cout<<neighbourCount[31]<<std::endl;
    }
//    for(int i=0;i<town->getSize();i++)
//    {
//        for(int j=0;j<town->getSize();j++){
//            std::cout<<neighbourList[i][j]<<" ";
//        }
//        std::cout<<"   "<<neighbourCount[i];
//        std::cout<<std::endl;
//    }
    out->addTown(n);
    std::vector<int> randomList;
    while(out->getSize()<town->getSize())
    {
        randomList.clear();
        visited[n]=true;
        for(int i=0;i<town->getSize();i++)
        {
            if(neighbourList[i][n]==1)neighbourCount[i]--;
            neighbourList[i][n]=0;
        }
        if(neighbourCount[n]>0){
            int smallestValue=town->getSize();
            for(int i=0;i<town->getSize();i++){
                if(neighbourList[n][i]==1){
                    if(neighbourCount[i]<smallestValue){
                        smallestValue=neighbourCount[i];
                    }
                }
            }
            for(int i=0;i<town->getSize();i++){
                if(neighbourCount[i]==smallestValue && neighbourList[n][i]==1)randomList.push_back(i);
            }
        }else
        {
            for(int i=0;i<town->getSize();i++)
            {
                if(visited[i]==0)randomList.push_back(i);
            }
        }
        neighbourCount[n]=0;
//        for(int i=0;i<town->getSize();i++){
//            std::cout<<visited[i]<<" ";
//        }
//        std::cout<<std::endl;
        n=randomList[getRandomNumber(randomList.size()-1)];
        out->addTown(n);
    }
//    for(int i=0;i<town->getSize();i++){
//        std::cout<<out->getTown(i)<<" ";
//    }
//    std::cout<<std::endl;
//    std::cout<<std::endl;
    mutate(out,chance,*town);
    out->calcLength(*town);
}

// Do all 2-opt combinations
void TwoOpt(route a, route b,route* out, map* town,double chance)
{
    // Get tour size
    int size = a.getSize();

    // repeat until no improvement is made
        b.clearRoute();
        double best_distance = a.calcLength(*town);

        for ( int i = 0; i < size - 1; i++ )
        {
            for ( int k = i + 1; k < size; k++)
            {
                TwoOptSwap( i, k,a, b);

                double new_distance = a.calcLength(*town);

                if ( new_distance < best_distance )
                {
                    // Improvement found so reset
                    a = b;
                    best_distance = new_distance;
                }
            }
        }
    *out=a;
}

void TwoOptSwap( const int& i, const int& k, route a, route &b)
{
    int size = a.getSize();

    // 1. take route[0] to route[i-1] and add them in order to new_route
    for ( int c = 0; c <= i - 1; ++c )
    {
        b.addTown(a.getTown(c));
    }

    // 2. take route[i] to route[k] and add them in reverse order to new_route
    int dec = 0;
    for ( int c = i; c <= k; ++c )
    {
        b.addTown(a.getTown(k - dec));
        dec++;
    }

    // 3. take route[k+1] to end and add them in order to new_route
    for ( int c = k + 1; c < size; ++c )
    {
        b.addTown(a.getTown(c));
    }
}

void generateRandomMember(route &child,map &town){
    for(int i=0;i<town.getSize();i++)
    {
        child.addTown(i);
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
    double chance=(MutationChance*1000);
    long long mutate=0;
    int swapA,swapB,j;
    for(int i=0;i<a->getSize();i++){
        mutate=getRandomNumber(1000-1)+1;
        if(mutate<=chance){
            j=getRandomNumber(a->getSize()-1);
            swapA=a->getTown(i);
            swapB=a->getTown(j);
            a->setTown(swapB,i);
            a->setTown(swapA,j);
        }
    }
    //if(a->calcLength(town)>b.calcLength(town))a=&b;
}


void wypislosowych(std::mt19937 mt,std::uniform_int_distribution<int> dis){
    for(int i=0;i<100;i++) std::cout<<dis(mt)<<std::endl;
}

