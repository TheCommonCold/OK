#include "map.h"

void map::load(){
    //Kiedyś trzeba to ogarnąc
    std::cout<<"[map.load()] Kto otwiera?\n0 - Lukasz\n1 - Artur Y70\n2 - Artur Linux\n3 - Artur Win Y550(trza dodac)\n";
    int number_of_location;
    std::string location_of_files;
    std::cin>>number_of_location;
    switch (number_of_location)
    {
        case 0:
            location_of_files="C:\\Users\\Luker\\Documents\\GitHub\\OK\\plik.txt";
            break;
        case 1:
            location_of_files="D:\\Artur\\Repos\\OK\\plik.txt";
            break;
        case 2:
            location_of_files="/home/artur/Repos/CLion/OK/plik.txt";
            break;
        default:
            std::cout<<"location unspecified"<<std::endl;
            return;
    }
    std::ifstream file(location_of_files);
    file>>this->size;
    for(int i=0;i<this->size;i++){
        //dwa razy bo najpierw wczytuje numer miasta ktorego nie uzywamy potem x i y
        file>>this->coords[i][0];
        file>>this->coords[i][0];
        file>>this->coords[i][1];
    }
}

int map::getSize(){
    return this->size;
}

double map::getDistance(int i, int j){
   //std::cout<<"a  1  "<<x<<" "<<y<<std::endl;
    return sqrt(pow((this->coords[i][0]-this->coords[j][0]),2)+pow((this->coords[i][1]-this->coords[j][1]),2));
}

int map::getX(int x){
    return this->coords[x][0];
}

int map::getY(int x){
    return this->coords[x][1];
}

//generator losowej instancji
void map::create(int size,int MaxNumber){
    srand (time(NULL));
    this->size=size;
    int i =0;
    while(i<size){
        int Duplicates=0;
        this->coords[i][0]=rand()%MaxNumber;
        this->coords[i][1]=rand()%MaxNumber;
        for(int j=0;j<i;j++){
            if(this->coords[j][0]==this->coords[i][0]){
                Duplicates++;
            }
            if(this->coords[j][1]==this->coords[i][1]){
                Duplicates++;
            }
        }
        if(Duplicates==0)i++;
    }
}

//generator chorej instancji
void map::createMeme(int size) {
    srand (time(NULL));
    this->size=size;
    int i =0;
    int RandomPos;
    int RandomSize;
    while(i<size){
        int Duplicates=0;
        RandomSize=rand()%size;
        RandomPos=rand()%size;
        this->coords[i][0]=RandomPos;
        this->coords[i][1]=RandomPos;
        i++;
        this->coords[i][0]=RandomPos+RandomSize;
        this->coords[i][1]=RandomPos;
        i++;
        this->coords[i][0]=RandomPos;
        this->coords[i][1]=RandomPos+RandomSize;
        i++;
        this->coords[i][0]=RandomPos+RandomSize;
        this->coords[i][1]=RandomPos+RandomSize;
        i++;
        for(int j=0;j<i;j++){
            if(this->coords[j][0]==this->coords[i][0]){
                Duplicates++;
            }
            if(this->coords[j][1]==this->coords[i][1]){
                Duplicates++;
            }
        }
        if(Duplicates==0)i=i-4;
    }
}

//tworzy plik wyjsciowy z instancja
void map::CreateMapFile() {
    std::ofstream file("C:\\Users\\Luker\\CLionProjects\\OK_Projekt V3\\map.txt");
    file<<this->size<<std::endl;
    for(int i=0;i<this->size;i++){
        file<<i+1<<" ";
        file<<this->coords[i][0]<<" ";
        file<<this->coords[i][1]<<std::endl;
    }
}