#ifndef TRACKPARTICIPANT_H
#define TRACKPARTICIPANT_H

#include "EventParticipant.h"

class TrackParticipant : public EventParticipant
{
public:
	//Constructor
	TrackParticipant();
	
	//Destructor
	~TrackParticipant();

	//Operator Overloading
	TrackParticipant operator=(const TrackParticipant &part);
	friend ostream& operator<<(ostream &ostrm, const TrackParticipant &part);

	//Public Member Variables
	const double getTime();

private:
	//Private Member Varibles
	double time;

	//Private Member Function
	double setTime(double &tm);
};
#endif