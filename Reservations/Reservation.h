#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <string>
#include <iostream>
#include "ClimbList.h"
#include "MemberList.h"

const int FIRST_RESERVATION_NUMBER = 50001;

class Node
{

public:
    Node() : reservationNumber(0), memberID(0), prev(nullptr),
        next(nullptr) {}

    Node(int theReservationNumber, int theMemberID, 
        std::string theClimbName, Node* nextLink, Node* prevLink)
        : reservationNumber(theReservationNumber),
        memberID(theMemberID), climbName(theClimbName),
        next(nextLink), prev(prevLink) {}

    int getReservationNumber() const
    {
        return reservationNumber;
    }

    int getMemberID() const
    {
        return memberID;
    }

    std::string getClimbName() const
    {
        return climbName;
    }

    Node* getPrev() const
    {
        return prev;
    }

    Node* getNext() const
    {
        return next;
    }

    void setReservationNumber(int theReservationNumber)
    {
        reservationNumber = theReservationNumber;
    }

    void setMemberID(int theMemberID)
    {
        memberID = theMemberID;
    }

    void setPrev(Node* prevLink)
    {
        prev = prevLink;
    }

    void setNext(Node* nextLink)
    {
        next = nextLink;
    }

    ~Node() {}

private:
    int reservationNumber;
    int memberID;
    std::string climbName;
    Node* next;
    Node* prev;
};

class Reservations
{

public:
    Reservations() : first(nullptr), last(nullptr), count(0) {}

    int addReservation(int theMemberID, std::string theClimbName);

    void cancelReservation(int theReservationNumber);

    void printReservation(int theReservationNumber,
        const ClimbList& aClimbList, 
        const MemberList& aMemberList) const;

    void clearList();

    ~Reservations();

private:
    Node* first;
    Node* last;
    int count;

    Node* findReservation(int theReservationNumber) const
    {
        Node* current = first;
        bool found = false;
        while (current != nullptr && !found)
        {
            if (current->getReservationNumber() 
                == theReservationNumber)
            {
                found = true;
            }
            else
            {
                current = current->getNext();
            }
        }

        return current;
    }

};

#endif

