



#ifndef I_URL_ASSEMBLER_H
#define I_URL_ASSEMBLER_H

#include <string>

class IURLAssembler
{
public:
	virtual ~IURLAssembler() {};
	virtual std::string GetUrl(const std::string& location, const std::string& appID) = 0;
};

#endif // !I_URL_ASSEMBLER_H

