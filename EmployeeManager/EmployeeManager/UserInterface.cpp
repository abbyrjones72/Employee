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