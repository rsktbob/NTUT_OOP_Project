.PHONY: directories bin/ut_all clean gcovr

all: directories bin/ut_all

gcovr: directories bin/ut_all_gcovr

directories: 
	mkdir -p bin

bin/ut_all: src/algorithm.h src/alcohol.h src/order.h src/sour.h src/tequila.h test/ut_alcohol.h test/ut_main.cpp
		g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

bin/ut_all_gcovr: src/algorithm.h src/alcohol.h src/order.h src/sour.h src/tequila.h test/ut_alcohol.h test/ut_main.cpp
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css


