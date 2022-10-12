#ifndef CLIMBLIST_H
#define CLIMBLIST_H

#include <map>
#include "Climb.h"

class ClimbList
{

public:
    ClimbList() : climbList() {}

    void addClimb(const Climb& aClimb, double price);

    void addClimb(const std::string& aLocation,
        const std::string& climbName, int theDuration,
        char theDifficulty, double price);

    double getPrice(const std::string& climbName) const;

    void printAllLocations() const;

    void printByLocation(const std::string& aLocation) const;

    void printByDuration() const;

    void printByDuration(int theDays) const;

    void printByDifficulty(char theDifficulty) const;

    void printByPrice() const;

    void printByClimbName(const std::string& climbName) const;

    void clearList();

private:
    std::multimap<Climb, double> climbList;
};

#endif

