#include "rouletteTable.h"
#include "player.h"

#define DEBUG false //change this to true to help verify and debug your code 

using namespace std;

//--------------------------------------------------
void Player::setCurrentAmount(int amountValue)
{ 		
	currentAmount = amountValue;
}
//--------------------------------------------------
int Player::getCurrentAmount()
{
		return (currentAmount);
}
//--------------------------------------------------
bool Player::isWinner(vector <int> numbersBetOn, int winningNumber)
{
	bool win = false;

	//Go through the entire betting vector to see if there is a match
	for (int i = 0; i < numbersBetOn.size(); i++)
	{
			if (numbersBetOn[i] == winningNumber)
				win = true; 
	} 

	return win;
}
//--------------------------------------------------
int Player::winnings(bool winBet, int amountBet, int houseOdds)
{
		if (winBet) // is true then, make sure you are giving it a boolean value
		{
			return(houseOdds*amountBet);
		}
		else // I will assume that this will return negative earnings to be added to net worth
		{
			return(-1 * amountBet);
		}
}
//--------------------------------------------------
bool Player::betStreet(int which, int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{

	//Do a little error checking to make sure your client uses your function correctly
 	if ((which < 1) || (which > 12)) //then error
	{
		//ask me in class about the difference between cerr and cout
		cerr << "Not a valid entry for street bet" << endl;
		return true; //this hijacks the outOfMoney sentinel to quit for the day
	}

 	if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
	{
		//therefore bet the rest of your money!!!
		amountBet = currentAmount; //use this for all scenarios
	}

	 vector <int> temp(3); //each set for a street bet is 3 numbers 

	 //please note that these values came from Appendix A
	 //check over them to make sure there is no mistake! 
	 switch (which)
	 {
	  case 1: temp = {1,2,3}; break;
	  case 2: temp = {4,5,6}; break;
	  case 3: temp = {7,8,9}; break;
	  case 4: temp = {10,11,12}; break;
	  case 5: temp = {13,14,15}; break;
	  case 6: temp = {16,17,18}; break;
	  case 7: temp = {19,20,21}; break;
	  case 8: temp = {22,23,24}; break;
	  case 9: temp = {25,26,27}; break;
	  case 10: temp = {28,29,30}; break;
	  case 11: temp = {31,32,33}; break;
	  case 12: temp = {34,35,36}; break;
	 }

	if (DEBUG)// this can help with validating and runtime debugging	
			cout << rolledValue<< ":: " << currentAmount 
				  << ": " << winnings(isWinner(temp, rolledValue), amountBet, 11)
				  << endl;

	//now change the amount that the player has based on the bet!! 
	 currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 11);

	if (currentAmount <= 0)
			return (true); // You are out of money and let global function know it! 
	else
			return (false); //You still have money so you can keep going
}

//--------------------------------------------------
bool Player::betStraightUp(int whichnumber, int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{

        //Do a little error checking to make sure your client uses your function correctly
        if ((whichnumber < 0) || (whichnumber > 36)) //mnaking sure number user enters is between 1 and 36
        {
                //ask me in class about the difference between cerr and cout
                cerr << "Not a valid entry for straight up bet" << endl;
                return true; //this hijacks the outOfMoney sentinel to quit for the day
        }

        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }

        vector <int> temp = {whichnumber};
 

         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 

	

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount << ": " << winnings(isWinner(temp, rolledValue), amountBet, 35) << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 35);

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}


//--------------------------------------------------
bool Player::betRed(int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{
        
        //Do a little error checking to make sure your client uses your function correctly

        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }

         vector <int> temp = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36}; //we can just define even numbers as Bet Red
		

         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount << ": " << winnings(isWinner(temp, rolledValue), amountBet, 1) << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 1); //the 1 is the odds of winning

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}


//--------------------------------------------------
bool Player::betBlack(int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{

        //Do a little error checking to make sure your client uses your function correctly

        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }

         vector <int> temp = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35}; //defining Bet Black as all odd numbers


         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount << ": " << winnings(isWinner(temp, rolledValue), amountBet, 1) << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 1); //1 representing the oddds

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}


//----------------------------------------------------------------------
bool Player::betDozen(int whichnumber, int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{

        //Do a little error checking to make sure your client uses your function correctly
        if ((whichnumber < 1) || (whichnumber > 3)) //mnaking sure number user enters is between 1 and 3, including both, for the amount of cases
        {
                //ask me in class about the difference between cerr and cout
                cerr << "Not a valid entry for straight up bet" << endl;
                return true; //this hijacks the outOfMoney sentinel to quit for the day
        }

        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }

        vector <int> temp(12); //number of elements in vector is 12

	 switch (whichnumber)
         {
          case 1: temp = {1,2,3,4,5,6,7,8,9,10,11,12}; break;
          case 2: temp = {13,14,15,16,17,18,19,20,21,22,23,24}; break;
          case 3: temp = {25,26,27,28,29,30,31,32,33,34,35,36}; break;
	}

         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 



        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount << ": " << winnings(isWinner(temp, rolledValue), amountBet, 2) << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 2);

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}

