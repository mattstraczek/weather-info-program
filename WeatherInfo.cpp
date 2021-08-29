//Matt Straczek
//CSC 240-300

#include "WeatherInfo.h"
#include <iomanip>
#include <sstream>


WeatherInfo::WeatherInfo()
{
	weekDay = " ";
	highTemp = 0;
	lowTemp = 0;
	rainFall = 0.0;
}

WeatherInfo::WeatherInfo(string day, int hi, int lo, double rain)
{
	weekDay = day;
	highTemp = hi;
	lowTemp = lo;
	rainFall = rain;
}

string WeatherInfo::getWeekDay()
{
	return weekDay;
}

int WeatherInfo::getHighTemp()
{
	return highTemp;
}

int WeatherInfo::getLowTemp()
{
	return lowTemp;
}

double WeatherInfo::getRainFall()
{
	return rainFall;
}

void WeatherInfo::setWeekDay(string day)
{
	weekDay = day;
}

void WeatherInfo::setHighTemp(int degrees)
{
	highTemp = degrees;
}

void WeatherInfo::setLowTemp(int degrees)
{
	lowTemp = degrees;
}

void WeatherInfo::setRainFall(double inches)
{
	rainFall = inches;
}

string WeatherInfo::toString()
{
	ostringstream strOut;

	strOut.precision(1);
	strOut.setf(ios::fixed | ios::showpoint);

	strOut << setw(9) << weekDay << setw(9) << highTemp << setw(9) << lowTemp << setw(9) << rainFall << ends;

	return strOut.str();
}
