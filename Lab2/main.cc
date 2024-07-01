
//but I will leave it in this format for this lab

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
#include "rouletteTable.h"
#include "player.h"

using namespace std;

#define SIM_DAYS 1000
#define NUM_OF_GAMES_IN_ONE_DAY 100
#define NUM_MINUTES_PER_ROLL 3
#define INITIAL_WORTH 200 
#define INITIAL_BET 10 
#define COST_OF_TRIP 1200

#define DEBUG false //change this to true to help verify and debug your code 

//Don't forget your function protoypes for your global functions
void StrategyExample_Simulation(string);
void StrategyA_Simulation(string);
void StrategyB_Simulation(string);
void StrategyC_Simulation(string);
void StrategyD_Simulation(string);
void StrategyE_Simulation(string);

int main()
{
   	srand(time(0)); 

		//You can comment this out in your program submission
		//StrategyExample_Simulation("StrategyExample.txt"); 

		//Your main might look something like the following 
		StrategyA_Simulation("StrategyA.txt");
		StrategyB_Simulation("StrategyB.txt");
   		StrategyC_Simulation("StrategyC.txt");
		StrategyD_Simulation("StrategyD.txt");
		StrategyE_Simulation("StrategyE.txt");
}

//----------------------------------------------------------------------------------------------
void StrategyExample_Simulation(string outFileName)
//If you are having trouble getting started, I have given
//you this function as a possible way that you can create
//your 5 global functions for each betting strategy
//
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
	//instantiate a roulette table
	Roulette table;

	//make an output file object for this betting strategy
	ofstream outFile; 

	//if (DEBUG) // then it is easier to look at one result in the file 
		outFile.open(outFileName, ios::out);
	//else //you might want to look at multiple runs in one file
		outFile.open(outFileName, ios::app);

	int total = 0; //used to calculate the average amount left at the end of the day
	int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
	int numberLoss = 0; 		// number of times the amount left is less than initial amount	
	int numberOverDouble = 0; //number of times you have doubled your money in one day
	int numberOverTripAmount = 0;//number of times you can pay for your trip!

	//instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play 	
	for (int days = 0 ; days < SIM_DAYS; days++)
   {	

		//reset the player's net worth at the beginning of the day
		player.setCurrentAmount(INITIAL_WORTH);

		int counter = 0; //This counts the number of games in one day
		int playerBet = INITIAL_BET; //This is a constant bet in this scenario
		bool outOfMoney= false; //When true you are broke! 

		//now simulate a day at the roulette table 
		while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
   	{
			//roll the ball on the table and generate winning number
			table.rollBall();
			
			if (DEBUG) //Note this flag is set at the top of this file
				cout << "This is game : " << counter << " of day " << days << endl;
			
			outOfMoney= player.betStreet(1,playerBet,table.getNumberRolled());

			//I will leave this up to you, but if you win the cost of trip
			//as a caring Georgia Tech Professor I advise that you stop
			//gambling!! I will use the outOfMoney sentinel to getout of 
			//this while loop.. so don't be confused by this variable hijacking
			if (player.getCurrentAmount() >= COST_OF_TRIP)	
				 outOfMoney= true;
			    	
		}//end while loop for at least around 5 hours of betting

		//now remember the result of this one day of betting for long-term stats
		if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
		if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
		if (player.getCurrentAmount() >= COST_OF_TRIP) numberOverTripAmount++;

		//now remember the total amount earned so as to calculate the average
		total += player.getCurrentAmount();
	   totalTime += counter*NUM_MINUTES_PER_ROLL;

		if (DEBUG) //only used to help validate or debug
			outFile << days << " " << player.getCurrentAmount() << endl;

	} //end loop for the 1000 days

	//now include information in your file concerning the questions asked in the lab
	//please have your other output files follow this same format. 
	//Make sure you understand why I did some type casting to float for test 1!
	outFile << outFileName << endl; //these are just questions being outputted to the output file
	outFile <<  fixed << setprecision(4);
	outFile << "The player started with $" << INITIAL_WORTH << endl;

	outFile << "Average amount at the end of the day: "  
			  << static_cast <float> (total)/ SIM_DAYS << endl;

	outFile << "Average amount of time at the table that day: " 
			  << static_cast <float> (totalTime)/SIM_DAYS << " minutes or " 
			  << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;
	
	outFile << "Percentage of days lost money: " 
			  << 100* static_cast <float> (numberLoss)/SIM_DAYS << endl;

	outFile << "Percentage of days over double initial worth: " 
			  << 100*static_cast <float> (numberOverDouble)/SIM_DAYS << endl;

	outFile << "Percentage of days paid for your trip: " 
			  << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;
	outFile << endl;

   outFile.close();
}

