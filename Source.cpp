//Matt Straczek
//CSC 240-300

#include "WeatherInfo.h"
#include <iostream>
#include <iomanip>


//function prototypes
int userInput(WeatherInfo array[], int size);
double averageHigh(int counter, WeatherInfo array[]);
double averageLow(int counter, WeatherInfo array[]);
double totalRainFall(int counter, WeatherInfo array[]);
int indexOfHighestTemp(int counter, WeatherInfo array[]);
int indexOfLowestTemp(int counter, WeatherInfo array[]);
void displayWeatherInformation(int counter, WeatherInfo array[]);


int main()
{
	//array declaration
	WeatherInfo week[7];


	//user input function call, return dayCount value to main
	int count = userInput(week, 7);


	//print list of weather information
	displayWeatherInformation(count, week);


	//finds and prints highest/lowest/total values
	cout << endl << "Highest Reading: " << week[indexOfHighestTemp(count, week)].getHighTemp() << " [" << week[indexOfHighestTemp(count, week)].getWeekDay() << "]" << endl;
	cout << endl << "Lowest Reading: " << week[indexOfLowestTemp(count, week)].getLowTemp() << " [" << week[indexOfLowestTemp(count, week)].getWeekDay() << "]" << endl;
	cout << endl << "Total Rainfall: " << totalRainFall(count, week) << '"' << endl;
}


//function definitions
	int userInput(WeatherInfo array[], int size)
	{

		int dayCount = 0;
		char choice = ' ';
		string day;
		int hi, low;
		double inches;

		do
		{
			cout << "Enter day of week (eg. Sunday, Monday, etc...): ";
			cin >> day;
			cout << endl << "Enter high temperature in degrees Fahr: ";
			cin >> hi;
			cout << endl << "Enter low temperature in degrees Fahr: ";
			cin >> low;
			cout << endl << "Enter total rainfall in inches: ";
			cin >> inches;

			array[dayCount].setHighTemp(hi);
			array[dayCount].setWeekDay(day);
			array[dayCount].setLowTemp(low);
			array[dayCount].setRainFall(inches);
			
			dayCount++;
			if (dayCount < size)
			{
				cout << endl << endl << "Another day (y or n): ";
				cin >> choice;
			}
			
			cout << endl << endl;

		} while (choice == 'y' && dayCount < size);

		return dayCount;
	}

	void displayWeatherInformation(int counter, WeatherInfo array[])
	{
		cout << setw(9) << "Week Day" << setw(9) << "Hi" << setw(9) << "Low" << setw(9) << "Rain" << endl;
		cout << setw(9) << "--------" << setw(9) << "----" << setw(9) << "----" << setw(9) << "----" << endl;
		for (int i = 0; i < counter; i++)
		{
			cout << array[i].toString() << endl;
		}
		cout << setw(9) << "--------" << setw(9) << "----" << setw(9) << "----" << setw(9) << "----" << endl;
		cout << setw(9) << "Averages" << setw(9) << showpoint << fixed << setprecision(1) << averageHigh(counter, array) << setw(9) << showpoint << fixed << setprecision(1) << averageLow(counter, array) << setw(9) << showpoint << fixed << setprecision(1) << totalRainFall(counter, array) / counter << endl;
	}


	double averageHigh(int counter, WeatherInfo array[])
	{
		double avgHigh = 0;
		int totalHigh = 0;

		for (int i = 0; i < counter; i++)
		{
			totalHigh += array[i].getHighTemp();
		}

		avgHigh = double(totalHigh) / double(counter);
		return avgHigh;
	}

	double averageLow(int counter, WeatherInfo array[])
	{
		double avgLow = 0;
		int totalLow = 0;

		for (int i = 0; i < counter; i++)
		{
			totalLow += array[i].getLowTemp();
		}

		avgLow = double(totalLow) / double(counter);
		return avgLow;
	}

	double totalRainFall(int counter, WeatherInfo array[])
	{
		double total = 0;
		for (int i = 0; i < counter; i++)
		{
			total += array[i].getRainFall();
		}

		return total;
	}

	int indexOfHighestTemp(int counter, WeatherInfo array[])
	{
		int highestTempIndex = 0;

		for (int i = 0; i < counter - 1; i++)
		{
			if (array[highestTempIndex].getHighTemp() < array[i + 1].getHighTemp())
			{
				highestTempIndex = i + 1;
			}
			
		}
		
		return highestTempIndex;
	}

	int indexOfLowestTemp(int counter, WeatherInfo array[])
	{
		int lowestTempIndex = 0;

		for (int i = 0; i < counter - 1; i++)
		{
			if (array[lowestTempIndex].getLowTemp() > array[i + 1].getLowTemp())
			{
				lowestTempIndex = i + 1;
			}

		}

		return lowestTempIndex;
	}