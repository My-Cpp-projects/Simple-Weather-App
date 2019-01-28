



#ifndef NETWORK_PROCESSOR_H
#define NETWORK_PROCESSOR_H

#include <string>

class NetworkProcessor
{
public:
	NetworkProcessor();
	virtual ~NetworkProcessor();

public:
	void GetResponse(const std::string& url, std::string& json);
};

#endif // !NETWORK_PROCESSOR_H

