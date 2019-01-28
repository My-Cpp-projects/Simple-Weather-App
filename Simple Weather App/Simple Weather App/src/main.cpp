



#include <iostream>

#include "../include/Application.h"

int main()
{
	std::string appid = "..."; // Your own appid
	Application application(appid);
		
	//--- Use this function to add location to the list
	//application.AddWeatherLocation("YOUR LOCATION HERE");

	// --- Use this function to clear the list
	//application.ClearExistingLocationFile();
	
	application.DisplayWeatherOfLocations();
	return 0;
}