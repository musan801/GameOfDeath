#include  <iostream>
#include "Habitat.h"

using namespace std;
int  main() {
	cout << "FIRST COMMIT" << endl;
	Habitat MyHabitat;
	MyHabitat.Initialize(10, 10, 10);
	MyHabitat.DisplayHabitat();

	return 0;
}