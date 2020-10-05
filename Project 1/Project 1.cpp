#include "pch.h"
#include <iostream>
#include "EventParticipant.h"
#include "FieldParticipant.h"
#include "TrackParticipant.h"
#include <iomanip>

using namespace std;

void driver();

int main()
{
	driver();

	cout << "****Program Closed****" << endl;
	system("pause");
	return 0;
}

void driver()
{
	cout << "*********TRACK MEET INPUT SYSTEM*********" << endl;

	bool runDriver = true; //While true the system will continue to get new sets of entries, when false the driver function will stop
						   // and main will close out the program

	while (runDriver == true)
	{
		//Informs user of the limitations of the program and prompts the user to choose what to enter into the program
		cout << "\nThis program records up to 100 participants in an event." << endl;
		cout << "What type of event do you want to enter into the system?\n" << endl;
		cout << "Track Event (T) or Field Event (F): ";

		char decision;

		cin >> decision;

		if (decision == 't')
			decision = 'T';
		else if (decision == 'f')
			decision = 'F';
		else
			while (decision != 'F' && decision != 'T') //User must input a T, F, t, or f
			{
				system("CLS");
				cout << "\nInvaild response...Try again\n";
				cout << "What type of event do you want to enter into the system?\n" << endl;
				cout << "Track Event (T) or Field Event (F): ";
				cin >> decision;

				if (decision == 't')
					decision = 'T';
				else if (decision == 'f')
					decision = 'F';
			}

		int entryNum; //Lets the user determine how many participants to enter into the program

		cout << "\nEnter the Number of Participants to enter into the system (No more than 100): ";
		cin >> entryNum;

		while (entryNum <= 0 || entryNum > 100) //Prevents user from entering 0 or more than 100 entries
		{
			cout << "\nInvalid Response" << endl;
			cout << "\nEnter the Number of Participants to enter into the system (No more than 100): ";
			cin >> entryNum;
		}

		system("CLS");

		if (decision == 'T')
		{
			TrackParticipant *participant[100]; //Pointer to an array of track objects, up to 100 participants can be put into the array

			for (int i = 0; i < entryNum; i++)
				participant[i] = new TrackParticipant; //Allocates memory to create TrackParticipant objects up
													   //to the user defined number of entries

			cout << "All participant's information have been recorded." << endl;
			system("pause");
			system("CLS"); //Clears screen before pulling up a menu

			bool menu_open = true;

			while (menu_open == true) //Menu continues to run until user decides to exit the menu
			{
				cout << "1. Sort and Display Entries by Name\n" << "2. Sort, Score, and Display Entries by Time or Distance\n"
					<< "3. Enter New Set of Entries\n" << "0. Close Program\n\n" << "Enter a number from above: ";

				int menuNum;

				cin >> menuNum;

				while (menuNum < 0 && menuNum > 3)
					cin >> menuNum;

				if (menuNum == 1)
				{
					TrackParticipant *temp = nullptr; //Creates a temporary object to use while sorting the array

					for (int i = 0; i < entryNum; i++)
					{
						for (int j = 0; j < entryNum - i - 1; j++)
						{
							if (participant[j]->getName() > participant[j + 1]->getName())
							{
								//Used to sort the array (swap function)
								temp = participant[j];
								participant[j] = participant[j + 1];
								participant[j + 1] = temp;
								temp = nullptr;
							}
						}
					}
					delete temp;

					double time[3] = { 1000, 1000, 1000 }; //Used to Store the 3 Fastest Times

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < entryNum; j++)
						{
							if (participant[j]->getTime() < time[i])
							{
								//if-statement below checks if the time from index [j] is already in the array
								if (participant[j]->getTime() == time[0] || participant[j]->getTime() == time[1] || participant[j]->getTime() == time[2])
									continue;
								else
									time[i] = participant[j]->getTime(); //Stores the 3 fastest times
							}

						}
					}
					system("CLS");

					//Displays Header for each entry's information
					cout << "****Sorted Entries By Name****\n" << endl;
					cout << "****Name****" << setw(20) << "****Team****" << setw(20) << "****Gender****"
						<< setw(20) << "****Age****" << setw(20) << "****Time****" << endl;

					//Displays each object's information
					for (int i = 0; i < entryNum; i++)
					{
						cout << participant[i]->getName() << setw(20) << participant[i]->getTeam() << setw(20) << participant[i]->getGender()
							<< setw(20) << participant[i]->getAge() << setw(20) << participant[i]->getTime();

						//Used to score the times
						if (participant[i]->getTime() == time[0]) //First Place
							cout << setw(20) << "3" << endl;
						else if (participant[i]->getTime() == time[1]) //Second Place
							cout << setw(20) << "2" << endl;
						else if (participant[i]->getTime() == time[2]) //Third Place
							cout << setw(20) << "1" << endl;
						else
							cout << setw(20) << "0" << endl; //Anything after third place
					}
					system("pause");
					system("CLS");
				}
				else if (menuNum == 2)
				{
					TrackParticipant *temp = nullptr; //Creates a temporary object to use while sorting the array

					for (int i = 0; i < entryNum; i++)
					{
						for (int j = 0; j < entryNum - i - 1; j++)
						{
							if (participant[j]->getTime() > participant[j + 1]->getTime())
							{
								//Used to sort the array by time (swap function)
								temp = participant[j];
								participant[j] = participant[j + 1];
								participant[j + 1] = temp;
								temp = nullptr;
							}
						}
					}
					delete temp;

					system("CLS");

					//Displays Header for entry's information
					cout << "****Sorted Entries By Time****\n" << endl;
					cout << "****Name****" << setw(20) << "****Team****" << setw(20) << "****Gender****"
						<< setw(20) << "****Age****" << setw(20) << "****Time****" << setw(20) << "****Score****" << endl;

					int counter = 3; //Keeps track of the point value to assign

					for (int i = 0; i < entryNum; i++)
					{
						cout << participant[i]->getName() << setw(20) << participant[i]->getTeam() << setw(20) << participant[i]->getGender()
							<< setw(20) << participant[i]->getAge() << setw(20) << participant[i]->getTime() << setw(20) << counter << endl;

						if (counter > 0)
							counter--; //Decrements the place counter's point value
					}

					system("pause");
					system("CLS");
				}
				else if (menuNum == 3)
				{
					//Sets each object pointer to point to a nullptr so the participant array can be deallocated 
					for (int i = 0; i < 100; i++) 
						participant[i] = nullptr;			

					menu_open = false; //closes menu
					system("CLS");
				}
				else
				{
					menu_open = false; //closes menu
					runDriver = false; //closes driver function
					system("CLS");
				}
			}

		}
		else if (decision == 'F')
		{
			FieldParticipant *participant[100]; //Pointer to an array of field objects, up to 100 participants can be put into the array

			for (int i = 0; i < entryNum; i++)
			{
				participant[i] = new FieldParticipant; //Allocates memory to create FieldParticipant objects up 
												       //to the user defined number of entries
			}

			cout << "All participant's information have been recorded." << endl;
			system("pause");
			system("CLS"); //Clears screen before pulling up a menu

			bool menu_open = true;

			while (menu_open == true) //Menu continues to run until user decides to exit the menu
			{
				cout << "1. Sort and Display Entries by Name\n" << "2. Sort, Score, and Display Entries by Time or Distance\n"
					<< "3. Enter New Set of Entries\n" << "0. Close Program\n\n" << "Enter a number from above: ";

				int menuNum;

				cin >> menuNum;

				while (menuNum < 0 && menuNum > 3)
					cin >> menuNum;

				if (menuNum == 1)
				{
					FieldParticipant *temp = nullptr; //Creates a temporary object to use while sorting the array

					for (int i = 0; i < entryNum; i++)
					{
						for (int j = 0; j < entryNum - i - 1; j++)
						{
							if (participant[j]->getName() > participant[j + 1]->getName())
							{
								//Used to sort the array (swap function)
								temp = participant[j];
								participant[j] = participant[j + 1];
								participant[j + 1] = temp;
								temp = nullptr;
							}
						}						
					}
					delete temp;

					double dist[3] = { 0, 0, 0 }; //Array to store the 3 farthest distances
			
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < entryNum; j++)
						{
							if (participant[j]->getDistance() > dist[i])
							{
								//if-statement below checks if the time from index [j] is already in the array
								if (participant[j]->getDistance() == dist[0] || participant[j]->getDistance() == dist[1] || participant[j]->getDistance() == dist[2])
									continue;
								else
									dist[i] = participant[j]->getDistance(); //Stores the 3 farthest distances
							}		
						}
					}
					system("CLS");

					//Displays Header to entry's information
					cout << "****Sorted Entries By Name****\n" << endl;
					cout << "****Name****" << setw(20) << "****Team****" << setw(20) << "****Gender****"
						<< setw(20) << "****Age****" << setw(20) << "****Distance****"  << setw(20) << "****Score****" << endl;

					//Displays object's information
					for (int i = 0; i < entryNum; i++)
					{
						cout <<  participant[i]->getName()  << setw(20) << participant[i]->getTeam() << setw(20) << participant[i]->getGender()
							<< setw(20) << participant[i]->getAge() << setw(20) << participant[i]->getDistance();
						
						//Used to display the point value received based off distance
						if (participant[i]->getDistance() == dist[0]) //First place
							cout << setw(20) << "3" << endl;
						else if (participant[i]->getDistance() == dist[1]) //Second place
							cout << setw(20) << "2" << endl;
						else if (participant[i]->getDistance() == dist[2]) //Third place
							cout << setw(20) << "1" << endl;
						else
							cout << setw(20) << "0" << endl; //Anything less than third place
					}

					system("pause");
					system("CLS");
				}
				else if (menuNum == 2)
				{
					FieldParticipant *temp = nullptr; //Creates a temporary object to use while sorting the array

					for (int i = 0; i < entryNum; i++)
					{
						for (int j = 0; j < entryNum - i - 1; j++)
						{
							if (participant[j]->getDistance() < participant[j + 1]->getDistance())
							{
								//Used to sort the array by time (swap function)
								temp = participant[j];
								participant[j] = participant[j + 1];
								participant[j + 1] = temp;
								temp = nullptr;
							}
						}
					}
					delete temp;

					system("CLS");

					//Displays Header to entry's information
					cout << "****Sorted Entries By Distance****\n" << endl;
					cout << "****Name****" << setw(20) << "****Team****" << setw(20) << "****Gender****"
						<< setw(20) << "****Age****" << setw(20) << "****Distance****" << setw(20) << "****Score****" << endl;

					int counter = 3; //Keeps track of the point value to assign

					//Displays object's information
					for (int i = 0; i < entryNum; i++)
					{
						cout << participant[i]->getName() << setw(20) << participant[i]->getTeam() << setw(20) << participant[i]->getGender()
							<< setw(20) << participant[i]->getAge() << setw(20) << participant[i]->getDistance() << setw(20) << counter << endl;

						if (counter > 0)
							counter--; //Decrements the point value
					}
					system("pause");
					system("CLS");
				}
				else if (menuNum == 3)
				{
					//Sets each object pointer to point to a nullptr so the participant array can be deallocated 
					for (int i = 0; i < entryNum; i++)
						participant[i] = nullptr;

					menu_open = false; //closes menu
					system("CLS");
				}
				else
				{
					menu_open = false; //closes menu
					runDriver = false; //closes driver function
					system("CLS");
				}
			}
		}
	}
}