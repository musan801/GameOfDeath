#include "Habitat.h"
#include <iostream>
#include "WorkingHuman.h"
#include "NonWorkingHuman.h"

using namespace std;


Habitat::Habitat() {
    N_size = 0;
    H_num = 0;
    O_num = 0;
    Grid2D = NULL;
    Offices = NULL;
}

Habitat::Habitat(int n_temp, int h_temp, int o_temp)
{
    Initialize(n_temp, h_temp, o_temp);
}

void Habitat::Initialize(int n_temp, int h_temp, int o_temp)
{
    N_size = n_temp;
    H_num = h_temp;
    O_num = o_temp;
    Grid2D = new char* [n_temp];
    Offices = new Office[O_num];

    while (h_temp != 0) {
        if (o_temp != 0) {
            WorkingHuman* obj = new WorkingHuman();
            Humans.push_back(obj);
            o_temp--;
            h_temp--;
        }
        else {
            NonWorkingHuman* obj = new NonWorkingHuman();
            Humans.push_back(obj);
            h_temp--;
        }
    }
    for (int i = 0; i < n_temp; ++i)
    {
        Grid2D[i] = new char[n_temp];
    }
    /*
    // Initializing with random values
    char[3] = { ' ','H','O'};
    for (int i = 0; i < N_size; i++) {
        for (int j = 0; j < N_size; j++)
        {


        }
    }
    */


}

void Habitat::DisplayHabitat()
{

    for (int i = 0; i < N_size; i++) {
        for (int j = 0; j < N_size; j++)
        {
            cout << Grid2D[i][j] << " ";
        }
        cout << endl;
    }
}


int Habitat::getNsize() const
{
    return N_size;
}

void Habitat::setNsize(int Nsize)
{
    N_size = Nsize;
}

int Habitat::getHnum() const
{
    return H_num;
}

void Habitat::setHnum(int Hnum)
{
    H_num = Hnum;
}

int Habitat::getOnum() const
{
    return O_num;
}

void Habitat::setOnum(int Onum)
{
    O_num = Onum;
}

char** Habitat::getGrid2D() const
{
    return Grid2D;
}

void Habitat::setGrid2D(char** Grid2D)
{
    this->Grid2D = Grid2D;
}


Office* Habitat::getOffices() const
{
    return Offices;
}

void Habitat::setOffices(Office* Offices)
{
    this->Offices = Offices;
}


vector<Human*> Habitat::getHumans() const
{
    return Humans;
}

void Habitat::setHumans(vector<Human*> Humans)
{
    this->Humans = Humans;
}
