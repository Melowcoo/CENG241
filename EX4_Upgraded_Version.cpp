#include <iostream>
using namespace std;

class Employee {
private:
    int employeeID;
    double hourlyWage, hoursWorked, salary;

public:
    void input(int employeeID, double hourlyWage, double hoursWorked) {
        this->employeeID = employeeID;
        this->hourlyWage = hourlyWage;
        this->hoursWorked = hoursWorked;
    }

    void calculateSalary() {
        this->salary = hourlyWage * hoursWorked;
    }

    ~Employee() {
        cout << "Salary of ID " << employeeID << " is " << salary << endl;
    }
};

int main() {
    int n;
    const int rule_UpTo_50 = 50; // Fixed missing semicolon

    cout << "Enter number of employees (up to " << rule_UpTo_50 << "): ";
    cin >> n;

    if (n < 1 || n > rule_UpTo_50) {
        cout << "Invalid number of employees." << endl;
        cout << "Setting number of employees to MAX(" << rule_UpTo_50 << ")" << endl;
        n = rule_UpTo_50;
    }

    Employee* obj = new Employee[n];

    int id = 0;
    double wage = 0.0, hours = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "Input ID, hourly wage, hours worked: ";
        cin >> id >> wage >> hours;

        obj[i].input(id, wage, hours);
        obj[i].calculateSalary();
    }

    delete[] obj;

    return 0;
}
