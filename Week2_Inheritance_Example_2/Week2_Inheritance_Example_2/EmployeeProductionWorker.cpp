/*
 Program Name: EmployeeProductionWorker.cpp
 Programmer: Moris Gomez
 Date: Saturday 02/17/2024
 Version Control: 3.0
 About: Week 2, CSCI 2, Lab.
 Description:
 Create a class Employee with a sub class Production Worker.
*/



#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Employee
{
protected:
    string employeeName;
    string employeeNumber;
    string employeeHireDate;
    
public:
    //default constructor:
    Employee()
    {
        employeeName = "Jon Doe";
        employeeNumber = "000";
        employeeHireDate = "00/00/0000";
    }
    
    //constructor w/ 3 arg:
    Employee(string name, string number, string date)
    {
        employeeName = name;
        employeeNumber = number;
        employeeHireDate = date;
    }
    
    //getters:
    string getName()
    {
        return employeeName;
    }
    string getNumber()
    {
        return employeeNumber;
    }
    string getDate()
    {
        return employeeHireDate;
    }
    
    //setters:
    void setName(string nam)
    {
        employeeName = nam;
    }
    void setNumber(string num)
    {
        employeeNumber = num;
    }
    void setDate(string dat)
    {
        employeeHireDate = dat;
    }
}; //end parent class Employee.

/// 
///
///
///

class ProductionWorker : public Employee
{
private:
    int employeeShift;
    double employeeHourly;
    
public:
    //default constructor:
    ProductionWorker()
    {
        employeeShift = 0;
        employeeHourly = 0.0;
        Employee();
        //inherits default constructor name, number, date.
    }
    
    //constructor w/ 4 arg:
    ProductionWorker(string name, string number, string date, int shift, double hourly):Employee(name, number, date)
    {
        employeeShift = shift;
        employeeHourly = hourly;
    }
    
    //getters:
    int getShift()
    {
        return employeeShift;
    }
    int getHourly()
    {
        return employeeHourly;
    }
    
    //setters:
    void setShift(int s)
    {
        employeeShift = s;
    }
    void setHourly(double h)
    {
        employeeHourly = h;
    }
    
    //other functions:
    double calcSalary()
    {
        return employeeHourly * 40;
    }
    void display()
    {
        cout << "employee first name: " << employeeName << endl;
        cout << "employee number: " << employeeNumber << endl;
        cout << "employee hire date: " << employeeHireDate << endl;
        
        if (employeeShift == 1)
        {
            cout << "employee shift: daytime" << endl;
        }
        else if (employeeShift == 2)
        {
            cout << "employee shift: nighttime" << endl;
        }
        else
        {
            cout << "error: enter 1 or 2 for shift." << endl;
        }
        cout << "employee hourly pay: $" << employeeHourly << endl;
        cout << "your salary for a 40 hour work week is: $" << fixed << setprecision(2) << calcSalary() << endl;
    }
    
}; //end sub class ProductionWorker.

int main()
{
    string name;
    cout << "first name:";
    cin >> name;
    
    string number;
    cout << "employee number:";
    cin >> number;
    
    string date;
    cout << "hire date:";
    cin >> date;
    
    int shift;
    cout << "shift (day = 1 & night = 2):";
    cin >> shift;
    
    double pay;
    cout << "hourly pay:";
    cin >> pay;
    
    ProductionWorker userOne(name, number, date, shift, pay);
    cout << endl << "YOUR INFORMATION:" << endl << "-------------------" << endl;
    userOne.display();
    return 0;
}
