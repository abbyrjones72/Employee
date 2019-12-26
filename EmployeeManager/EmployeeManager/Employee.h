// Employee.h

#include <iostream>

namespace Records
{
	const int kDefaultStartingSalary = 30000;
	class Employee
	{
	public:
		Employee();
		~Employee();

		void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire();
		void fire();
		void display();

		// gets and sets

		void		setFirstName(std::string inFirstName);
		std::string getFirstName();
		void		setLastName(std::string inLastName);
		std::string getLastName();
		void		setEmployeeNumber(int inEmployeeNumber);
		int			getEmployeeNumber();
		void		setSalary(int inNewSalary);
		int			getSalary();
		bool		getIsHired();

	private:
		std::string m_firstName;
		std::string m_lastName;
		int m_employeeNumber;
		int m_salary;
		bool m_isHired;
	};
}