#include "pch.h"
#include "TrackParticipant.h"

//Constructor
TrackParticipant::TrackParticipant()
{
	double time;

	cout << "Enter Participant's Time: ";
	cin >> time;

	while (time < 0 && time < 1000) //Time cannot be set less than zero or more than 1000 seconds or minutes
	{
		if (time < 0)
			cin >> time;
	}

	setTime(time);
	system("CLS");
}

//Destructor
TrackParticipant::~TrackParticipant()
{
	delete[] this; //Deallocates memory
}

//Operator Overloading
TrackParticipant TrackParticipant::operator=(const TrackParticipant &part)
{
	//Assigns the object's data from the object on the right side of the equals sign (=) to the 
	//data belonging to the object on the left side of the equal sign
	time = part.time;

	return *this; //returns the object left of the equals sign
}

ostream& operator<<(ostream &ostrm, const TrackParticipant &part)
{
	return ostrm << part; //Used to insert data from the object into the output stream
}

//Public Member Functions
const double TrackParticipant::getTime()
{
	return time; //Returns the value stored in the time private member variable
}

//Private Member Functions
double TrackParticipant::setTime(double &tm)
{
	time = tm;
	return time; //Sets the time variable
}