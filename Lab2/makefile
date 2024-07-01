all: simulateBets

simulateBets : main.o player.o  rouletteTable.o
	g++ -std=c++0x main.o player.o rouletteTable.o -o simulateBets

main.o : main.cc player.h rouletteTable.h
	g++ -std=c++0x -c main.cc

player.o : player.cc player.h 
	g++ -std=c++0x -c player.cc

rouletteTable.o : rouletteTable.cc rouletteTable.h
	g++ -std=c++0x -c rouletteTable.cc

