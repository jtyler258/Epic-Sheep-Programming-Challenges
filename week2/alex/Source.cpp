#include <iostream>
#include <fstream>

using namespace std;

void lockDoors(bool *doors, int numDoors);

int main(int argc, char *argv[]) {
	ifstream stream("file.txt");

	int numDoors, numIterations;
	while (stream >> numDoors && stream >> numIterations)
	{
		// Create door array. False is unlocked, true is locked
		bool *doors = new bool[numDoors]();

		// Do lockDoors numIterations - 1 times
		for (int i = 0; i < numIterations - 1; ++i)
		{
			lockDoors(doors, numDoors);
		}

		// Last iteration, toggle last door
		if (doors[numDoors - 1] == true)
			doors[numDoors - 1] = false;
		else
			doors[numDoors - 1] = true;

		int numUnlockedDoors = 0;

		// Count the number of unlocked doors
		for (int i = 0; i < numDoors; ++i)
		{
			if (doors[i] == false)
				++numUnlockedDoors;
		}

		cout << numUnlockedDoors << endl;
	}

	return 0;
} 

void lockDoors(bool *doors, int numDoors)
{
	// Lock every second door
	for (int i = 1; i < numDoors; i += 2)
	{
		doors[i] = true;
	}

	// Toggle every third door
	for (int i = 2; i < numDoors; i += 3)
	{
		if (doors[i] == true) 
			doors[i] = false;
		else
			doors[i] = true;
	}

}


