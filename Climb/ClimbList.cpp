#include "ClimbList.h"
#include <algorithm>
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

void ClimbList::addClimb(const Climb& aClimb, double price)
{
    climbList.insert(make_pair(aClimb, price));
}

void ClimbList::addClimb(const string& aLocation,
    const string& climbName, int theDuration, char theDifficulty,
    double price)
{
    Climb newClimb(aLocation, climbName, theDuration, theDifficulty);

    climbList.insert(make_pair(newClimb, price));
}

double ClimbList::getPrice(const std::string& climbName) const
{
    auto climbIter = find_if(climbList.begin(), climbList.end(),
        [&climbName](pair<Climb, double> aClimb)
        { return aClimb.first.getName() == climbName; });
    return climbIter->second;
}

void ClimbList::printAllLocations() const
{
    auto climbIter = climbList.begin();
    auto climbIterEnd = climbList.end();
    string currentLocation;

    while (climbIter != climbIterEnd)
    {
        cout << "\t" << climbIter->first.getLocation() << endl;
        climbIter = climbList.upper_bound(climbIter->first);
    }

    cout << endl;
}

void ClimbList::printByLocation(const string& aLocation) const
{
    auto climbIter = find_if(climbList.begin(), climbList.end(),
        [&aLocation](pair<Climb, double> aClimb)
        {return aClimb.first.getLocation() == aLocation; });

    while (climbIter->first.getLocation() == aLocation)
    {
        cout << climbIter->first << "\t  Price (per person): $ "
            << fixed << showpoint << setprecision(2)
            << climbIter->second << "\n\n";

        climbIter++;
    }
}

void ClimbList::printByDuration() const
{
    multimap<int, string> tempMultiMap;

    for (const auto& climbIter : climbList)
    {
        tempMultiMap.insert(make_pair(
            climbIter.first.getDuration(),
            climbIter.first.getLocation()));
    }

    for_each(tempMultiMap.begin(), tempMultiMap.end(),
        [](pair<int, string> aPair) {cout << "\t (" << aPair.first
        << ") " << aPair.second << endl; });

    cout << endl;
}

void ClimbList::printByDuration(int theDuration) const
{

    for (const auto& climbListIter : climbList)
    {
        if (climbListIter.first.getDuration() == theDuration)
        {
            cout << climbListIter.first << endl;
        }
    }
}

void ClimbList::printByDifficulty(char theDifficulty) const
{
    for (const auto& climbIter : climbList)
    {
        if (climbIter.first.getDifficulty() == theDifficulty)
        {
            cout << "\t(" << climbIter.first.getDifficulty() << ") "
                << climbIter.first.getName() << ", "
                << climbIter.first.getLocation() << endl;
        }
    }

    cout << endl;
}

void ClimbList::printByPrice() const
{
    multimap<double, pair<string, string>> tempMultiMap;

    for (const auto& climbIter : climbList)
    {
        tempMultiMap.emplace(climbIter.second,
            make_pair(climbIter.first.getLocation(),
                climbIter.first.getName()));
    }

    for (const auto& tempIter : tempMultiMap)
    {
        cout << "\t  $ " << fixed << showpoint << setprecision(2)
            << setw(7) << tempIter.first << " - "
            << tempIter.second.first << " ("
            << tempIter.second.second << ")" << endl;
    }

    cout << endl;

}

void ClimbList::printByClimbName(const string& climbName) const
{
    auto climbIter = find_if(climbList.begin(), climbList.end(),
        [&climbName](pair<Climb, double> aClimb)
        {return aClimb.first.getName() == climbName; });

    cout << climbIter->first << "\t  $" <<
        fixed << showpoint << setprecision(2) << climbIter->second
        << endl;

    cout << endl;
}

void ClimbList::clearList()
{
   climbList.clear();
}
