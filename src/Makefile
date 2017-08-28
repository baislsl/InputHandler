CXXFLAGS      += -std=gnu++11
all : InputEngine.o KeyCode.o Terminal.o InputBuffer.o Util.o Cursor.o
	g++ -std=c++11 -o te test.cpp InputEngine.o KeyCode.o Terminal.o InputBuffer.o Util.o Cursor.o
test : utest.cpp
	g++ -o utest utest.cpp
clean:
	rm *.o