//--------------------------------------------------------------------------------------------------------------
bool Player::betDoubleStreet(int whichnumber, int amountBet, int rolledValue)
{

        //Do a little error checking to make sure your client uses your function correctly
        if ((whichnumber < 1) || (whichnumber > 11)) //then error
        {
                //ask me in class about the difference between cerr and cout
                cerr << "Not a valid entry for street bet" << endl;
                return true; //this hijacks the outOfMoney sentinel to quit for the day
        }

        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }

         vector <int> temp(6); //each set for a street bet is 3 numbers 

         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 
         switch (whichnumber)
         {
          case 1: temp = {1,2,3,4,5,6}; break; //cases represnting all possible options player can choose for Double Street Bet
          case 2: temp = {4,5,6,7,8,9}; break;
          case 3: temp = {7,8,9,10,11,12}; break;
          case 4: temp = {10,11,12,13,14,15}; break;
          case 5: temp = {13,14,15,16,17,18}; break;
          case 6: temp = {16,17,18,19,20,21}; break;
          case 7: temp = {19,20,21,22,23,24}; break;
          case 8: temp = {22,23,24,25,26,27}; break;
          case 9: temp = {25,26,27,28,29,30}; break;
          case 10: temp = {28,29,30,31,32,33}; break;
          case 11: temp = {31,32,33,34,35,36}; break;
         }

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount
                                  << ": " << winnings(isWinner(temp, rolledValue), amountBet, 11)
                                  << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 11);

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}

//--------------------------------------------------------------------------------------------------------------
bool Player::betSquare(int whichnumber, int amountBet, int rolledValue)
{

        //Do a little error checking to make sure your client uses your function correctly
        if ((whichnumber < 1) || (whichnumber > 22)) //then error
        {
                //ask me in class about the difference between cerr and cout
                cerr << "Not a valid entry for street bet" << endl;
                return true; //this hijacks the outOfMoney sentinel to quit for the day
        }       
        
        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }       
        
         vector <int> temp(6); //vector with 6 elements
         
         switch (whichnumber) //calling whichnumber variable from betSquare()
         {
          case 1: temp = {1,2,4,5}; break;
          case 2: temp = {2,3,5,6}; break;
          case 3: temp = {4,5,7,8}; break;
          case 4: temp = {5,6,8,9}; break;
          case 5: temp = {7,8,10,11}; break;
          case 6: temp = {8,9,11,12}; break;
          case 7: temp = {10,11,13,14}; break;
          case 8: temp = {11,12,14,15}; break;
          case 9: temp = {13,14,16,17}; break;
          case 10: temp = {14,15,17,18}; break;
          case 11: temp = {16,17,19,20}; break;
	  case 12: temp = {17,18,20,21}; break;
          case 13: temp = {19,20,22,23}; break;
          case 14: temp = {20,21,23,24}; break;
          case 15: temp = {22,23,25,26}; break;
          case 16: temp = {23,24,26,27}; break;
          case 17: temp = {25,26,28,29}; break;
          case 18: temp = {26,27,29,30}; break;
          case 19: temp = {28,29,31,32}; break;
          case 20: temp = {29,30,32,33}; break;
          case 21: temp = {31,32,34,35}; break;
          case 22: temp = {32,33,35,36}; break;
         }

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount
                                  << ": " << winnings(isWinner(temp, rolledValue), amountBet, 11)
                                  << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 11);

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}

//--------------------------------------------------------------------------------------------------------------
bool Player::betColumn(int whichnumber, int amountBet, int rolledValue)
{

        //Do a little error checking to make sure your client uses your function correctly
        if ((whichnumber < 1) || (whichnumber > 3)) //player must choose a case 1,2, or 3
        {
                //ask me in class about the difference between cerr and cout
                cerr << "Not a valid entry for street bet" << endl;
                return true; //this hijacks the outOfMoney sentinel to quit for the day
        }       
        
        if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
        {
                //therefore bet the rest of your money!!!
                amountBet = currentAmount; //use this for all scenarios
        }       
        
         vector <int> temp(12); //each set for a street bet is 3 numbers 
         
         //please note that these values came from Appendix A
         //check over them to make sure there is no mistake! 
         switch (whichnumber)
         {
          case 1: temp = {1,4,7,10,13,16,19,22,25,28,31,34}; break;
          case 2: temp = {2,5,8,11,14,17,20,23,26,29,32,35}; break;
          case 3: temp = {3,6,9,12,15,18,21,24,27,30,33,36}; break;
         }

        if (DEBUG)// this can help with validating and runtime debugging        
                        cout << rolledValue<< ":: " << currentAmount
                                  << ": " << winnings(isWinner(temp, rolledValue), amountBet, 11)
                                  << endl;

        //now change the amount that the player has based on the bet!! 
         currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 11);

        if (currentAmount <= 0)
                        return (true); // You are out of money and let global function know it! 
        else
                        return (false); //You still have money so you can keep going
}



