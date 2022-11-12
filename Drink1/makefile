.PHONY: direction bin/ut_all clean

all: directories bin/ut_all

directories: 
	mkdir -p bin

bin/ut_all: src/drink.h test/ut_drink.h test/ut_main.cpp
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -rf bin

valgrind:
	valgrind --error-exitcode=2 --track-origins=yes --leak-check=full ./bin/ut_all