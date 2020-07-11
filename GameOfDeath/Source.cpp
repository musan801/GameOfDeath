#include  <iostream>
#include "Habitat.h"

using namespace std;
int  main() {
	cout << "Second Commit" << endl;
	Habitat MyHabitat;
	MyHabitat.Initialize(10,11,5);
	MyHabitat.DisplayHabitat();
	return 0;
}