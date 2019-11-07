// EmployeePaycheck.cpp : Defines the entry point for the console application.
//Nile Weadick

#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "string"
#include "fstream"

using namespace std;

int main()
{

// Declare Variables

	string name, choice;
	float hourlyWage, hoursWorked;
	double earned, overTime, overTimeHours, bonus, FICA, fedTax, stateTax, netPay, deductions;
	
	

// Input 

	/* in */

	// Get name and wage

	cout <<  "Employee name? "; 
	cin >> name;

	cout << "Hourly Rate? ";
	cin >> hourlyWage;

	// Accept only hourly rates between 5.50 and 200.00.  Force the user to reenter an hourly rate until it is in range.

	while (hourlyWage < 5.50 || hourlyWage > 200.00)
		{
			cout << "Hourly rate must be betweeen 5.50 and 200.00";
			cout << endl << "Please reenter an hourly rate ";
			cin >> hourlyWage;
		} 

	/* in */

	cout << "Hours worked? ";
	cin >> hoursWorked;

	// Accept only hours worked between 0.0 and 60.0 without a warning cross check. 

	if (hoursWorked < 0.0 || hoursWorked > 60.0)
		{
			cout << "Hours worked must be betweeen 0.0 and 60.0";

			//If hours are greater than 60.0 ask the user to override the 60 hour limit.

			cout << endl << "Do you wish to override? (Choose yes or no) ";

			/* in */
			// The user may override the limit and use a value out of range or renter a value
			// The final value entered must either be within range, or overridden
	
			cin >> choice;

			if (choice == "yes")
			{
				// Do nothing and continue
			}

			while (choice == "no")
			{
				cout << "Please reenter hours worked ";
				cin >> hoursWorked;
			}
	}

	cout << endl << "***********************************************************" << endl << endl;

	earned = hourlyWage * hoursWorked;

	// Calculate overtime and total earned
	
	if (hoursWorked > 40)
	{
		overTimeHours = hoursWorked - 40;
		bonus = hourlyWage * 1.5;
		overTime = overTimeHours * bonus;
		earned = hourlyWage * 40 + overTime;
	}

	if (hoursWorked < 40)
	{
		earned = hourlyWage * hoursWorked;
	}

	FICA = earned * .0765;

	if (earned < 1500)
	{
		fedTax = earned * .022;
	}

	if (earned > 1500)
	{
		fedTax = earned *.028;
	}

	stateTax = earned * 0.12;
	deductions = FICA + fedTax + stateTax;
	netPay = earned - deductions;

	// Output

	/* out */

	cout << fixed << showpoint << setprecision(2) ;
	cout << name << " earned $" << earned << endl ;
	cout << "FICA $" << FICA << endl;
	cout << "Fed $" << fedTax << endl;
	cout << "State tax $" << stateTax << endl;

	//Flag any net pay in excess of $10,000 with the “(out of normal range)” warning.

	if (netPay > 10000)
	{
		cout << "Net pay $" << netPay << " (OUT OF NORMAL RANGE)" << endl;
	}
	if (netPay < 10000)
	{
		cout << "Net pay $" << netPay << endl;
	}

	// freeze screen 

	string junk;
	cout << endl << "Hit any key to continue...";
	cin >> junk;
	return (0);
}

