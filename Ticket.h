#pragma once
#ifndef  _TICKET_
#define TICKET

#include <string>

// class declaration section 
class WorkTicket
{
	// Private attributes are added to the class along with their proper datatypes.
private:
	int myticketNumber{};
	int myticketDay{};
	int myticketMonth{};
	int myticketYear{};
	std::string myclientID;
	std::string myissueDescrip;

	// Public section of the class which will be available outside of the class also. 
public:


	//Constructor - Parameterized constructor is the default value for the data entry of the attributes in the file whenever the input is not entered or
	//proper. 
	WorkTicket(int myticketNumber = 1, int myticketDay = 1, int myticketMonth = 1, int myticketYear = 2000, std::string myclientID = "", std::string myissueDescrip = "");

	/*copy costructor*/
	WorkTicket(const WorkTicket& ticketobj);

	///* Operator overloads */
	bool operator==(const WorkTicket& another_number) const;
	WorkTicket operator=(const WorkTicket& other_ticket);
	operator std::string() const;


	///* Friend overloads */
	//friend std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket);
	//friend std::istream& operator>>(std::istream& in, WorkTicket ticket);


	// Accesors(getters) - This are the getters function which will be useful in displaying the values of the attributes in the console window. Getter function
	//for each of the member of the attribute is added down below.
	int GetNumber() const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	std::string GetID() const;
	std::string GetDescription() const;
	std::string ShowWorkTicket() const;
	/*std::string output() const;*/



	// Mutators(setters) - These the setters function which will manipulate the input in the attributes. Setter function for each of the attribute is added.:
	void SetNumber(int ticketNumber);
	void SetDay(int ticketDay);
	void SetMonth(int ticketMonth);
	void SetYear(int ticketYear);
	void SetID(std::string clientID);
	void SetDescription(const std::string& issueDescrip);
	bool SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, std::string clientID, std::string issueDescrip);


};// end of class WorkTicket.

#endif
