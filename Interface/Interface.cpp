#include "Interface.h"
#include "ClimbList.h"
#include "MemberList.h"
#include "Reservation.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
    cout << "\n" << string(51, '*') << endl;
    cout << "\t\tHIKING IN THE US" << endl;
    cout << string(51, '*') << endl;
    cout << "\n\t1. Browse by location\n"
        << "\t2. Browse by duration\n"
        << "\t3. Browse by difficulty\n"
        << "\t4. Browse by price\n"
        << "\t5. Make a reservation\n"
        << "\t6. View Reservation\n"
        << "\t7. Cancel reservation\n"
        << "\t8. Exit\n";
    cout << endl;
}

void processReservation(ClimbList& theClimbList, 
    MemberList& theMemberList, Reservations& theReservations)
{
    int menuChoice = 0;
   
    cout << "Please make a selection: ";
    cin >> menuChoice; 
        
    while (menuChoice != 8)
    {

        cout << endl;           
             
        if (menuChoice == 1)
        {
            chooseByLocation(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 2)
        {
            chooseByDuration(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 3)
        {
            chooseByDifficulty(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 4)
        {
            chooseByPrice(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 5)
        {
            makeReservation(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 6)
        {
            viewReservation(theClimbList, theMemberList, 
                theReservations);
        }
        else if (menuChoice == 7)
        {
            cancelReservation(theClimbList, theMemberList, 
                theReservations);
        }

        cout << endl;
        system("Pause");
        displayMenu();

        cout << "Please make a selection: ";
        cin >> menuChoice;
    }

    cout << "\nThank you for visiting!\n";

}

void chooseByLocation(ClimbList& theClimbList, 
    MemberList& theMemberList, Reservations& theReservations)
{
    theClimbList.printAllLocations();

    string locationChoice;
    cout << "Choose a location: ";
    cin >> locationChoice;
    cout << endl;

    theClimbList.printByLocation(locationChoice);
    askToReserve(theClimbList, theMemberList, theReservations);
}

void chooseByDuration(ClimbList& theClimbList,
    MemberList& theMemberList, Reservations& theReservations)
{
    cout << "\t(days)" << endl;

    theClimbList.printByDuration();

    int numOfDays = 0;
    cout << "How many days are you considering? ";
    cin >> numOfDays;
    cout << endl;

    theClimbList.printByDuration(numOfDays);
    askToReserve(theClimbList, theMemberList, theReservations);

}

void chooseByDifficulty(ClimbList& theClimbList, MemberList& theMemberList,
    Reservations& theReservations)
{
    cout << "Choose difficulty level: \n" << endl;
    cout << "\te. easy"
        << "\n\tm. moderate"
        << "\n\ts. strenous\n\n";

    char theDifficulty = ' ';
    cout << "Your choice: ";
    cin >> theDifficulty;

    cout << "\n\t(difficulty level)" << endl;

    theClimbList.printByDifficulty(theDifficulty);
    askToReserve(theClimbList, theMemberList, theReservations);
}

void chooseByPrice(ClimbList& theClimbList, MemberList& theMemberList,
    Reservations& theReservations)
{
    theClimbList.printByPrice();
    askToReserve(theClimbList, theMemberList, theReservations);
}

int askIfMember(MemberList& theMemberList)
{
    char answerToConfirm = ' ';
    cout << "\nAre you a member? (y/n) ";
    cin >> answerToConfirm;
    cout << endl;

    if (answerToConfirm == 'y')
    {
        int idNumber = 0;
        cout << "What is your member ID number? ";
        cin >> idNumber;
        cout << endl;

        string lastName;
        cout << "What is your last name? ";
        cin >> lastName;
        cout << endl;

        theMemberList.printMember(idNumber, lastName);

        return idNumber;
    }
    else
    {
        return addNewMember(theMemberList);
    }

}

int addNewMember(MemberList& theMemberList)
{
    cout << "\tLet's add you to the member list!" << endl;

    string firstName, lastName;
    cout << "\t\tWhat is your first name? ";
    cin >> firstName;
    cout << "\t\tWhat is your last name? ";
    cin >> lastName;


    theMemberList.addMember(firstName, lastName);
    cout << "\n\tWelcome to the club!"
        << "\n\t\tYour member ID number is: " 
        << theMemberList.getLastID();

    return theMemberList.getLastID();
}

void makeReservation(ClimbList& theClimbList, 
    MemberList& theMemberList, Reservations& theReservations)
{
    int idRetrieved = askIfMember(theMemberList);

    string theClimbName;
    cout << endl << "Which area would you like to reserve (rock climb name)? ";
    cin >> theClimbName;

    theClimbList.printByClimbName(theClimbName);

    double price = theClimbList.getPrice(theClimbName);
    int points = theMemberList.getPoints(idRetrieved);
    double discount = price - (points / 100);

    cout << "\tDiscounted price using points: $" << fixed
        << showpoint << setprecision(2) << discount << endl;

    cout << "\n\tBefore proceeding, please make a note of your reservation number."
        << "\n\t  Reservation #: " <<
        theReservations.addReservation(idRetrieved, theClimbName) << endl;

    cout << "\n( *** Will continue to scheduling and payment. *** )" << endl;

}

void viewReservation(ClimbList& theClimbList, MemberList& theMemberList,
    Reservations& theReservations)
{
    int reservationNum = 0;
    cout << "Enter reservation #: ";
    cin >> reservationNum;
    cout << endl;

    theReservations.printReservation(reservationNum, theClimbList, theMemberList);
}

void cancelReservation(ClimbList& theClimbList, MemberList& theMemberList,
    Reservations& theReservations)
{
    int reservationNum = 0;
    cout << "Enter reservation #: ";
    cin >> reservationNum;

    theReservations.printReservation(reservationNum, theClimbList, theMemberList);

    char userAnswer = ' ';
    cout << "Are you sure you want to cancel this reservation? (y / n) ";
    cin >> userAnswer;

    if (userAnswer == 'y')
    {
        theReservations.cancelReservation(reservationNum);

        cout << "\nReservation #" << reservationNum << " has been canceled.\n";
    }
}

void askToReserve(ClimbList& theClimbList, MemberList& theMemberList,
    Reservations& theReservations)
{
    char userAnswer = ' ';
    cout << "Would you like to make a reservation? (y/n) ";
    cin >> userAnswer;

    if (userAnswer == 'y')
    {
        makeReservation(theClimbList, theMemberList, theReservations);
    }
}
