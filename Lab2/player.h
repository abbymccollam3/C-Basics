#include <iostream> //letting compiler know the variables are there
#include <cstdlib>
#include <vector>
#include <fstream>

#include "rouletteTable.h"

//These are called "inclusion guards."
//Although not always necessary they are 
//good to start to have in your header files
//in case your client calls your header files
//multiple times!!!

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
	public:
		//constructors -- you might have to add a default constructor
		Player(int amt): currentAmount(amt) {}	

		//member functions that allow differnt bets in Appendix A 
		//that you will need to create for completion of this lab!!
		//I have briefly indicated the inputs to the funcitons. 
		//The return results indicate if you have any money left!! techniques we are writing functions for
		bool betBlack(int,int); // amount to bet , winning number
		bool betRed(int,int); // amount to bet , winning number
		bool betStraightUp(int,int,int);// number to bet on , amount bet, winning number; use this for example A
		bool betDozen(int,int,int);// which dozen , bet amount , winning number
		bool betStreet(int,int,int); //street number , bet amount , winning number; he used this for example
		bool betDoubleStreet(int,int,int); //street number , bet amount , winning number
		bool betSquare(int,int,int); //square number , bet amount , winning number
		bool betColumn(int,int,int); // which column , bet amount , winning number

		//setters and getters
		int getCurrentAmount();
		void setCurrentAmount(int);

		//utility functions you can make private if you want
	private:
		bool isWinner(vector <int> , int);
		int winnings(bool, int, int); 

	private:
		int currentAmount; //This is the amount of money that the player has!(i.e. net worth)
};

#endif
