#ifndef CLIMB_H
#define CLIMB_H

#include <string>
#include <iostream>

class Climb
{
	friend std::ostream& operator<<(std::ostream& out,
		const Climb& aClimb);

public:
	Climb() : duration(0), difficulty('e') {}

	Climb(const std::string& aLocation, const std::string& aName,
		int theDuration, char theDifficulty) :
		location(aLocation), name(aName),
		duration(theDuration), difficulty(theDifficulty) {}

	std::string getLocation() const;

	std::string getName() const;

	int getDuration() const;

	char getDifficulty() const;

	bool operator<(const Climb& paramClimb) const;

	~Climb() {}

private:
	std::string location;
	std::string name;
	int duration;
	char difficulty;
};

#endif
