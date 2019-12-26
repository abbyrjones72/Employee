// Database.cpp
#include "Database.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace Records
{
	Database::Database()
	{
		m_nextSlot = 0;
		m_nextEmployeeNumber = kFirstEmployeeNumber;
	}

	Database::~Database()
	{
		// nothing to do
	}

	int i = 0;

	// fills in the next blank employee with actual information
	Employee& Database::addEmployee(string inFirstName, string inLastName)
	{
		// sanity check; if greater than max capacity, throw error
		if (m_nextSlot >= kMaxEmployees)
		{
			cerr << "There is no more room to add the new employees." << endl;
			throw exception();
		}

		// assign the next location in the array to theEmployee
		Employee& theEmployee = m_Employee[m_nextSlot++];
		theEmployee.setFirstName(inFirstName);
		theEmployee.setLastName(inLastName);

		// increment the employee number and set to current employee (this is an ID field)
		theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
		theEmployee.hire();

		return theEmployee;
	}

	Employee& Database::getEmployee(int inEmployeeNumber)
	{
		for (; i < m_nextEmployeeNumber; i++)
		{
			if (m_Employee[i].getEmployeeNumber() == inEmployeeNumber)
			{
				return m_Employee[i];
			}
		}
		cerr << "No employee with employee number " << inEmployeeNumber << endl;
		throw exception();
	}

	// overloaded by firstname and lastname
	Employee& Database::getEmployee(string inFirstName, string inLastName)
	{
		for (; i < m_nextSlot; i++)
		{
			if (m_Employee[i].getFirstName() == inFirstName && m_Employee[i].getLastName() == inLastName)
			{
				return m_Employee[i];
			}
		}
		cerr << "No employee with name " << inLastName << ", " << inFirstName << endl;
		throw exception();
	}

	void Database::displayAll()
	{
		for (; i < m_nextSlot; i++)
		{
			m_Employee[i].display();
		}
	}

	void Database::displayCurrent()
	{
		for (; i < m_nextSlot; i++)
		{
			if (m_Employee[i].getIsHired())
			{
				m_Employee[i].display();
			}
		}
	}

	void Database::displayFormer()
	{
		for (; i < m_nextSlot; i++)
		{
			if (m_Employee[i].getIsHired() == false)
			{
				m_Employee[i].display();
			}
		}
	}
}
