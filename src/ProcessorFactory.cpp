#include "ProcessorFactory.hpp"
#include "Processor.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;



/*the avauilable processor types*/
class TextProcessor : public Processor {
public:
    void process(const std::vector<std::string>& data) override {
        cout << "TextProcessor processing data: ";
        for (const string &word : data) {
            cout << word << " ";
        }
        cout << endl;
    }
};

class NumericProcessor : public Processor {
public:
    void process(const std::vector<std::string>& data) override {
        cout << "NumericProcessor processing data: ";
        for (const string &word : data) {
            cout << word << " ";
        }
        cout << endl;
    }
};

class ImageProcessor : public Processor {
public:
    void process(const std::vector<std::string>& data) override {
        cout << "ImageProcessor processing data: ";
        for (const string &word : data) {
            cout << word << " ";
        }
        cout << endl;
    }
};

class AudioProcessor : public Processor {
public:
    void process(const std::vector<std::string>& data) override {
        cout << "AudioProcessor processing data: ";
        for (const string &word : data) {
            cout << word << " ";
        }
        cout << endl;
    }
};


// Factory method
Processor* ProcessorFactory::createProcessor(const std::string& type) {
    string t = type;
    for (char &c : t)
    c = tolower(c); 

    if (t == "text")    return new TextProcessor();
    if (t == "numeric") return new NumericProcessor();
    if (t == "image")   return new ImageProcessor();
    if (t == "audio")   return new AudioProcessor();

    throw runtime_error(string("Unknown processor type: ") + type);
}