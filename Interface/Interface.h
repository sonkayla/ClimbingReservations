#ifndef INTERFACE_H
#define INTERFACE_H

#include "ClimbList.h"
#include "MemberList.h"
#include "Reservation.h"

#include <iostream>

void displayMenu();

void processReservation(ClimbList& theClimbList, 
	MemberList& theMemberList, Reservations& theReservations);

void chooseByLocation(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

void chooseByDuration(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

void chooseByDifficulty(ClimbList& theClimbList, 
	MemberList& theMemberList, Reservations& theReservations);

void chooseByPrice(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

int askIfMember(MemberList& theMemberList);

int addNewMember(MemberList& theMemberList);

void makeReservation(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

void viewReservation(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

void cancelReservation(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

void askToReserve(ClimbList& theClimbList,
	MemberList& theMemberList, Reservations& theReservations);

#endif
