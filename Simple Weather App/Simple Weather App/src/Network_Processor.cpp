



#include "curl_easy.h"
#include "curl_form.h"
#include "curl_ios.h"
#include "curl_exception.h"

#include "../include/Network_Processor.h"

NetworkProcessor::NetworkProcessor()
{

}

NetworkProcessor::~NetworkProcessor()
{

}

void NetworkProcessor::GetResponse(const std::string& url, std::string& json)
{
	std::stringstream stream;
	try
	{
		curl::curl_ios<std::stringstream> writer(stream);
		curl::curl_easy easy(writer);

		easy.add<CURLOPT_URL>(url.data());
		easy.add<CURLOPT_FOLLOWLOCATION>(1L);

		easy.perform();
	}
	catch (curl::curl_easy_exception const& error)
	{
		auto errors = error.get_traceback();
		
		for (const auto& err : errors)
		{
			stream << "\"ERROR:\"\"\"message\"" + err.first + "\"";
		}
		error.clear_traceback();
	}

	json = stream.str();
}