#include "ProcessorFactory.hpp"
#include "Configuration.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Configuration config("config/settings.txt");
        auto processorType = config.getOption("Processor.Options.Type");
        auto processor = ProcessorFactory::createProcessor(processorType);
        std::vector<std::string> data = {"Sample1", "Sample2", "Sample3"};
        processor->process(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}

// intintiate a processor factory obj and give the config dir to it
// the processor factory  obj should instinitate a configuration obj and pass the dir to it
// the config obj should parse and return the info to the factory
// factory should return an obj of a certain type
// the main should call the process function using the returned pointer