//--------------------------------------------------------------------------------------------------
void StrategyA_Simulation(string outFileName)//StrategyA.txt = outFileName
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
        //instantiate a roulette table
        Roulette table;

        //make an output file object for this betting strategy
        ofstream outFile;

        //if (DEBUG) // then it is easier to look at one result in the file 
                outFile.open(outFileName, ios::out);
        //else //you might want to look at multiple runs in one file
          //      outFile.open(outFileName, ios::app);

        int total = 0; //used to calculate the average amount left at the end of the day

        int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
        int numberLoss = 0;             // number of times the amount left is less than initial amount  
        int numberOverDouble = 0; //number of times you have doubled your money in one day
        int numberOverTripAmount = 0;//number of times you can pay for your trip!

        //instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play    
        for (int days = 0 ; days < SIM_DAYS; days++)
   {

                //reset the player's net worth at the beginning of the day
                player.setCurrentAmount(INITIAL_WORTH);

                int counter = 0; //This counts the number of games in one day
                int playerBet = INITIAL_BET; //This is a constant bet in this scenario
                bool outOfMoney= false; //When true you are broke! 

                //now simulate a day at the roulette table 
                while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
        {
                        //roll the ball on the table and generate winning number
                        table.rollBall();

                        if (DEBUG) //Note this flag is set at the top of this file
                                cout << "This is game : " << counter << " of day " << days << endl;

                        outOfMoney= player.betStraightUp(1,playerBet,table.getNumberRolled()); //here we are calling the betStraightUp function from player.cc showing the number chosen, amount about, and rolled number


                        //I will leave this up to you, but if you win the cost of trip
                        //as a caring Georgia Tech Professor I advise that you stop
                        //gambling!! I will use the outOfMoney sentinel to getout of 
                        //this while loop.. so don't be confused by this variable hijacking
                        if (player.getCurrentAmount() >= COST_OF_TRIP)  
                                 outOfMoney= true;

                }//end while loop for at least around 5 hours of betting

                //now remember the result of this one day of betting for long-term stats
                if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
                if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
                if (player.getCurrentAmount() >= COST_OF_TRIP) numberOverTripAmount++;

                //now remember the total amount earned so as to calculate the average
                total += player.getCurrentAmount();
           totalTime += counter*NUM_MINUTES_PER_ROLL;

                if (DEBUG) //only used to help validate or debug
                        outFile << days << " " << player.getCurrentAmount() << endl;

        } //end loop for the 1000 days

        //now include information in your file concerning the questions asked in the lab
        //please have your other output files follow this same format. 
        //Make sure you understand why I did some type casting to float for test 1!
        outFile << outFileName << endl;
        outFile <<  fixed << setprecision(4);
        outFile << "The player started with $" << INITIAL_WORTH << endl;

	outFile << "Average amount at the end of the day: "  
                          << static_cast <float> (total)/ SIM_DAYS << endl;

	outFile << "Percentage of days lost money: "
                          << 100* static_cast <float> (numberLoss)/SIM_DAYS << endl;

  	outFile << "Percentage of days over double initial worth: "
                          << 100*static_cast <float> (numberOverDouble)/SIM_DAYS << endl;        

	outFile << "Percentage of days paid for your trip: "
                          << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;

        outFile << "Average amount of time at the table that day: "
                          << static_cast <float> (totalTime)/SIM_DAYS << " minutes or "
                          << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;

        outFile << endl;

   outFile.close();
}


