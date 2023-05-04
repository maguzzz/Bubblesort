#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

// Definening the MAX number as 100
#define MAX  200

using namespace std;

int main()
{
	//How many pillars do you want
	int array[MAX];

	int number = 200;
	bool isSwitched = false;

	int screenHeight = 340;
	int screenWidth = 800;

	int barCheckCount = 0;

	int barhWidth = screenWidth / number;



	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "BubbleSort", sf::Style::Close);


	//Adding Font
	sf::Font Manrope;
	Manrope.loadFromFile("Fonts/Manrope-Bold.ttf");

	//Score Text
	sf::Text CheckCount;
	CheckCount.setFont(Manrope);
	CheckCount.setString("Checks: " + to_string(barCheckCount));
	CheckCount.setFillColor(sf::Color::White);
	CheckCount.setPosition(20, 20);
	CheckCount.setScale(.6, .6);
	window.draw(CheckCount);

	//Changing Seed so the random numbers are realy random
	srand(time(NULL));

	//inputting values in an array
	for (int i = 0; i < number; i++)
	{
		//For every iteration we add a new number to the index
		array[i] = rand() % number;
	}

	//Displaying Array befor its sorted
	for (int k = 0; k < number; k++)
	{
		sf::RectangleShape bar(sf::Vector2f(barhWidth, array[k]));
		bar.setPosition(k * barhWidth, screenHeight - array[k]);
		window.draw(bar);
	}
	window.display();

	//Sleepign the programm so you can see the unsorted array
	Sleep(5000);

	for (int i = 0; i < number; i++)
	{
		for (int j = i + 1; j < number; j++)
		{
			// Ascending order
			if (array[i] > array[j])
			{
				// Switching the value of (i) to (j) if the value of (i) is bigger than (j)
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				isSwitched = true;
				barCheckCount += 1;

				// Redrawing the bars after swapping two values in the array
				window.clear();

				for (int k = 0; k < number; k++)
				{
					sf::RectangleShape bar(sf::Vector2f(barhWidth, array[k]));
					bar.setPosition(k * barhWidth, screenHeight - array[k]);
					
					//Marking the curren switch Red
					if (k == j || k == i){
						bar.setFillColor(sf::Color::Red);
					}
					else {
						bar.setFillColor(sf::Color::White);
					}

					//Displaying Bar
					window.draw(bar);

					//Counting How many Checks where made
					CheckCount.setString("Checks: " + to_string(barCheckCount));
					window.draw(CheckCount);
				}
				window.display();
				Sleep(25);
			}	
		}
	}


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window.close();
		}
	}
	return 0;
}
