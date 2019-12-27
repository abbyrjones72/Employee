// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
using namespace Records;

int		displayMenu();
void	doHire(Database& inDB);
void	doFire(Database& inDB);
void	doPromote(Database& inDB);
void	doDemote(Database& inDB);

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employee" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "--->";

	cin >> selection;

	return selection;
}

void doHire(Database& inDB)
{
	string firstName;
	string lastName;

	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;

	try
	{
		inDB.addEmployee(firstName, lastName);
	}
	catch (std::exception ex)
	{
		cerr << "Unable to add new employee!" << endl;
	}
}

void doFire(Database& inDB)
{
	int employeeNumber;

	cout << "Employee number? ";
	cin >> employeeNumber;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " has been terminated." << endl;
	}
	catch (std::exception ex)
	{
		cerr << "Unable to terminate employee." << endl;
	}
}

void doPromote(Database& inDB)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;

	cout << "How much of a raise? ";
	cin >> raiseAmount;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (std::exception ex)
	{
		cerr << "Unable to promote employee." << endl;
	}
}

void doDemote(Database& inDB)
{
	int employeeNumber;
	int salaryAdjust;

	cout << "Employee number? ";
	cin >> employeeNumber;

	cout << "Salary adjustment? ";
	cin >> salaryAdjust;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(salaryAdjust);
	}
	catch (std::exception ex)
	{
		cerr << "Unable to demote employee." << endl;
	}
}

int main(int argc, char** argv)
{
	Database employeeDB;
	bool done = false;

	while (done != false)
	{
		int selection = displayMenu();

		switch (selection)
		{
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;
		case 7:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown command" << endl;
		}
	}
	return 0;
}