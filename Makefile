CC=g++
TARGET=NumericBaseball
CFLAGS=-I inc
LDFLAGS=-lc
SRC=$(wildcard src/*.cc)
OBJ=$(SRC:.cc=.o)

all: $(TARGET)

$(TARGET): main.cc $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(TARGET) $(OBJ)