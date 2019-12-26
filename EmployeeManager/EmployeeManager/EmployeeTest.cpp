// EmployeeTest.cpp

#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main(int argc, char** argv)
{
	cout << "Testing the Employee class." << endl;

	Employee emp;

	emp.setFirstName("Abby");
	emp.setLastName("Jones");
	emp.setEmployeeNumber(-1);
	emp.setSalary(50000);
	emp.promote(1);
	emp.promote(50);
	emp.hire();
	emp.display();

	return 0;
}