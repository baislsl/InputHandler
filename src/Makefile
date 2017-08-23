CXXFLAGS      += -std=gnu++11
all : InputEngine.o KeyCode.o Terminal.o
	g++ -std=c++11 -o te test.cpp InputEngine.o KeyCode.o Terminal.o
test : utest.cpp
	g++ -o utest utest.cpp
clean:
	rm *.o te utest
