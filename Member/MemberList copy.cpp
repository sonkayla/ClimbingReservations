#include "MemberList.h"
#include <algorithm>
#include <iostream>

using namespace std;

void MemberList::addMember(const string& theFirstName,
    const string& theLastName)
{
    Member newMember(theFirstName, theLastName);

    if (memberList->empty())
    {
        newMember.setID(FIRST_MEMBER_ID);
        memberList->insert(newMember);
    }
    else
    {
        newMember.setID((memberList->rbegin()->getID()) + 1);
        memberList->insert(newMember);
    }
}

void MemberList::addMember(const std::string& theFirstName,
    const std::string& theLastName, int thePoints)
{
    Member newMember(theFirstName, theLastName);
    newMember.addPoints(thePoints);

    if (memberList->empty())
    {
        newMember.setID(FIRST_MEMBER_ID);
        memberList->insert(newMember);
    }
    else
    {
        newMember.setID((memberList->rbegin()->getID()) + 1);
        memberList->insert(newMember);
    }
}

int MemberList::getLastID() const
{
    return memberList->crbegin()->getID();

}

int MemberList::getPoints(int idNumber) const
{
    auto iterPointsToID = find_if(memberList->begin(),
        memberList->end(), [&idNumber](const auto& elem)
        {return elem.getID() == idNumber; });

    return iterPointsToID->getPoints();
}

void MemberList::printMember(int idNumber,
    const string& theLastName) const
{
    auto iterFindMember = find_if(memberList->begin(),
        memberList->end(), [&idNumber](const auto& elem)
        { return elem.getID() == idNumber; });

    if (iterFindMember->getLastName() == theLastName)
    {
        iterFindMember->printMember();
        cout << "\tMembership # " << idNumber << endl;
    }
}

void MemberList::clearList()
{
    memberList->clear();
}

MemberList::~MemberList()
{
    delete memberList;
    memberList = nullptr;
}
