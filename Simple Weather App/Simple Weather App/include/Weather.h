



#ifndef WEATHER_H
#define WEATHER_H

#include <vector>
#include <string>
#include <map>

struct WeatherDTO;

class Weather
{
public:
	Weather(const std::string& data);
	Weather(const Weather &p2);
	virtual ~Weather();

public:
	WeatherDTO GetData() const;
	void DisplayWeather() const;

private:
	typedef void (Weather::*WeatherFuncPtr)(std::string);

private:
	void Init(const std::string& data);
	std::vector<std::string> SeperateWordsInStringData(const std::string& data);
	bool IsValidData(const std::vector<std::string>& data) const;

	void DisplayData() const;
	void DisplayMessage() const;
	void SetMessage(const std::vector<std::string>& data);

	void StoreData(const std::vector<std::string>& words);

	void StoreLongitude(std::string value);
	void StoreLatitude(std::string value);
	void StoreTemperature(std::string value);
	void StoreMaxTemperature(std::string value);
	void StoreMinTemperature(std::string value);
	void StoreDescription(std::string value);
	void StoreName(std::string value);
	void StoreCountry(std::string value);

private:
	WeatherDTO* mData;
	std::string mMessage;
	bool mIsWeatherExists;

	static const std::map<std::string, WeatherFuncPtr> STRING_FUNCTION_MAP;
	static const std::vector<char> VALID_CHARS;
};

#endif // !WEATHER_H

