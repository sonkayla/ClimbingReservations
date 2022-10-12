#include "Reservation.h"
#include "ClimbList.h"
#include "MemberList.h"
#include <iostream>

using namespace std;

int Reservations::addReservation(int theMemberID, 
    std::string theClimbName)
{
    if (count == 0)
    {
        first = new Node(FIRST_RESERVATION_NUMBER, theMemberID, 
            theClimbName, nullptr, nullptr);

        last = first;
    }
    else
    {
        Node* newNode = new Node(FIRST_RESERVATION_NUMBER + count,
            theMemberID, theClimbName, nullptr, last);
        last->setNext(new Node(FIRST_RESERVATION_NUMBER + count,
            theMemberID, theClimbName, nullptr, last));

        last = last->getNext();
    }

    count++;

    return last->getReservationNumber();

}

void Reservations::cancelReservation(int theReservationNumber)
{
    if (count == 1)
    {
        delete first;

        first = nullptr;
        last = first;
    }
    else
    {
        Node* deleting = findReservation(theReservationNumber);

        if (deleting == first)
        {
            first = first->getNext();
            first->setPrev(nullptr);
        }
        else if (deleting == last)
        {
            last = last->getPrev();
            last->setNext(nullptr);
        }
        else
        {
            deleting->getNext()->setPrev(deleting->getPrev());
            deleting->getPrev()->setNext(deleting->getNext());
        }

        delete deleting;
        deleting = nullptr;
    }

    count--;
}

void Reservations::printReservation(int theReservationNumber,
    const ClimbList& aClimbList, const MemberList& aMemberList) const
{
    Node* reservationNode = findReservation(theReservationNumber);

    aClimbList.printByClimbName(reservationNode->getClimbName());

    int memberPoints = 
        aMemberList.getPoints(reservationNode->getMemberID());
    int discount = memberPoints / 100;

    double theClimbPrice = 
        aClimbList.getPrice(reservationNode->getClimbName());

    cout << "\tDiscounted price using points: $" 
        << theClimbPrice - discount << "\n\n";
}

void Reservations::clearList()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;

    count = 0;
}

Reservations::~Reservations()
{
    clearList();
}
