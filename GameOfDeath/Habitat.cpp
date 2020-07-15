#include "Habitat.h"
#include <iostream>
#include "WorkingHuman.h"
#include "NonWorkingHuman.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <thread>
#include <chrono> 
#include<vector>

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
    Grid2D = new char* [N_size];
    Offices = new Office[O_num];
    for (int i = 0; i < N_size; ++i)
    {
        Grid2D[i] = new char[N_size];
        for (int j = 0; j < N_size; j++)
        {
            Grid2D[i][j] = '-';
        }
    }

    // This loop Spawns Humans and Offices and also maps them on the Grid
    srand((unsigned)time(NULL));
    while (h_temp != 0) {
      //  DisplayHabitat();
      //  cout << endl;
            if (o_temp != 0) 
            {
               // Offices
                o_temp--;
                h_temp--;
                FindUninitialized:
                int temp_i =  (rand() % (n_temp ));
                int temp_j =  (rand() % (n_temp ));
                if (Grid2D[temp_i][temp_j] == '-')
                {
                    int off_i = (rand() % (n_temp));
                    int off_j = (rand() % (n_temp));
                    if (Grid2D[off_i][off_j] == '-')
                    {
                        //cout << temp_i << "testing";
                        Grid2D[temp_i][temp_j] = 'W';
                        Grid2D[off_i][off_j] = 'O';
                        Offices[o_temp].setPos(Point(off_i, off_j));
                        Humans.push_back(new WorkingHuman(&Offices[o_temp], Point(temp_i, temp_j)));
                    }
                    
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
                
                if (Grid2D[temp_i][temp_j] == '-')
                {
                    Humans.front()->setInitialPos(temp_i, temp_j);
                    Humans.front()->setCurrentPos(Point(temp_i, temp_j));

                    Grid2D[temp_i][temp_j] = 'H';
                }
                else 
                    goto  FindUninitialized1;
            }
        }
   /* for (int i = 0; i < Humans.size(); i++) {
         cout<<Humans.at(i)->getInitialPos().getX()<< ' ';
         cout << Humans.at(i)->getInitialPos().getX() << ' ';
    }
    for (int i = 0; i < O_num; i++)
    {
         Point temp= Offices[i].getPos();
         cout << endl<<temp.getX() << " "<<temp.getY()<<"Point"<<endl;

    }*/
    
}

void Habitat::retainOfficeHouse() {
    
    for (int i = 0; i < O_num; i++)
    {
        Grid2D[Offices[i].getPos().getX()][Offices[i].getPos().getY()] = 'o';
        Grid2D[Humans.at(i)->getInitialPos().getX()][Humans.at(i)->getInitialPos().getY()] = 'w';
        if (Humans[i]->getCurrentPos()==Offices[i].getPos()) 
        {
            Grid2D[Offices[i].getPos().getX()][Offices[i].getPos().getY()] = 'O';
        }
        if (Humans[i]->getCurrentPos() == Humans[i]->getInitialPos())
        {
            Grid2D[Humans.at(i)->getInitialPos().getX()][Humans.at(i)->getInitialPos().getY()] = 'W';
        }
    }
}

