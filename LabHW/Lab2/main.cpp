#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Employee {
private:
    int Line;
    vector<string> name;
    vector<string> salary;
    vector<string> bonus;
    int nameSize;
    int salarySize;
    int bonusSize;

public:
    Employee(int line) : Line(line) {
        nameSize = 0;
        salarySize = 0;
        bonusSize = 0;
    }

    void initEmployee() {
        for (int l = 0; l < Line; l++) {
            string nameStr, salaryStr, bonusStr;
            cin >> nameStr >> salaryStr >> bonusStr;
            name.push_back(nameStr);
            salary.push_back(salaryStr);
            bonus.push_back(bonusStr);

            if (nameSize < nameStr.size())
                nameSize = nameStr.size();
            if (salarySize < salaryStr.size())
                salarySize = salaryStr.size();
            if (bonusSize < bonusStr.size())
                bonusSize = bonusStr.size();
        }
    }

    void printEmployeeInfo() {
        for (int l = 0; l < Line; l++) {
            cout << setw(nameSize) << name[l] << "|";
            cout << setw(salarySize + 2) << salary[l] << "|";
            cout << setw(bonusSize + 2) << bonus[l] << endl;
        }
    }
};

int main() {
	int Line;
	while (cin >> Line) {
		Employee employee(Line);
		employee.initEmployee();
		employee.printEmployeeInfo();
	}
}

/*
Alexandrescu|  20000000|  99999
	   Frank|    100000|     50
		Andy|         1|      1
*/
