//20120454-Le Cong Dat
//Factory method
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
	string Name;
	double PaymentPerTime;
	double Time;
public:
	Employee() {
		Name = "";
		PaymentPerTime = 0;
		Time = 0;
	};
	void Input(string name, double paymentpertime, double time)
	{
		this->Name = name;
		this->PaymentPerTime = paymentpertime;
		this->Time = time;
	}
	double TotalPayment();
	virtual void printRes() = 0;
};
double Employee::TotalPayment()
{
	return PaymentPerTime * Time;
}
class DailyEmployee :public Employee
{
public:
	DailyEmployee() {};
	virtual void printRes()
	{
		cout << "DailyEmployee: " << this->Name << endl;
		cout << "DailyPayment= " << this->PaymentPerTime << "$" << endl;
		cout << "TotalDays= " << this->Time << "$" << endl;
		cout << "TotalPayment: " << this->TotalPayment() << "$" << endl << endl;
	}
};
class HourlyEmployee :public Employee
{
public:
	HourlyEmployee() {};
	virtual void printRes()
	{
		cout << "HourlyEmployee: " << this->Name << endl;
		cout << "HourlyPayment= " << this->PaymentPerTime << "$" << endl;
		cout << "TotalHours= " << this->Time << "$" << endl;
		cout << "TotalPayment: " << this->TotalPayment() << "$" << endl << endl;
	}
};
class ProductEmployee :public Employee
{
public:
	ProductEmployee() {};
	virtual void printRes()
	{
		cout << "ProductEmployee: " << this->Name << endl;
		cout << "PaymentPerProduct= " << this->PaymentPerTime << "$" << endl;
		cout << "TotalProducts= " << this->Time << "$" << endl;
		cout << "TotalPayment: " << this->TotalPayment() << "$" << endl << endl;
	}
};
class Manager
{
private:
	string Name;
	double FixedPayment;
	double TotalEmployees;
	double PaymentPerEmployee;
public:
	Manager() 
	{
		this->Name = "";
		this->FixedPayment = 0;
		this->TotalEmployees = 0;
		this->PaymentPerEmployee = 0;
	};
	void Input(string name, double fixedpayment, double totalemployees, double paymentperemployee)
	{
		this->Name = name;
		this->FixedPayment = fixedpayment;
		this->TotalEmployees = totalemployees;
		this->PaymentPerEmployee = paymentperemployee;
	}
	double TotalPayment()
	{
		return this->FixedPayment + this->PaymentPerEmployee * this->TotalEmployees;
	}
	void printRes()
	{
		cout << "Manager: " << this->Name << endl;
		cout << "FixedPayment= " << this->FixedPayment << "$"<<endl;
		cout << "TotalEmployees= " << this->TotalEmployees << endl;
		cout << "PaymentPerEmployee= " << this->PaymentPerEmployee << "$" << endl;
		cout << "TotalPayment: " <<this->TotalPayment()<< "$" << endl << endl;
	}
};
enum eEmployee
{
	Daily,
	Hourly,
	Product
};
class EmployeeFactory
{
public:
	EmployeeFactory() {};

	~EmployeeFactory() {};

	static Employee* createEmployee(eEmployee ID)
	{
		switch (ID)
		{
		case Daily:
		{
			return new DailyEmployee();
			break;
		}
		case Hourly:
		{
			return new HourlyEmployee();
			break;
		}
		case Product:
		{
			return new ProductEmployee();
			break;
		}
		default:
		{
			return NULL;
			break;
		}
		}
	}
};
int main()
{
	freopen("November2021.txt", "rt", stdin);
	Employee* e;
	Manager m;
	string temp1 = "", temp2="", temp3="";
	string name;
	double a, b, c;
	while (!feof(stdin))
	{
		cin >> temp1;
		getline(cin, temp2);
		if (temp1 == "DailyEmployee:")
		{
			e = EmployeeFactory::createEmployee(Daily);
			name = temp2;
			cin >> temp1 >> temp2;
			temp3 = "";
			int i = 0;
			for (i = 0; i < temp1.length(); i++)
				if (temp1[i] == '=')
					break;
			i++;
			for (int j = i; j < temp1.length(); j++)
				if (temp1[j] != '$') temp3 = temp3 + temp1[j];
				else break;
			a = stod(temp3);
			for (i = 0; i < temp2.length(); i++)
				if (temp2[i] == '=')
					break;
			i++;
			temp3 = "";
			for (int j = i; j < temp2.length(); j++)
				temp3 = temp3 + temp2[j];
			b = stod(temp3);
			e->Input(name, a, b);
			e->printRes();
		}
		else if (temp1 == "HourlyEmployee:")
		{
			e = EmployeeFactory::createEmployee(Hourly);
			name = temp2;
			cin >> temp1 >> temp2;
			temp3 = "";
			int i = 0;
			for (i = 0; i < temp1.length(); i++)
				if (temp1[i] == '=')
					break;
			i++;
			for (int j = i; j < temp1.length(); j++)
				if (temp1[j] != '$') temp3 = temp3 + temp1[j];
				else break;
			a = stod(temp3);
			for (i = 0; i < temp2.length(); i++)
				if (temp2[i] == '=')
					break;
			i++;
			temp3 = "";
			for (int j = i; j < temp2.length(); j++)
				temp3 = temp3 + temp2[j];
			b = stod(temp3);
			e->Input(name, a, b);
			e->printRes();
		}
		else if (temp1 == "ProductEmployee:")
		{
			e = EmployeeFactory::createEmployee(Product);
			name = temp2;
			cin >> temp1 >> temp2;
			temp3 = "";
			int i = 0;
			for (i = 0; i < temp1.length(); i++)
				if (temp1[i] == '=')
					break;
			i++;
			for (int j = i; j < temp1.length(); j++)
				if (temp1[j] != '$') temp3 = temp3 + temp1[j];
				else break;
			a = stod(temp3);
			for (i = 0; i < temp2.length(); i++)
				if (temp2[i] == '=')
					break;
			i++;
			temp3 = "";
			for (int j = i; j < temp2.length(); j++)
				temp3 = temp3 + temp2[j];
			b = stod(temp3);
			e->Input(name, a, b);
			e->printRes();
		}
		else if (temp1 == "Manager:")
		{
			name = temp2;
			cin >> temp1 >> temp2 >> temp3;
			string temp4 = "";
			int i = 0;
			for (i = 0; i < temp1.length(); i++)
				if (temp1[i] == '=')
					break;
			i++;
			for (int j = i; j < temp1.length(); j++)
				if (temp1[j] != '$') temp4 = temp4 + temp1[j];
				else break;
			a = stod(temp4);
			for (i = 0; i < temp2.length(); i++)
				if (temp2[i] == '=')
					break;
			i++;
			temp4 = "";
			for (int j = i; j < temp2.length(); j++)
				temp4 = temp4 + temp2[j];
			b = stod(temp4);
			for (i = 0; i < temp3.length(); i++)
				if (temp3[i] == '=')
					break;
			i++;
			for (int j = i; j < temp3.length(); j++)
				if (temp3[j] != '$') temp4 = temp4 + temp3[j];
				else break;
			c = stod(temp4);
			m.Input(name, a, b, c);
			m.printRes();
		}
	}
	return 0;
}