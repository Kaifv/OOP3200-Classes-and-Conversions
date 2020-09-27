/*
* This is the main.cpp file for the WorkTicket vs file for lab 1. In this file we will add the functionality for the basic work ticket environment, which will store the
* ticket number, date, id, name of the customer and the problem caused to them. We will be modifying the existing code to corporate the functionality of
* function overloading. We will define some of the built-in and also some other function and overload them as we want them to work.
*
* Developer Name: Kaifkhan Vakil
* Student Id: 100772820.
* Date: 24th September, 2020.
*
*/

// Including all the libraries that will be helpful in the code. 
#include <iostream>
#include <iomanip>			
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()
#include "Ticket.h"

using namespace std;


// main function
int main()
{
	// Declaration section for the main function.
	WorkTicket arr[3]; // Array of objects in the class to store the objects.
	int inputNumber; // Input for ticket number. 
	int inputday, inputMonth, inputYear; //input for date.
	string inputID; // input client ID.
	string inputDescrip; //input for description.
	int i = 0; // initialization of integer for while loop.

	// Noting the user to enter the information as asked. 
	std::cout << "Enter the information as prompted: " << endl;

	// Starting of the while loop.
	while (i < 3)
	{
		// Try and catch method for the input.	
		try
		{
			// Prompting to enter the ticket number, with validation through consoleinput class. 
			std::cout << "Enter the ticket number: ";
			inputNumber = ConsoleInput::ReadInteger(1);
			arr[i].SetNumber(inputNumber);


			// Prompting the user to enter the client ID.
			std::cout << "Enter the Client ID: ";
			cin >> inputID;
			arr[i].SetID(inputID);


			// Prompting the user to enter the date of their information. 
			std::cout << "Enter the date, you will be prompted to enter day, month and year individually.\n";
			std::cout << "Enter the day: ";
			inputday = ConsoleInput::ReadInteger(1, 31);
			arr[i].SetDay(inputday);

			std::cout << "Enter the month: ";
			inputMonth = ConsoleInput::ReadInteger(1, 12);
			arr[i].SetMonth(inputMonth);

			std::cout << "Enter the year: ";
			inputYear = ConsoleInput::ReadInteger(2000, 2099);
			arr[i].SetYear(inputYear);

			// Prompting the user to write the description of their problem. 
			std::cout << "Write the brief description of the problem: ";
			cin >> inputDescrip;
			arr[i].SetDescription(inputDescrip);
			cout << endl;
			i++;
		}
		// We will catch the exception if any of the input values stands out the validation parameters.
		catch (const exception& ex)
		{
			cerr << ex.what() << " Ending the program." << endl;
			i--;
		}

	}
	WorkTicket other_ticket = arr[1].GetNumber();

	cout << "\n A WorkTicket object was ASSIGNED";

	cout << "\nA WorkTicket object has been copied.";

	std::cout << endl << endl;

	//Now we will show the entered data by the user using a for loop.
	std::cout << "You entered the noted below information, please check.\n" << endl;
	for (int y = 0; y < 3; y++)
	{
		std::cout << "Your ticket number: " << arr[y].GetNumber() << endl;
		std::cout << "Your entered client ID: " << arr[y].GetID() << endl;
		std::cout << "Your entered date: " << arr[y].GetDay() << "/" << arr[y].GetMonth() << "/" << arr[y].GetYear() << endl;
		std::cout << "Your entered description: " << arr[y].GetDescription() << endl;

		std::cout << endl;
	}

	cout << "\n Are both the ticket numbers same?: " << std::to_string(arr[0].GetNumber() == arr[1].GetNumber()) << std::endl;

	WorkTicket anotherDate;

	cout << "\n Enter another ticket date: ";
	cin >> anotherDate;


	return 0;
} //end of main function.
