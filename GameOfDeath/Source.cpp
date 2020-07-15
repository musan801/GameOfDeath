
#include  <iostream>
#include "Habitat.h"

using namespace std;
int  main() {
	Habitat MyHabitat;
	MyHabitat.Initialize(18,18,3);
    MyHabitat.Generations(10);
	/*for (int i = 0; i < 10; i++)
		cout<<MyHabitat.getHumans().at(i)->getHasVirus()<<" ";
	return 0;
    */

} 

