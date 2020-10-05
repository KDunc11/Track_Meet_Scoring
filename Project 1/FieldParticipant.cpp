#include "pch.h"
#include "FieldParticipant.h"

//Constructor
FieldParticipant::FieldParticipant()
{
	double distance;

	cout << "Enter Participant's Distance (in meters): ";
	cin >> distance;
	
	while (distance < 0 || distance > 200) //Distance cannot be set less than zero or more than 200 meters
	{
		if (distance < 0 || distance > 200)
			cin >> distance;
	}

	setDistance(distance);
	system("CLS");
}

//Destructor
FieldParticipant::~FieldParticipant()
{
	delete[] this; //Deallocates memory
}

//Operator Overloading
FieldParticipant FieldParticipant::operator=(const FieldParticipant &part)
{
	//Assigns the object's data from the object on the right side of the equals sign (=) to the 
	//data belonging to the object on the left side of the equal sign
	distance = part.distance;
	
	return *this; //returns the object left of the equals sign
}

ostream& operator<<(ostream& ostrm, const FieldParticipant &part)
{
	return ostrm << part; //Used to insert data from the object into the output stream
}

//Public Member Functions
const double FieldParticipant::getDistance()
{
	return distance; //returns value stored in object's distance variable
}

//Private Member Functions
double FieldParticipant::setDistance(double &dist)
{
	distance = dist;
	return distance; //Sets the Distance variable
}
