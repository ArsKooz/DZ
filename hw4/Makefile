CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = onegin.exe
SOURCES = main.cpp lib.cpp
HEADERS = lib.h
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
