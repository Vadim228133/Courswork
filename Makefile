CXX=gcc

CFLAGS = -c -Wall -Werror -std=c99

FLAGS = -Wall -Werror -std=c99

OBJECTS = build/main.o build/read_tariff.o build/print.o build/find.o

.PHONY: clean all bin build default

all: default

default: bin build bin/key

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/main.o

build/print.o: src/print.c
	$(CXX) $(CFLAGS) src/print.c -o build/print.o

build/read_tariff.o: src/read_tariff.c
	$(CXX) $(CFLAGS) src/read_tariff.c -o build/read_tariff.o

build/find.o: src/find.c
	$(CXX) $(CFLAGS) src/find.c -o build/find.o

build:
	mkdir -p build

bin:
	mkdir -p bin

clean:
	-rm -rf build bin

run: 
	./bin/key