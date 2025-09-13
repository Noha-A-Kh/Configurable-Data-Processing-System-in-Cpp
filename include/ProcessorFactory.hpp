#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP

#include "Processor.hpp"
#include <string>

class ProcessorFactory
{
public:
    /*Description: this function creates a processor by name and throws std::runtime_error if unknown.*/
    static Processor *createProcessor(const std::string &type);
};

#endif // PROCESSORFACTORY_HPP