//--------------------------------------------------------------------------------------------------
void StrategyB_Simulation(string outFileName)//StrategyA.txt = outFileName
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
        //instantiate a roulette table
        Roulette table;

        //make an output file object for this betting strategy
        ofstream outFile;

        //if (DEBUG) // then it is easier to look at one result in the file 
                outFile.open(outFileName, ios::out);
        //else //you might want to look at multiple runs in one file
               // outFile.open(outFileName, ios::app);

        int total = 0; //used to calculate the average amount left at the end of the day

        int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
        int numberLoss = 0;             // number of times the amount left is less than initial amount  
        int numberOverDouble = 0; //number of times you have doubled your money in one day
        int numberOverTripAmount = 0;//number of times you can pay for your trip!

        //instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play    
        for (int days = 0 ; days < SIM_DAYS; days++)
   {

                //reset the player's net worth at the beginning of the day
                player.setCurrentAmount(INITIAL_WORTH);

                int counter = 0; //This counts the number of games in one day
                int playerBet = INITIAL_BET; //This is a constant bet in this scenario
                bool outOfMoney= false; //When true you are broke! 

                //now simulate a day at the roulette table 
                while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
        {
                        //roll the ball on the table and generate winning number
                        table.rollBall();

                        if (DEBUG) //Note this flag is set at the top of this file
                                cout << "This is game : " << counter << " of day " << days << endl;

                        outOfMoney= player.betStraightUp(1,playerBet,table.getNumberRolled()); //calling Bet Straight Up again


                        //I will leave this up to you, but if you win the cost of trip
                        //as a caring Georgia Tech Professor I advise that you stop
                        //gambling!! I will use the outOfMoney sentinel to getout of 
                        //this while loop.. so don't be confused by this variable hijacking
                        if (player.getCurrentAmount() >= COST_OF_TRIP)
                                 outOfMoney= true;

                }//end while loop for at least around 5 hours of betting

                //now remember the result of this one day of betting for long-term stats
                if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
                if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
                if (player.getCurrentAmount() >= COST_OF_TRIP) numberOverTripAmount++;

                //now remember the total amount earned so as to calculate the average
                total += player.getCurrentAmount();
           totalTime += counter*NUM_MINUTES_PER_ROLL;

                if (DEBUG) //only used to help validate or debug
                        outFile << days << " " << player.getCurrentAmount() << endl;

        } //end loop for the 1000 days

        //now include information in your file concerning the questions asked in the lab
        //please have your other output files follow this same format. 
        //Make sure you understand why I did some type casting to float for test 1!
        outFile << outFileName << endl;
        outFile <<  fixed << setprecision(4);

   	outFile << "The player started with " << INITIAL_WORTH << endl;

        outFile << "Average amount at the end of the day : " << static_cast <float> (total)/ SIM_DAYS << endl;

        outFile << "Average amount of time at the table that day: " << static_cast <float> (totalTime)/SIM_DAYS << " minutes or " << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;

        outFile << "Percentage of days lost money : "
                          << 100* static_cast <float> (numberLoss)/SIM_DAYS << endl;

        outFile << "Percentage of days over double initial worth : "
                          << 100*static_cast <float> (numberOverDouble)/SIM_DAYS << endl;

        outFile << "Percentage of days paid for your trip: "
                          << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;
        
	outFile << "Bet straight up constantly maximizes the chance that you will double your money and also maximizes the chance that you will have enough to pay for the trip." << endl;

      outFile << endl;

   outFile.close();
}

