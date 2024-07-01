#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#ifndef ROULETTE_TABLE
#define ROULETTE_TABLE

class Roulette
{
	public:
		Roulette();
		void rollBall();

		void setNumberRolled(int);
		int getNumberRolled();

	private:
		int numberRolled;
};
#endif
