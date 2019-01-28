



#include <sstream>
#include <iostream>
#include <fstream>

#include "../include/Application.h"
#include "../include/Open_Weather_Map_URL_Assembler.h"
#include "../include/Network_Processor.h"
#include "../include/Weather.h"

const std::string Application::FILE_NAME = "Locations.txt";

Application::Application(const std::string& appID)
	: mAssembler(OpenWeahterMapURLAssembler::GetInstance())
	, mProcessor(new NetworkProcessor)
	, mAppID(appID)
{
	Init();
}

Application::~Application()
{
	delete mProcessor;
}

void Application::AddWeatherLocation(const std::string& locationName)
{
	WriteLocationIntoTheFile(locationName);
	AddLocationToBuffer(locationName);
}

void Application::DisplayWeatherOfLocations() const
{
	for (const auto& weather : mWeatherLocations)
	{
		std::cout << "/////////////////////////////////////////" << std::endl;
		weather.DisplayWeather();
		std::cout << "/////////////////////////////////////////" << std::endl;
	}
}

void  Application::ClearExistingLocationFile() const
{
	std::ofstream ofs;
	ofs.open(FILE_NAME, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

void Application::Init()
{
	FillWeatherLocations();
}

void Application::WriteLocationIntoTheFile(const std::string& locationName)
{
	std::ofstream file;
	file.open(FILE_NAME, std::ios_base::app);
	file << locationName << "\n";
}

void Application::FillWeatherLocations()
{
	std::ifstream infile(FILE_NAME);
	std::string location;
	while (std::getline(infile, location))
	{
		AddLocationToBuffer(location);
	}
}

void Application::AddLocationToBuffer(const std::string& locationName)
{
	std::string json;
	mProcessor->GetResponse(mAssembler->GetUrl(locationName, mAppID), json);
	Weather tmp(json);
	mWeatherLocations.push_back(tmp);
}
