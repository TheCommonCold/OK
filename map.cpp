#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "map.h"

void map::load(){
    std::ifstream file("C:\\Users\\Luker\\CLionProjects\\OK_Projekt V3\\tsp500.txt");
    file>>this->size;
    for(int i=0;i<this->size;i++){
        file>>this->coords[i][0];
        file>>this->coords[i][0];
        file>>this->coords[i][1];
    }
}

int map::getSize(){
    return this->size;
}

double map::getDistance(int x, int y){
   //std::cout<<"a  1  "<<x<<" "<<y<<std::endl;
    return sqrt(((this->coords[x][0]-this->coords[y][0])*(this->coords[x][0]-this->coords[y][0]))+((this->coords[x][1]-this->coords[y][1])*(this->coords[x][1]-this->coords[y][1])));
}

int map::getX(int x){
    return this->coords[x][0];
}

int map::getY(int x){
    return this->coords[x][1];
}

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

void map::CreateMapFile() {
    std::ofstream file("C:\\Users\\Luker\\CLionProjects\\OK_Projekt V3\\map.txt");
    file<<this->size<<std::endl;
    for(int i=0;i<this->size;i++){
        file<<i+1<<" ";
        file<<this->coords[i][0]<<" ";
        file<<this->coords[i][1]<<std::endl;
    }
}