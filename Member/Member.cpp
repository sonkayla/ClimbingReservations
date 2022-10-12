
#include "Member.h"

#include <iostream>

using namespace std;

void Member::addPoints(int thePoints)
{
    points += thePoints;
}

void Member::setID(int idNumber)
{
    id = idNumber;
}

int Member::getID() const
{
    return id;
}

string Member::getLastName() const
{
    return lastName;
}

int Member::getPoints() const
{
    return points;
}

void Member::printMember() const
{
    cout << "\t" << lastName << ", " << firstName
        << "\n\t" << "Points available: " << points << endl;
}

bool Member::operator<(const Member& paramMember) const
{
    return (id < paramMember.id);
}