//--------------------------------------------------------------------------------------------------
void StrategyC_Simulation(string outFileName)//StrategyA.txt = outFileName
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
        //instantiate a roulette table
        Roulette table;

        //make an output file object for this betting strategy
        ofstream outFile;

        //if (DEBUG) // then it is easier to look at one result in the file 
                outFile.open(outFileName, ios::out);
        //else //you might want to look at multiple runs in one file
          //      outFile.open(outFileName, ios::app);

        int total = 0; //used to calculate the average amount left at the end of the day

        int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
        int numberLoss = 0;             // number of times the amount left is less than initial amount  
        int numberOverDouble = 0; //number of times you have doubled your money in one day
        int numberOverTripAmount = 0;//number of times you can pay for your trip!

        //instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play    
        for (int days = 0 ; days < SIM_DAYS; days++)
   {

                //reset the player's net worth at the beginning of the day
                player.setCurrentAmount(INITIAL_WORTH);

                int counter = 0; //This counts the number of games in one day
                int playerBet = INITIAL_BET; //This is not a constant bet in this scenario
                bool outOfMoney= false; //When true you are broke! 
			
                //now simulate a day at the roulette table 
                while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
        {
                        //roll the ball on the table and generate winning number
                        table.rollBall();

                        if (DEBUG) //Note this flag is set at the top of this file
                                cout << "This is game : " << counter << " of day " << days << endl;

                        outOfMoney= player.betRed(playerBet,table.getNumberRolled()); //this is changed; 1??
			
			if(INITIAL_WORTH > player.getCurrentAmount()) //if our initial worth is greater than our current amount, we need to do the following
			{
				playerBet = INITIAL_WORTH - player.getCurrentAmount() + INITIAL_BET; //1200 - current amount of money + initial bet
			}
			else //if our initial worth is not greater than our current, then we bet the amount of our initial bet
			{
				playerBet = INITIAL_BET;
			}

                        //I will leave this up to you, but if you win the cost of trip
                        //as a caring Georgia Tech Professor I advise that you stop
                        //gambling!! I will use the outOfMoney sentinel to getout of 
                        //this while loop.. so don't be confused by this variable hijacking
                        if (player.getCurrentAmount() >= COST_OF_TRIP)
				outOfMoney= true;

                }//end while loop for at least around 5 hours of betting

                //now remember the result of this one day of betting for long-term stats
                if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
                if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
                if (player.getCurrentAmount() >= COST_OF_TRIP) numberOverTripAmount++;

                //now remember the total amount earned so as to calculate the average
                total += player.getCurrentAmount();
           totalTime += counter*NUM_MINUTES_PER_ROLL;

                if (DEBUG) //only used to help validate or debug
                        outFile << days << " " << player.getCurrentAmount() << endl;
		
//begin code

	} //end loop for the 1000 days

        //now include information in your file concerning the questions asked in the lab
        //please have your other output files follow this same format. 
        //Make sure you understand why I did some type casting to float for test 1!
        outFile << outFileName << endl;
        outFile <<  fixed << setprecision(4);

        outFile << "The player started with " << INITIAL_WORTH << endl;

        outFile << "Percentage of simulations ending with less than initial amount:  " << 100*static_cast <float> (numberLoss)/SIM_DAYS << endl;

        outFile << "Percentage of days over double initial worth : "
                          << 100*static_cast <float> (numberOverDouble)/SIM_DAYS << endl;

	outFile << "Average amount of time at the table that day: " << static_cast <float> (totalTime)/SIM_DAYS << " minutes or " << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;

        outFile << "Percentage of days paid for your trip: "
                          << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;

	outFile << "If you decided that you could spend 10 hours in the casino on the first day, this would hardly change the results on 1000 days of game play, since the 10 hours is only applicable to the first day. However, this does change statistics on that first day increasing the percentages of ending with less than the initial amount, days doubling initial amount, and days paid for the trip, as there is more time spent betting, seeing one does not run out of money." << endl;

      outFile << endl;

   outFile.close();
}


