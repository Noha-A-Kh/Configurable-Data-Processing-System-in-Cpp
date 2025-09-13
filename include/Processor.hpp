#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <vector>
#include <string>

class Processor {
public:
    virtual ~Processor() {}
    virtual void process(const std::vector<std::string>& data) = 0;
};

#endif