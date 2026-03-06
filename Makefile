CXX=g++
TARGET=NumericBaseball
CXXFLAGS=-I inc
LDFLAGS=-lc
SRC=$(wildcard src/*.cc)
OBJ=$(SRC:.cc=.o)

all: $(TARGET)

$(TARGET): main.cc $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(TARGET) $(OBJ)