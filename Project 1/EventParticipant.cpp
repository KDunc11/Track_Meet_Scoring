#include "pch.h"
#include "EventParticipant.h"
#include <iomanip>


//Constructor
EventParticipant::EventParticipant()
{
	string name;
	int age;
	char gender;
	string team;

	cout << "Enter Participant's Name (Last Name,First Initial) [No Spaces]: ";
	cin >> name;
	setName(name);

	cout << "Enter Participant's Age: ";
	cin >> age;
	setAge(age);

	cout << "Enter Participant's Gender (M for Male, F for Female): ";
	cin >> gender;
	setGender(gender);

	cout << "Enter Participant's Team Name (No Spaces): ";
	cin >> team;
	setTeam(team);

	numOfParticipants++; //Accounts for another participant being added into the array
}

//Destructor
EventParticipant::~EventParticipant()
{	
	delete[] this; //Deallocates memory
}


EventParticipant EventParticipant::operator=(const EventParticipant &part)
{
	//Assigns the object's data from the object on the right side of the equals sign (=) to the 
	//data belonging to the object on the left side of the equal sign
	name = part.name;
	age = part.age;
	gender = part.gender;
	team = part.team;

	return *this; //returns the object left of the equals sign
}

ostream& operator<<(ostream &ostrm, const EventParticipant &rval)
{
	return ostrm << rval; //Used to insert data from the object into the output stream
}

//Acessor Functions
const string EventParticipant::getName()
{
	return name; //Returns string stored in name
}

const int EventParticipant::getAge()
{
	return age; //Returns value stored in name
}

const char EventParticipant::getGender()
{
	return gender; //Returns character stored in name
}

const string EventParticipant::getTeam()
{
	return team; //Returns string stored in name
}

//Private Member Functions
string EventParticipant::setName(string &partName)
{
	return name = partName; //Assigns user specified name to the object's name variable
}

int EventParticipant::setAge(int &partAge)
{
	if (partAge <= 0 || partAge > 100)
	{
		while (partAge <= 0 || partAge > 100) //prevents user from entering an age less than 1 or 100 or above
		{
			cout << "Nice try, try again./n" << endl;
			cout << "Enter Participant's Age: ";
			cin >> partAge;
		}
	}
	
	return age = partAge; //Assigns user specified age to the object's age variable
}

char EventParticipant::setGender(char &partGender)
{
	if (partGender == 'm')
		partGender = 'M';

	else if (partGender == 'f')
		partGender = 'F';

	else
		while (partGender != 'M' && partGender != 'F')
			cin >> partGender;

	return gender = partGender; //Assigns user specified gender to the object's gender variable
}

string EventParticipant::setTeam(string &partTeam)
{
	return team = partTeam; //Assigns user specified team name to the object's team variable
}