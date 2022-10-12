#include "Climb.h"

#include <iostream>

using namespace std;

ostream& operator<<(std::ostream& out, const Climb& aClimb)
{
    string difficultyWord;

    if (aClimb.difficulty == 'e')
    {
        difficultyWord = "easy";
    }
    else if (aClimb.difficulty == 'm')
    {
        difficultyWord = "moderate";
    }
    else
    {
        difficultyWord = "strenuous";
    }

    out << "\t" << aClimb.name << " (" << aClimb.location
        << ")\n\t  Difficulty: " << difficultyWord <<
        "\n\t  Duration: " << aClimb.duration << " day(s)" << endl;

    return out;
}

string Climb::getLocation() const
{
    return location;
}

string Climb::getName() const
{
    return name;
}

int Climb::getDuration() const
{
    return duration;
}

char Climb::getDifficulty() const
{
    return difficulty;
}

bool Climb::operator<(const Climb& paramClimb) const
{
    return (location < paramClimb.location);
}
