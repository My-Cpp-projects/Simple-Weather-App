



#ifndef WEATHER_DTO_H
#define WEATHER_DTO_H

#include <string>

struct WeatherDTO
{
	WeatherDTO() 
		: mLongitude	(INT_MAX)
		, mLatitdue		(INT_MAX)
		, mTemperature	(INT_MAX)
		, mMaxTemp		(INT_MAX)
		, mMinTemp		(INT_MAX)
		, mDescription	("")
		, mName			("")
		, mCountry		("")
	{

	}

	double mLongitude;
	double mLatitdue;
	double mTemperature;
	double mMaxTemp;
	double mMinTemp;
	std::string mDescription;
	std::string mName;
	std::string mCountry;
};

#endif // !WEATHER_DTO_H

