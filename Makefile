CXX = clang++-18
CXXFLAGS = -std=c++14 -Wall -Wextra -g

SRC = SquareMat.cpp
MAIN = main.cpp
TEST = Test.cpp


Main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o Main $(SRC) $(MAIN)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test $(SRC) $(TEST)
	./test

valgrind: Main test
	valgrind --leak-check=full --track-origins=yes ./Main
	valgrind --leak-check=full --track-origins=yes ./test

clean:
	rm -f Main test *.o
