



#include "../include/Open_Weather_Map_URL_Assembler.h"

const std::string OpenWeahterMapURLAssembler::websiteURL = "https://api.openweathermap.org/data/2.5/weather?q=";
OpenWeahterMapURLAssembler* OpenWeahterMapURLAssembler::mInstance = nullptr;

std::string OpenWeahterMapURLAssembler::GetUrl(const std::string& location, const std::string& appID)
{
	return websiteURL + location + "&units=metric" + "&APPID=" + appID;
}

OpenWeahterMapURLAssembler* OpenWeahterMapURLAssembler::GetInstance()
{
	if (nullptr == mInstance)
	{
		mInstance = new OpenWeahterMapURLAssembler;
	}
	return mInstance;
}