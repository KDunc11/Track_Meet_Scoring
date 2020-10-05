#ifndef FIELDPARTICIPANT_H
#define FIELDPARTICIPANT_H

#include "EventParticipant.h"

class FieldParticipant : public EventParticipant
{
public:
	//Constructor
	FieldParticipant();
	
	//Destructor
	~FieldParticipant();

	//Operator Overloading
	FieldParticipant operator=(const FieldParticipant &part); //Assignment Operator
	friend ostream& operator<<(ostream& ostrm, const FieldParticipant &part); //Insertion Operator

	//Public Member Functions
	const double getDistance();

private:
	//Private Member Variables
	double distance;

	//Private Member Functions
	double setDistance(double &dist);
};
#endif