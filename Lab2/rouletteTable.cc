#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include "rouletteTable.h"

using namespace std;

//--------------------------------------------
//this is a nice example of using an initializer list in a constructor
Roulette::Roulette(): numberRolled(-1)  {}
//--------------------------------------------
void Roulette::setNumberRolled(int value)
{			numberRolled = value; 		}
//--------------------------------------------
int Roulette::getNumberRolled()
{	return numberRolled; 	}
//--------------------------------------------
void Roulette::rollBall()
{
	numberRolled = rand()%37;//this returns 0 to 36	according to European roulette
}
//--------------------------------------------


