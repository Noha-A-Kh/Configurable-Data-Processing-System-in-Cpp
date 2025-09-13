#include "Configuration.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

Configuration::Configuration(const std::string &path)
{
    parseFile(path);
}

void Configuration::parseFile(const std::string &filePath)
{
    ifstream configFile(filePath.c_str());

    if (!configFile)
    {
        throw runtime_error("Could not open configuration file: " + filePath);
    }

    string currentLine;
    while (getline(configFile, currentLine))
    {
        // skip empty lines
        if (currentLine.empty() || currentLine[0] == '#')
        {
            continue;
        }

        // find the equal sign
        size_t equalSignPosition = currentLine.find('=');
        if (equalSignPosition == string::npos)
        {
            continue;
        }

        string keyPart = currentLine.substr(0, equalSignPosition);
        string valuePart = currentLine.substr(equalSignPosition + 1);

        options_[keyPart] = valuePart;
    }
}

std::string Configuration::getOption(const std::string &optionName)
{
    if (options_.count(optionName) == 0)
    {
        throw runtime_error("Missing configuration option: " + optionName);
    }

    return options_[optionName];
}

void Configuration::printOptions(const std::string &processorName)
{
    for (const pair<string, string> &entry : options_)
    {
        const string &fullKey = entry.first;
        const string &fullValue = entry.second;

        // check if this key starts with "Processor.Options."
        if (fullKey.find("Processor.Options.") == 0)
        {
            // find the position of the last dot in the key
            size_t lastDotPosition = fullKey.find_last_of('.');
            string fieldName = fullKey.substr(lastDotPosition + 1);

            cout << processorName << " processing data: "
                      << fieldName << " = " << fullValue << endl;
        }
    }
}
