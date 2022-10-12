class Member
{

public:
	Member() : id(0), points(0) {}

	Member(const std::string& theFirstName,
		const std::string& theLastName) : firstName(theFirstName),
		lastName(theLastName), id(0), points(0) {}

	void addPoints(int thePoints);

	void setID(int idNumber);

	int getID() const;

	std::string getLastName() const;

	int getPoints() const;

	void printMember() const;

	bool operator<(const Member& paramMember) const;

private:
	int id;
	std::string firstName;
	std::string lastName;
	int points;
};

#endif