void Habitat::Generations(int a)
{
    for (int j = 0; j < a; j++)
    {
        for (int i = 0; i < O_num; i++)
        {


            {


                Point Position = Humans.at(i)->GoToPos();

                //Grid2D[Humans.at(i)->getCurrentPos().getX()][Humans.at(i)->getCurrentPos().getY()] = '-'; //To make prev step look empty
               // cout << Humans.at(i)->getCurrentPos().getX() << " " << Humans.at(i)->getCurrentPos().getY() << "current pos" << endl;
                //cout << Position.getX() << " " << Position.getY() << "dest pos" << endl;
                //cout << BFS(Humans.at(i)->getCurrentPos(), Position).getX() << " bfs " << BFS(Humans.at(i)->getCurrentPos(), Position).getY() << endl;

                Point pos = OneStep(Humans.at(i)->getCurrentPos(), Position);
                //cout << pos.getX()<<" " << pos.getY() << endl;
                Grid2D[Humans.at(i)->getCurrentPos().getX()][Humans.at(i)->getCurrentPos().getY()] = '-'; //To show movement of Human
                Humans.at(i)->setCurrentPos(Point(pos.getX(), pos.getY()));
                Grid2D[Humans.at(i)->getCurrentPos().getX()][Humans.at(i)->getCurrentPos().getY()] = '+'; //To show movement of Human
                retainOfficeHouse();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            system("cls");
            DisplayHabitat();



        }
        // cout << endl;
        // DisplayHabitat();
        // cout << endl;
    }
}


Point Habitat::OneStep(Point src,Point dest )
{
  int  source_i=src.getX();
    int source_j=src.getY();
   int dest_i=dest.getX();
    int  dest_j=dest.getY();
   
    if (source_i < dest_i) /////// DOWN
    {
        if (Grid2D[source_i+1][source_j] != '-') { // down Obstacle
            //
            if (source_j < dest_j)  //////////down right RIGHT
            {
                if (Grid2D[source_i][source_j + 1] != '-') { // down right Obstacle
                    return Point(source_i, source_j - 1);
                }
                if (Grid2D[source_i][source_j + 1] == '-' or dest == Point(source_i, source_j + 1)) {
                    return Point(source_i, source_j + 1);
                }
            }
        }
        if (Grid2D[source_i + 1][source_j] == '-' or dest == Point(source_i+1,source_j) ) {
            return Point(source_i + 1, source_j);
        }
    }
    if (source_j < dest_j)  //////////MOVE RIGHT
    {
        if (Grid2D[source_i][source_j + 1] != '-') { // RIGHT Obstacle
            if (source_i > dest_i)  //////////MOVE RIGHT UP
            {
                if (Grid2D[source_i - 1][source_j] != '-') { //RIGHT UP Obstacle
                    return Point(source_i + 1, source_j);
                }
                if (Grid2D[source_i - 1][source_j] == '-' or dest == Point(source_i - 1, source_j)) {
                    return Point(source_i - 1, source_j);
                }
            }
        }
        if (Grid2D[source_i][source_j + 1] == '-' or dest == Point(source_i , source_j+1)) {
            return Point(source_i, source_j + 1);
        }
    }
    if (source_j > dest_j)  //////////LEFT
    {
        if (Grid2D[source_i][source_j - 1] != '-') { //Obstacle
            if (source_i > dest_i)  //////////MOVE LEFT UP
            {
                if (Grid2D[source_i - 1][source_j] != '-') { //LEFT UP Obstacle
                    return Point(source_i + 1, source_j);
                }
                if (Grid2D[source_i - 1][source_j] == '-' or dest == Point(source_i - 1, source_j)) {
                    return Point(source_i - 1, source_j);
                }
            }
        }
        if (Grid2D[source_i][source_j - 1] == '-' or dest == Point(source_i, source_j-1)) {
            return Point(source_i, source_j - 1);
        }
    }
    if (source_i > dest_i)  //////////UP
    {
        if (Grid2D[source_i-1][source_j ] != '-') { //up Obstacle
            if (source_j < dest_j)  //////////MOvE DOWN RIGHT
            {
                if (Grid2D[source_i][source_j + 1] != '-') { // down right Obstacle
                    return Point(source_i, source_j - 1);
                }
                if (Grid2D[source_i][source_j + 1] == '-' or dest == Point(source_i, source_j + 1)) {
                    return Point(source_i, source_j + 1);
                }
            }
        }
        if (Grid2D[source_i-1][source_j ] == '-' or dest == Point(source_i - 1, source_j)) {
            return Point(source_i-1, source_j );
        }
    }
    //cout << "needs more conditions" << endl;
    //Might allow diagonals later 
    return src;
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

bool Habitat::IsEffected(float immunity)
{
    immunity *= 100;
    return ((rand() % (100))<immunity);
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

/*bool Habitat::InContact(Point obj){      // Functions check if Human contacted a virus and also if he/she got effected
    if (Grid2D[obj.getX()][obj.getY()])
    {

    }

}*/