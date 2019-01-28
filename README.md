# Simple Weather App
A simple weather application which allows to add and store locations and show weather information of those locations.

I used CURL (https://curl.haxx.se/download.html) and CURLCPP (https://github.com/JosephP91/curlcpp) for networking purposes.

I used the API provided by https://openweathermap.org/

To get the application working one has to sign up in https://openweathermap.org/ and get a free API Key.

Then you have to copy the key and paste it in appid variable in main.cpp.
There is already a file named Locations.txt where some sample locations already exist.
You can call application.ClearExistingLocationFile() from main.cpp function to make the list empty or you can manually delete the file.
To add locations use application.AddWeatherLocation("YOUR LOCATION HERE") from main.cpp to add your location to the list.
Use application.DisplayWeatherOfLocations() to display weather information of all locations in the list. 

