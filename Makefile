CXX=gcc

CFLAGS = -c -Wall -Werror -std=c99

FLAGS = -Wall -Werror -std=c99

OBJECTS = build/src/main.o build/src/read_tariff.o build/src/print.o build/src/find.o

OBJECTS_TESTS = build/test/main.o build/test/tests.o build/src/find.o

.PHONY: clean all bin build default

all: default test

default: bin build bin/key

test: bin build bin/key_test
	bin/key_test

bin/key_test: $(OBJECTS_TESTS)
	$(CXX) $(FLAGS) $(OBJECTS_TESTS) -o bin/key_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/src/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o

build/src/print.o: src/print.c
	$(CXX) $(CFLAGS) src/print.c -o build/src/print.o

build/src/read_tariff.o: src/read_tariff.c
	$(CXX) $(CFLAGS) src/read_tariff.c -o build/src/read_tariff.o

build/src/find.o: src/find.c
	$(CXX) $(CFLAGS) src/find.c -o build/src/find.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin

clean:
	-rm -rf build bin

run: 
	./bin/key