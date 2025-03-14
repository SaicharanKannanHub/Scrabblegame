.default: all

all: scrabble

clean:
	rm -rf scrabble *.o *.dSYM

scrabble: Tile.o Node.o LinkedList.o scrabble.o Board.o Utils.o Player.o Gameplay.o PlayerHand.o TilesBag.o Tile.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
