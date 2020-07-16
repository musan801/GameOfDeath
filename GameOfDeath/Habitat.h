#pragma once
#include "Human.h"
#include <stack>
#include <vector>
#include "Office.h"
struct Direction {
    int X;
    int Y;
    int Dist;
    Direction(int x, int y, int w)
        : X(x), Y(y), Dist(w)
    {
    }
    bool operator==(Direction& x) {
        return Dist == x.Dist;
        X = x.X;
        Y = x.Y;
    }
};
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

    bool IsEffected(float immunity);

    Office* getOffices() const;
    void setOffices(Office* Offices);


    void Initialize(int n_temp, int h_temp, int o_temp);
   // void Generations();
    //Point OneStep(int i, int j, int di, int dj);
    Point OneStep(Point src, Point dest);
   //Point OneStep(Point src, Point dest, bool& alt, bool& changealt);
   
    //Point BFS(Point src, Point dest);
    void DisplayHabitat();
    void retainOfficeHouse();

    void Generations(int a,int t);

public:
    vector<Human*> getHumans() const;
    void setHumans(vector<Human*> Humans);

    bool InContact(Human obj);

    //bool InContact(Point obj);

 
    

};
// CPP program to solve Rat in a maze 
// problem with backtracking using stack 

