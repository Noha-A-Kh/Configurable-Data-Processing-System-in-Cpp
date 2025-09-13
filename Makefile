CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude


SRC = src/Processor.cpp src/ProcessorFactory.cpp src/Configuration.cpp src/Utilities.cpp src/main.cpp


OBJ = $(SRC:.cpp=.o)


TARGET = ConfigurableProcessor


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)
