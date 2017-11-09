//
// Created by Luker on 12.10.2017.
//

#ifndef OK_PROJEKT_MAP_H
#define OK_PROJEKT_MAP_H
#include <iostream>
#include <fstream>
class map {
private:
    int size;
    int coords[2000][2];

public:
    void load();
    int getSize();
    double getDistance(int x, int y);
    int getX(int x);
    int getY(int x);
    void create(int size,int MaxNumber);
    void createMeme(int size);
    void CreateMapFile();
};


#endif //OK_PROJEKT_MAP_H
