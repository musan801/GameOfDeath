#pragma once
#ifndef UNIQUE_HABITAT
#define UNIQUE_HABITAT
#include "Human.h"
#include <vector>
#include "Office.h"


class Habitat {
    int N_size; // size of habitat is n x n, range 0 < n <= 1000000.
    int H_num; // number  of humans, range 1 < h <= 1000000.
    int O_num; // number of offices
    char** Grid2D; //Main Grid environment 
    vector<Human*>Humans; // vector of humans
    Office* Offices; // list of offices
    
    
public:
    Habitat();
    Habitat(int n_temp, int h_temp, int o_temp);


    int getNsize() const;
    void setNsize(int Nsize);

    int getHnum() const;
    void setHnum(int Hnum);

    int getOnum() const;
    void setOnum(int Onum);

    char** getGrid2D() const;
    void setGrid2D(char** Grid2D);

    Office* getOffices() const;
    void setOffices(Office* Offices);


    void Initialize(int n_temp, int h_temp, int o_temp);
    void DisplayHabitat();


public:
    vector<Human*> getHumans() const;
    void setHumans(vector<Human*> Humans);

};

#endif
