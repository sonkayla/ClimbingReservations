#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservations(ifstream& infile, Reservations& reservations)
{

	int memberID = 0;
	string climbName;

	while (!infile.eof())
	{
		infile >> memberID >> climbName;
		reservations.addReservation(memberID, climbName);
	}
}

void getReservationData(Reservations& reservations)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservations(infile, reservations);

	infile.close();
}
