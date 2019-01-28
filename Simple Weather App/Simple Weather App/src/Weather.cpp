



#include <sstream>
#include <iostream>

#include "../include/Weather.h"
#include "../include/WeatherDTO.h"

const std::map<std::string, Weather::WeatherFuncPtr> Weather::STRING_FUNCTION_MAP =
{
	{	"lon",			&Weather::StoreLongitude		},
	{	"lat",			&Weather::StoreLatitude			},
	{	"temp",			&Weather::StoreTemperature		},
	{	"tempmax",		&Weather::StoreMaxTemperature	},
	{	"tempmin",		&Weather::StoreMinTemperature	},
	{	"description",	&Weather::StoreDescription		},
	{	"name",			&Weather::StoreName				},
	{	"country",		&Weather::StoreCountry			}
};

const std::vector<char> Weather::VALID_CHARS =
{
	' ',
	'.',
	'-',
	'\''
};

Weather::Weather(const std::string& json)
	: mData(new WeatherDTO)
	, mMessage("")
	, mIsWeatherExists(false)
{
	Init(json);
}

Weather::Weather(const Weather &weather)
{
	mIsWeatherExists = weather.mIsWeatherExists;
	mMessage = weather.mMessage;
	mData = new WeatherDTO();
	*mData = *weather.mData;
}

Weather::~Weather()
{
	if (mData)
	{
		delete mData;
	}
}

WeatherDTO Weather::GetData() const
{
	return *mData;
}

void Weather::DisplayWeather() const
{
	if (mIsWeatherExists)
	{
		DisplayData();
	}
	else
	{
		DisplayMessage();
	}
}

void Weather::Init(const std::string& json)
{
	std::vector<std::string> tmp = SeperateWordsInStringData(json);
	if (IsValidData(tmp))
	{
		mIsWeatherExists = true;
		StoreData(tmp);
	}
	else
	{
		mIsWeatherExists = false;
		SetMessage(tmp);
	}
}

std::vector<std::string> Weather::SeperateWordsInStringData(const std::string& json)
{
	char delim = '"';
	std::vector<std::string> words;
	std::string tmp;
	std::stringstream tmpStream(json);
	while (std::getline(tmpStream, tmp, delim))
	{
		std::string tmp2;

		for (const auto& c : tmp)
		{
			if (isalpha(c) || isdigit(c)
				|| std::find(VALID_CHARS.begin(), VALID_CHARS.end(), c) != VALID_CHARS.end())
			{
				tmp2 += c;
			}
		}
		if (!tmp2.empty())
		{
			words.push_back(tmp2);
		}
	}

	return words;
}

bool Weather::IsValidData(const std::vector<std::string>& data) const
{
	if ("cod" == data[0] || data.size() < 1 || std::find(data.begin(), data.end(), "ERROR") != data.end())
	{
		return false;
	}
	return true;
}

void Weather::DisplayData() const
{
	std::cout << "Country: "			<< mData->mCountry << std::endl;
	std::cout << "Name: "				<< mData->mName	<< std::endl;
	std::cout << "Longitude: "			<< mData->mLongitude << std::endl;
	std::cout << "Latitude: "			<< mData->mLatitdue << std::endl;
	std::cout << "Temperature: "		<< mData->mTemperature << std::endl;
	std::cout << "Max Temperature: "	<< mData->mMaxTemp << std::endl;
	std::cout << "Min Temperature: "	<< mData->mMinTemp << std::endl;
	std::cout << "Description: "		<< mData->mDescription << std::endl;
}

void Weather::DisplayMessage() const
{
	std::cout << mMessage << std::endl;
}

void Weather::SetMessage(const std::vector<std::string>& data)
{
	auto it = std::find(data.begin(), data.end(), "message");
	if (it != data.end())
	{
		int index = std::distance(data.begin(), it);
		++index;
		mMessage = data[index];
	}
}

void Weather::StoreData(const std::vector<std::string>& words)
{
	for (const auto& s : STRING_FUNCTION_MAP)
	{
		auto it = std::find(words.begin(), words.end(), s.first);
		if (it != words.end())
		{
			WeatherFuncPtr handler = STRING_FUNCTION_MAP.at(s.first);
			int index = std::distance(words.begin(), it);
			++index;
			(this->*handler)(words[index]);
		}
	}
}

void Weather::StoreLongitude(std::string value)
{
	mData->mLongitude = std::stod(value);
}

void Weather::StoreLatitude(std::string value)
{
	mData->mLatitdue = std::stod(value);
}

void Weather::StoreTemperature(std::string value)
{
	mData->mTemperature = std::stod(value);
}

void Weather::StoreMaxTemperature(std::string value)
{
	mData->mMaxTemp = std::stod(value);
}

void Weather::StoreMinTemperature(std::string value)
{
	mData->mMinTemp = std::stod(value);
}

void Weather::StoreDescription(std::string value)
{
	mData->mDescription = value;
}

void Weather::StoreName(std::string value)
{
	mData->mName = value;
}

void Weather::StoreCountry(std::string value)
{
	mData->mCountry = value;
}