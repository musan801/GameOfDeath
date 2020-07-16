#include  <iostream>
#include "Habitat.h"
#include "WorkingHuman.h"

using namespace std;
int  main() {
	Habitat MyHabitat;
	int HabitatSize;
	int HumanPopulation;
	int WorkingPeopleSize;
	int GenSize;
	int Ticks;

	cout << "Please enter Size of Habitat:"<<endl;
	cin >> HabitatSize;
	cout << "Please enter Size of Population:" << endl;
	cin >> HumanPopulation;
	cout << "Please enter number of Working People:" << endl;
	cin >> WorkingPeopleSize;

	MyHabitat.Initialize(HabitatSize,HumanPopulation, WorkingPeopleSize); 

	cout <<"Enter number  of Gens: " <<endl;
	cin >> GenSize;

	cout << "Enter number  of ticks of Recovery:" << endl;
	cin >> Ticks;
    MyHabitat.Generations(GenSize,Ticks);
	/*for (int i = 0; i < 10; i++)
		cout<<MyHabitat.getHumans().at(i)->getHasVirus()<<" ";
	return 0;
    */
} 

