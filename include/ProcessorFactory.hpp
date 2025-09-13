#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP

#include "Processor.hpp"
#include <string>

class ProcessorFactory {
public:
 static Processor* createProcessor(const std::string& type);
};

#endif // PROCESSORFACTORY_HPP