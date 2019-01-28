



#ifndef OPEN_WEATHER_MAP_URL_ASSEMBLER
#define OPEN_WEATHER_MAP_URL_ASSEMBLER

#include "I_URL_Assembler.h"

class OpenWeahterMapURLAssembler : public IURLAssembler
{
public:
	virtual std::string GetUrl(const std::string& location, const std::string& appID);
	static OpenWeahterMapURLAssembler* GetInstance();

private:
	OpenWeahterMapURLAssembler() {}
	OpenWeahterMapURLAssembler(const OpenWeahterMapURLAssembler&) = delete;
	OpenWeahterMapURLAssembler(OpenWeahterMapURLAssembler&&) = delete;

private:
	static const std::string websiteURL;
	static OpenWeahterMapURLAssembler* mInstance;
};

#endif // !OPEN_WEATHER_MAP_URL_ASSEMBLER

