#ifndef EVENTPARTICIPANT_H
#define EVENTPARTICIPANT_H

#include <iostream>
#include <string>

using namespace std;

class EventParticipant
{
public:
	//Constructor
	EventParticipant();

	//Destructor
	~EventParticipant();

	//Operator Overloading
	EventParticipant operator=(const EventParticipant &part); //Assignment Operator
	friend ostream& operator<<(ostream &ostrm, const EventParticipant &rval); //Insertion Operator

	//Accessor Functions
	const string getName(); //To set the participant's name
	const int getAge(); //To set the participant's age
	const char getGender(); //To set the participant's gender
	const string getTeam(); //To set the participant's team name

	//Public Member Variables
	int numOfParticipants;

private:
	//Private Member Variables
	string name;
	int age;
	char gender;
	string team;

	//Private Member Functions
	string setName(string &partName);
	int setAge(int &partAge);
	char setGender(char &partGender);
	string setTeam(string &partTeam);
};
#endif