//--------------------------------------------------------------------------------------------------
void StrategyD_Simulation(string outFileName)//StrategyA.txt = outFileName
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
        //instantiate a roulette table
        Roulette table;

        //make an output file object for this betting strategy
        ofstream outFile;

       // if (DEBUG) // then it is easier to look at one result in the file 
                outFile.open(outFileName, ios::out);
       // else //you might want to look at multiple runs in one file
         //       outFile.open(outFileName, ios::app);

        int total = 0; //used to calculate the average amount left at the end of the day

        int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
        int numberLoss = 0;             // number of times the amount left is less than initial amount  
        int numberOverDouble = 0; //number of times you have doubled your money in one day
        int numberOverTripAmount = 0;//number of times you can pay for your trip!

        //instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play    
        for (int days = 0 ; days < SIM_DAYS; days++)
   {

                //reset the player's net worth at the beginning of the day
                player.setCurrentAmount(INITIAL_WORTH);

                int counter = 0; //This counts the number of games in one day
                int playerBet = INITIAL_BET; //This is not a constant bet in this scenario
                bool outOfMoney= false; //When true you are broke! 

                //now simulate a day at the roulette table 
                while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
        {
                        //roll the ball on the table and generate winning number
                        table.rollBall();

                        if (DEBUG) //Note this flag is set at the top of this file
                                cout << "This is game : " << counter << " of day " << days << endl;

                        outOfMoney= player.betDozen(1, playerBet,table.getNumberRolled()); //this is changed; 1??

                        if(INITIAL_WORTH > player.getCurrentAmount())
                        {
                                playerBet = INITIAL_WORTH - player.getCurrentAmount() + INITIAL_BET;
                        }
                        else
                        {
                                playerBet = INITIAL_BET;
                        }


                        //I will leave this up to you, but if you win the cost of trip
                        //as a caring Georgia Tech Professor I advise that you stop
                        //gambling!! I will use the outOfMoney sentinel to getout of 
                        //this while loop.. so don't be confused by this variable hijacking
                        if (player.getCurrentAmount() >= COST_OF_TRIP)
                                outOfMoney= true;

                }//end while loop for at least around 5 hours of betting

                //now remember the result of this one day of betting for long-term stats
                if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
                if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
                if (player.getCurrentAmount() >= COST_OF_TRIP) numberOverTripAmount++;

                //now remember the total amount earned so as to calculate the average
                total += player.getCurrentAmount();
           totalTime += counter*NUM_MINUTES_PER_ROLL;

                if (DEBUG) //only used to help validate or debug
                        outFile << days << " " << player.getCurrentAmount() << endl;

//begin code

        } //end loop for the 1000 days

        //now include information in your file concerning the questions asked in the lab
        //please have your other output files follow this same format. 
        //Make sure you understand why I did some type casting to float for test 1!
        outFile << outFileName << endl;
        outFile <<  fixed << setprecision(4);

        outFile << "The player started with $" << INITIAL_WORTH << endl;

        outFile << "Percentage of simulations ending with less than initial amount: " << 100*static_cast <float> (numberLoss)/SIM_DAYS << endl;

        outFile << "Percentage of days over double initial worth: "
                          << 100*static_cast <float> (numberOverDouble)/SIM_DAYS << endl;

        outFile << "Average amount of time at the table that day: "
                          << static_cast <float> (totalTime)/SIM_DAYS << " minutes or "
                          << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;

	outFile << "Percentage of days paid for your trip: "
                          << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;

	outFile << "This method is better than Strategy C in that there are more days the player is winning over double their initial worth and the average amount of time the player spends at the table is less; however, this strategy also leads to the player ending with less than their initial amount more often." << endl;

      outFile << endl;

   outFile.close();
}
//--------------------------------------------------------------------------------------------------
void StrategyE_Simulation(string outFileName)
//If you are having trouble getting started, I have given
//you this function as a possible way that you can create
//your 5 global functions for each betting strategy
//
//FIRST VALUE: This is the name of the output text file that will show statistics! 
{
        //instantiate a roulette table
        Roulette table;

        //make an output file object for this betting strategy
        ofstream outFile; 

       // if (DEBUG) // then it is easier to look at one result in the file 
                outFile.open(outFileName, ios::out);

	//else //you might want to look at multiple runs in one file
          //      outFile.open(outFileName, ios::app);

        int total = 0; //used to calculate the average amount left at the end of the day
        int totalTime = 0; //used to calculate the aveage time in the casino! 

   //use these variables to determine answers to lab questions.
        int numberLoss = 0;             // number of times the amount left is less than initial amount  
        int numberOverDouble = 0; //number of times you have doubled your money in one day
        int numberOverTripAmount = 0;//number of times you can pay for your trip

        //instantiate a player for your simulation with 200 dollars
   Player player(INITIAL_WORTH);

   //simulate 1000 days of game play    
        for (int days = 0 ; days < SIM_DAYS; days++)
   {

                //reset the player's net worth at the beginning of the day
                player.setCurrentAmount(INITIAL_WORTH);

                int counter = 0; //This counts the number of games in one day
                int playerBet = 20; //using $20 as initial bet
                bool outOfMoney= false; //When true you are broke! 

                //now simulate a day at the roulette table 
                while ((!outOfMoney) && (counter++ < NUM_OF_GAMES_IN_ONE_DAY) )
        {
                        //roll the ball on the table and generate winning number
                        table.rollBall();

                        if (DEBUG) //Note this flag is set at the top of this file
                                cout << "This is game : " << counter << " of day " << days << endl;

                        outOfMoney= player.betBlack(playerBet,table.getNumberRolled()); //CHANGE THIS

			if(INITIAL_WORTH > player.getCurrentAmount())
                        {
                                playerBet = INITIAL_WORTH - player.getCurrentAmount() + 20;
                        }
                        else
                        {
                                playerBet = 20;
                        }

                        //I will leave this up to you, but if you win the cost of trip
                        //as a caring Georgia Tech Professor I advise that you stop
                        //gambling!! I will use the outOfMoney sentinel to getout of 
                        //this while loop.. so don't be confused by this variable hijacking
                        if (player.getCurrentAmount() >= 220) //since we only care about winning $20 for lunch, we can end the simulation here
                                 outOfMoney= true;

                }//end while loop for at least around 5 hours of betting
             //now remember the result of this one day of betting for long-term stats
                if (player.getCurrentAmount() <  INITIAL_WORTH) numberLoss++;
                if (player.getCurrentAmount() >= 2*INITIAL_WORTH) numberOverDouble++;
                if (player.getCurrentAmount() >= 220) numberOverTripAmount++; //we only care about getting to $220, not getting to $1200

                //now remember the total amount earned so as to calculate the average
                total += player.getCurrentAmount();
           totalTime += counter*NUM_MINUTES_PER_ROLL;

                if (DEBUG) //only used to help validate or debug
                        outFile << days << " " << player.getCurrentAmount() << endl;

        } //end loop for the 1000 days

        //now include information in your file concerning the questions asked in the lab
        //please have your other output files follow this same format. 
        //Make sure you understand why I did some type casting to float for test 1!
        outFile << outFileName << endl;
        outFile <<  fixed << setprecision(4);
        outFile << "The player started with $" << INITIAL_WORTH << endl;

        outFile << "Average amount of time at the table that day: "
                          << static_cast <float> (totalTime)/SIM_DAYS << " minutes or "
                          << static_cast <float> (totalTime)/(SIM_DAYS*60) << " hours" <<  endl;

        outFile << "Percentage of days lost money: "
                          << 100* static_cast <float> (numberLoss)/SIM_DAYS << endl;

	outFile << "Percentage of days winning lunch money: "
                          << 100*static_cast <float> (numberOverTripAmount)/SIM_DAYS << endl;

	outFile << "This compares to betting $10 on black consistently becuase the Martingale strategy is a guarenteed win eventually. Using this strategy rather than consistently betting on black is better in this case especially because we only need to win $20 more than we started with and if our initial bet is $20, this will be acheieved quickly and at a higher percentage of the time." <<endl;

        outFile << endl;

   outFile.close();
}

