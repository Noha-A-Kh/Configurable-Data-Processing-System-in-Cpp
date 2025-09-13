#include <string>
#include <map>

class Configuration
{
public:
    Configuration(const std::string &path);

    /*returns a specific option*/
    std::string getOption(const std::string &key);
    /*print all Processor.Options.* for a given processor*/
    void printOptions(const std::string &processorName);

private:
    // a map to hold all options in key:value manner
    std::map<std::string, std::string> options_;
    // parses the files and fills the options_ map
    void parseFile(const std::string &path);
};