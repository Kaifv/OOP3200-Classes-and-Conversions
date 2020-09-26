#include "Ticket.h"
#include <iomanip>			
#include <iostream>
#include <sstream> 						
#include <stdexcept>		
#include <utility>


// class definition section

// Defining constructor with all the necessary parameters. 
WorkTicket::WorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, std::string clientID,
	std::string issueDescrip)
{
	SetWorkTicket(ticketNumber, ticketDay, ticketMonth, ticketYear, std::move(clientID), std::move(issueDescrip));
}

WorkTicket::WorkTicket(const WorkTicket& ticketobj)
{
	SetWorkTicket(ticketobj.GetNumber(), ticketobj.GetDay(), ticketobj.GetMonth(), ticketobj.GetYear(), ticketobj.GetID(), ticketobj.GetDescription());
}
//
//bool WorkTicket::operator==(const WorkTicket& another_number) const
//{
//	return (GetNumber() == another_number.GetNumber());
//}

//WorkTicket WorkTicket::operator=(const WorkTicket& other_ticket)
//{
//	SetNumber(other_ticket.GetNumber());
//	/*SetDay(other_ticket.GetDay());
//	SetMonth(other_ticket.GetMonth());
//	SetYear(other_ticket.GetYear());
//	SetID(other_ticket.GetID());
//	SetDescription(other_ticket.GetDescription());*/
//
//	return *this;
//}

// Defining SetWorkTicket function with its parameters and if all are valid then return true.
bool WorkTicket::SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, std::string clientID, std::string issueDescrip)
{

	SetNumber(ticketNumber);

	SetDay(ticketDay);

	SetMonth(ticketMonth);

	SetYear(ticketYear);

	SetID(std::move(clientID));

	SetDescription(issueDescrip);

	return true;
}

// Defining setter for ticket number which will validate the user input if it is in outside range.
void WorkTicket::SetNumber(int ticketNumber)
{
	if (ticketNumber > 0)
	{
		myticketNumber = ticketNumber;
	}
	else
	{
		throw std::invalid_argument("Error! Please enter positive whole number");
	}
}

// Defining setter for day attribute in date, so that it is always between 1 and 31.
void WorkTicket::SetDay(int ticketDay)
{
	if (ticketDay >= 1 && ticketDay <= 31)
	{
		myticketDay = ticketDay;
	}
	else
	{
		throw std::invalid_argument("Error! Please enter the day between 1 to 31");
	}
}

// Defining setter for month attribute in date, so that it is always between 1 and 12.
void WorkTicket::SetMonth(int ticketMonth)
{
	if (ticketMonth >= 1 && ticketMonth <= 12)
	{
		myticketMonth = ticketMonth;
	}
	else
	{
		throw std::invalid_argument("Error! Please enter the month between 1 to 12");
	}
}

// Defining setter for year attribute in date, so that it is always between 2000 and 2099.
void WorkTicket::SetYear(int ticketYear)
{
	if (ticketYear >= 2000 && ticketYear <= 2099)
	{
		myticketYear = ticketYear;
	}
	else
	{
		throw std::invalid_argument("Error! Please enter the Year between 2000 to 2099");
	}
}

// Defining setter for client ID, so that it's length is always 1 or more.
void WorkTicket::SetID(std::string clientId)
{
	myclientID = std::move(clientId);
}

// Defining setter for description, so that it's length is always 1 or more.
void WorkTicket::SetDescription(const std::string& issueDescrip)
{
	myissueDescrip = issueDescrip;
}

// Defining getter for ticket number.
int WorkTicket::GetNumber() const
{
	return myticketNumber;
}

// Defining getter for ticket day. 
int WorkTicket::GetDay() const
{
	return myticketDay;
}

// Defining getter for ticket month.
int WorkTicket::GetMonth() const
{
	return myticketMonth;
}

// Defining getter for ticket year. 
int WorkTicket::GetYear() const
{
	return myticketYear;
}

// Defining getter for client ID. 
std::string WorkTicket::GetID() const
{
	return myclientID;
}

// Defining getter for problem description. 
std::string WorkTicket::GetDescription() const
{
	return myissueDescrip;
}

// Defining getter to show the data in the proper format. 
std::string WorkTicket::ShowWorkTicket() const
{
	std::stringstream output;

	output << "Your ticket number is " << myticketNumber << " and your client ID is "
		<< myclientID << ". The problem you are facing is \"" << myissueDescrip << "\", and it was issued on the date "
		<< myticketDay << "/" << myticketMonth << "/" << myticketYear;

	return output.str();

}

//std::string WorkTicket::output() const
//{
//	std::stringstream result;
//
//	result << "(" << myticketNumber << ")";
//
//	return result.str();
//}
//
//std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket)
//{
//	out << ticket.output();
//	return out;
//}
//
//std::istream& operator>>(std::istream& in, WorkTicket ticket)
//{
//
//	in >> ticket.myticketDay;
//	if (ticket.myticketDay >= 1 && ticket.myticketDay <= 31)
//	{
//		in.ignore();
//		in >> ticket.myticketMonth;
//		if (ticket.myticketMonth >= 1 && ticket.myticketMonth <= 12)
//		{
//			in.ignore();
//			in >> ticket.myticketYear;
//			if (ticket.myticketYear >= 2000 && ticket.myticketYear <= 2099)
//			{
//				std::cout << "\n Input succesfull!";
//			}
//			else
//			{
//				std::cout << "\n Enter between 2000 and 2099";
//			}
//		}
//		else
//		{
//			std::cout << "\n Enter between 1 and 12";
//		}
//
//	}
//	else
//	{
//		std::cout << "\n Enter between 1 and 31";
//	}
//
//
//	return in;
//}