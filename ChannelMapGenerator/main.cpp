#include "json.hpp"
#include "iostream"
#include "fstream"
#include "vector"
#include "sstream"
#include "iomanip"

// #include "string"
// #include "string_view"
// #include "format"


// for convenience
using json = nlohmann::json;

using namespace std;
int main()
{
    json ChannelMap;
    json ChannelInfoArray;
    json ChannelInfo;

    fstream inFile;
    inFile.open("/home/doc/afiadc/ChannelMap/ChannelMap.txt");
    std::ofstream o("/home/doc/afiadc/ChannelMap/pretty.json");

    string line;
    while(getline(inFile, line))
    {
        int counter = 0;
        std::istringstream iss(line);
        int number = 0;
        int connector = 0;
        //cout << line << endl;
        while(iss >> number)
        {

            counter++;
            if (counter == 1) {connector = number; continue;}

            ChannelInfo["channel"] = number;
            ChannelInfo["connector"] = connector;
            ChannelInfo["x3"] = counter-1;
            ChannelInfo["x2"] = (connector-1)/3+1;
            ChannelInfo["x1"] = (connector-1)%3+1;

            ChannelInfoArray[std::to_string(number)] = ChannelInfo;

        }
        //cout << << std::setw(4) << ChannelMap << std::endl;
    }
    ChannelMap["channels"] = ChannelInfoArray;
    o << std::setw(4) << ChannelMap << std::endl;


    return 0;
}
