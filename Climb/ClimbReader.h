#include "ClimbList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string CLIMBS_FILE = "climbs_database.txt";

void createClimbList(ifstream& infile, ClimbList& climbList)
{
	string location,
		climbName;
	int duration = 0;
	char difficulty = 'e';
	double price = 0.0;

	while (!infile.eof())
	{
		infile >> location >> climbName >> duration >> difficulty 
			>> price;
		climbList.addClimb(location, climbName, duration, difficulty, 
			price);
	}
}

void getClimbData(ClimbList& climbList)
{
	ifstream infile;

	infile.open(CLIMBS_FILE);

	if (!infile)
	{
		cerr << CLIMBS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createClimbList(infile, climbList);

	infile.close();
}
