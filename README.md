# GameOfDeath
## Number of Classes:
- Habitat
- Human
	1. WorkingHuman
	2. NonWorkingHuman
- Office
- Point

## Habitat.h
This is the class, which describes the environment of the game.


It has the following variables.
- `int N_size` Size of habitat is n x n, range 0 < n <= 1000000.
- `int H_num` Number  of humans, range 1 < h <= 1000000.
- `int O_num` Number of offices.
- `char** Grid2D` The Main Grid environment. 
- `vector<Human*>Humans`  A vector of humans.
- `Office* Offices`  A list of offices.


Furthermore all the variables have getters and setters.


Some additional functions of this Class are:
- `void Initialize(int n_temp, int h_temp, int o_temp)`  Generates an environment.
- `bool IsEffected(float immunity)` Generates possibility of catching the virus.
- `Point OneStep(Point src, Point dest)`  Tells the human about the  next step towards the destination
- `void DisplayHabitat()`  Displays Habitat
- `void retainOfficeHouse()`   To Help The grid avoid showing trails and also shows where the human is.
- `void Generations(int a,int t)`   Runs a generation with t number of ticks.


-Humans are shown by `+` 
-Offices are shown by `o`
-Working Humans Houses are shown by 'W'
-Non working humans Houses are shown by 'H'
## Human.h
The variables in this class are: 


- `string Name`  the Name.
- `float ImmunityLevel`  How immune a person is to the virus.
- `Point CurrentPos` curent position.
- `Point InitialPos` Initial position.
- `bool HasVirus` if the person has the virus or not.
- `bool isHome` if the person is home or not.
- `int RecoveryTime` time needed to recover.

and along with the getters and setters it has a function `GoToPos()` which is virtual and its sole purpose is to be used in its moveable child classes.

Another thing to mention is that its constructor specifies the immunity level if the Human and also if that person has the virus or not.
For simplicity immunity level is random ranging from 0 to 1 and 30% of the population has the virus at the initialization state.

## WorkingHuman.h
This function is inherited from the Human class.

It has all the humans who travel to offices.


Addition variable is:
- `Office* MyOffice`This stores the office of the particular human.

it has the funtion `GoToPos()` overloaded. 
## NonWorkingHuman.h
it is am empty class for now but can be used in the future for some additional features.


## Office.h
This is a simple class with 2 variables.
- `Name` Name of the office.
- `Pos` Position of the office.

## Point.h
This is the point class  with two variables
- `X` position on X axis.
- `Y` position on Y axis.

and there Getters and setters.



# Source.cpp
## Driver file
This is the  driver  file. It takes all the paremeters as inputs and runs the program.

Inputs:

- `int HabitatSize`
- `int HumanPopulation`
- `int WorkingPeopleSize`
- `int GenSize`
- `int Ticks`

# Project Issues and Overview.
This project has one issue right now and that is the `OneStep()` function of the class Habitat.h. I tried to implement BFS into the project but it increased the 
time complexity of the project. Right now it simply travels step by step towards the position but it sometimes fails due to obstacles such as other buildings.
It is not the ideal approach to apply BFS too as humans can remember a path they have travelled.
#Time Complexity
It takes very little time to execute as I have tried my best to use loops as less as possible.
O(n^2) is the current complexity where n is the size of the Grid.

Future Possible Additions:
Here are some of the additions we can make in the future to this project:
- Destructors (when we decide to kill people and destroy buildings)
- A purpose for the non Working human.
- Quarentine when has virus.
- Offices with multiple employees.
