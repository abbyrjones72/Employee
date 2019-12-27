// DatabaseTest.cpp
#include <iostream>
#include "Database.h"

using namespace std;
using namespace Records;

int main(int argc, char** argv)
{
	Database db;
	
	Employee& emp1 = db.addEmployee("Abby", "Jones");
	emp1.fire();

	Employee& emp2 = db.addEmployee("Someone", "Better");
	emp2.hire();
	emp2.setSalary(100000);

	Employee emp3 = db.addEmployee("Joan", "OfArc");
	emp3.setSalary(122102);
	emp3.promote();

	cout << "all employees: " << endl;
	cout << endl;
	db.displayAll();

	cout << "current employees" << endl;
	cout << endl;
	db.displayCurrent();

	cout << "former employees" << endl;
	cout << endl;
	db.displayFormer();
	   
	return 0;
}