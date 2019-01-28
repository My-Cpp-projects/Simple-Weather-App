



#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

class Weather;
class OpenWeahterMapURLAssembler;
class NetworkProcessor;

class Application
{
public:
	Application(const std::string& appID);
	virtual ~Application();

public:
	void AddWeatherLocation(const std::string& locationName);
	void DisplayWeatherOfLocations() const;
	void ClearExistingLocationFile() const;

private:
	void Init();
	void WriteLocationIntoTheFile(const std::string& locationName);
	void FillWeatherLocations();
	void AddLocationToBuffer(const std::string& locationName);

private:
	static const std::string FILE_NAME;
	std::vector<Weather> mWeatherLocations;
	OpenWeahterMapURLAssembler* mAssembler;
	NetworkProcessor* mProcessor;
	std::string mAppID;
};

#endif // !APPLICATION_H

