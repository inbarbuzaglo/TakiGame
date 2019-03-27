CXX=g++
CXXFLAGS=-std=c++0x

all: main.o Card.o Player.o Game.o
	$(CXX) $(CXXFLAGS) main.o Card.o Player.o Game.o -o a.out

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Card.o: Card.cpp
	$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o
	
Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp -o Game.o
	

clean:
	rm -f *.o a.out