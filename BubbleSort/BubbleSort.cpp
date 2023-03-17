#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
// Definening the MAX number as 100
#define MAX 100
using namespace std;
using namespace sf;

int main()
{
	int number;
	int array[MAX];

	//Checking if the inptut number is bigger then 100 or smaller then 1
	while (true) {
		cout << "Enter a Number: ";
		cin >> number;
		if (number > MAX || number < 1)
		{
			cout << " ERROR | Enter a number in the range of " << MAX << endl;
			continue;
		}
		break;

	}

	//inputting values in an array
	for (int i = 0; i < number; i++)
	{
		//For every iteration we add a new number to the index
		array[i] = rand() % 100;
	}

	//outputting the unsorted array
	cout << "Unsorted array | ";
	for (int i = 0; i < number; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;


	//sorting an array
	for (int i = 0; i < number; i++)
	{
		for (int j = i + 1; j < number; j++)
		{
			// ascending order
			if (array[i] > array[j])
			{
				//Switching the value of (i) to (j) if the value of (i) is bigger then (j)
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	//display the sorted array
	cout << "  Sorted array | ";
	for (int i = 0; i < number; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
