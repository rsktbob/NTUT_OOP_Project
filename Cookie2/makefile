.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_cookie.h src/cookie.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

valgrind:
	valgrind --error-exitcode=2 --track-origins=yes --leak-check=full ./bin/ut_all

stat:
	wc src/* test/*
