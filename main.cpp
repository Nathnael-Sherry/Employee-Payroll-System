
#include <iostream>
#include <iomanip>

using namespace std;

class SalarySlip {
private:
    float BasicSal, NSSF, HA, HELB, NHIF, Gross, deductions;
    float pf, NetBeforeTax, Tds, SalaryHand;

public:
    void inputDetails() {
        cout << "Organisation Name: TechFin Company\n";
        cout << "Tech Department\n";
        cout << "------------------------------------\n";
        cout << "Client: Brian Mwendwa\n";
        cout << "Client age: 34yrs.\n";
        cout << "KRA No: AO9746297\n";
        cout << "------------------------------------\n";
        cout << "Salary Slip\n\n";
        cout << "Basic Salary: ";
        cin >> BasicSal;

        calculateDeductions();
        calculateGrossSalary();
        calculateNetSalary();
    }

    void calculateDeductions() {
        deductions = 0.3 * BasicSal;
        NSSF = deductions * 0.1;
        HA = deductions * 0.5;
        HELB = 5000; // Fixed
        NHIF = deductions * 0.75;
    }

    void calculateGrossSalary() {
        Gross = NSSF + HA + HELB + NHIF;
    }

    void calculateNetSalary() {
        pf = BasicSal * 0.12;
        NetBeforeTax = Gross - pf;
        Tds = NetBeforeTax * 0.01;
        SalaryHand = NetBeforeTax - Tds;
    }

    void displaySalarySlip() {
        cout << fixed << setprecision(2);
        cout << "--------------------------------------\n";
        cout << "Basic             |  " << setw(10) << BasicSal << "\n";
        cout << "NSSF              |  " << setw(10) << NSSF << "\n";
        cout << "Housing Allowance |  " << setw(10) << HA << "\n";
        cout << "HELB              |  " << setw(10) << HELB << "\n";
        cout << "NHIF              |  " << setw(10) << NHIF << "\n";
        cout << "Gross Salary      |  " << setw(10) << Gross << "\n";
        cout << "Providence Fund   |  " << setw(10) << pf << "\n";
        cout << "Net Before Tax    |  " << setw(10) << NetBeforeTax << "\n";
        cout << "TDS               |  " << setw(10) << Tds << "\n";
        cout << "-------------------------------------\n";
        cout << "Salary in Hand    |  " << setw(10) << SalaryHand << "\n";
    }
};

int main() {
    SalarySlip slip;
    slip.inputDetails();
    slip.displaySalarySlip();
    return 0;
}
