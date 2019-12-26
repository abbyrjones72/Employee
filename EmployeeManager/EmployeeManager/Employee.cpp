// Employee.cpp
#include <iostream>
#include "Employee.h"
using namespace std;

namespace Records
{
	Employee::Employee()
	{
		m_firstName = "";
		m_lastName = "";
		m_employeeNumber = -1;
		m_salary = kDefaultStartingSalary;
		m_isHired = false;
	}

	Employee::~Employee()
	{
		// do nothing
	}

	void Employee::promote(int inRaiseAmount)
	{
		setSalary(getSalary() + inRaiseAmount);
	}

	void Employee::demote(int inDemeritAmount)
	{
		setSalary(getSalary() - 1000);
	}

	void Employee::hire()
	{
		m_isHired = true;
	}

	void Employee::fire()
	{
		m_isHired = false;
	}

	void Employee::display()
	{
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << (m_isHired ? "Current Employee" : "Former Employee") << endl; // is this ternary?
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

	// gets and sets

	void Employee::setFirstName(std::string inFirstName)
	{
		m_firstName = inFirstName;
	}

	std::string Employee::getFirstName()
	{
		return m_firstName;
	}

	void Employee::setLastName(std::string inLastName)
	{
		m_lastName = inLastName;
	}

	std::string Employee::getLastName()
	{
		return m_lastName;
	}

	void Employee::setEmployeeNumber(int inEmployeeNumber)
	{
		m_employeeNumber = inEmployeeNumber;
	}

	int Employee::getEmployeeNumber()
	{
		return m_employeeNumber;
	}

	void Employee::setSalary(int inNewSalary)
	{
		m_salary = inNewSalary;
	}

	int Employee::getSalary()
	{
		return m_salary;
	}

	bool Employee::getIsHired()
	{
		return m_isHired;
	}
};