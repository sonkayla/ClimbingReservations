#include "Interface.h"
#include "ClimbReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ClimbList theClimbList;
    MemberList theMemberList;
    Reservations theReservations;

    getClimbData(theClimbList);
    getMemberData(theMemberList);
    getReservationData(theReservations);

    displayMenu();
    processReservation(theClimbList, theMemberList, theReservations);

    //system("Pause");
    return 0;
}