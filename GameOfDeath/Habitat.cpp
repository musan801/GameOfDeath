#include "Habitat.h"
#include <iostream>
#include "WorkingHuman.h"
#include "NonWorkingHuman.h"
#include <cstdlib>
#include <ctime>
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
    for (int i = 0; i < n_temp; ++i)
    {
        Grid2D[i] = new char[n_temp];
        for (int j = 0; j < n_temp; j++)
        {
            Grid2D[i][j] = '-';
        }

    }
    // This loop Spawns Humans and Offices and also maps them on the Grid
    srand((unsigned)time(NULL));
    while (h_temp != 0) {
      //  DisplayHabitat();
        cout << endl;
            if (o_temp != 0) 
            {
                WorkingHuman* obj = new WorkingHuman();
                Humans.push_back(obj);
               // Offices
                o_temp--;
                h_temp--;
                FindUninitialized:
                int temp_i =  (rand() % (n_temp ));
                int temp_j =  (rand() % (n_temp ));
                if (Grid2D[temp_i][temp_j] == '-')
                {
                    obj->setInitialPos(Point(temp_i, temp_j));
                    Grid2D[temp_i][temp_j] = 'W';
                }
                else
                    goto FindUninitialized;
            }
            else 
            {
                NonWorkingHuman* obj = new NonWorkingHuman();
                Humans.push_back(obj);
                h_temp--;
                FindUninitialized1:
                int temp_i =  (rand() % (n_temp ));
                int temp_j =  (rand() % (n_temp ));
                //cout << temp_i << "." << temp_j << endl;
                if (Grid2D[temp_i][temp_j] == '-')
                {
                    obj->setInitialPos(Point(temp_i, temp_j));
                    Grid2D[temp_i][temp_j] = 'H';
                }
                else 
                    goto  FindUninitialized1;
            }
        }
    /*for (int i = 0; i < Humans.size(); i++) {
         cout<<Humans.at(i)->getCurrentPos().getX()<< ' ';
         cout << Humans.at(i)->getCurrentPos().getX() << ' ';
         cout << endl;
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
