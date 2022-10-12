/*
   HuySon

   Huynh, Julie
   Son, Kayla

   Spring 2022
   CS A250 - C++ 2
   Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <set>
#include <string>
#include "Member.h"

const int FIRST_MEMBER_ID = 111;

class MemberList
{
public:
    MemberList() : memberList(new std::set<Member>) {}

    void addMember(const std::string& theFirstName,
        const std::string& theLastName);

    void addMember(const std::string& theFirstName,
        const std::string& theLastName, int thePoints);

    int getLastID() const;

    int getPoints(int idNumber) const;

    void printMember(int idNumber,
        const std::string& theLastName) const;

    void clearList();

    ~MemberList();
private:
    std::set<Member>* memberList;
};

#endif


