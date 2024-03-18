#include <iostream>
#include <map>;
using namespace std;


/*
 * In Visual Studio environment create a console program in C/C++ based on created algorithm by using structures.
 * User should be able to: add data in array of structures,
 * print array contents on the screen (in a clear understandable way for the user),
 * perform additional action according to the individual task.
 *
 *
 * Structure fields: company code, name, paid taxes amount.
 * Operation: define company name that paid lowest taxes amount.
 * */


int main() {
int studentCode = 84883;
int totalTaskCount = 20;
int taskNumber = studentCode % totalTaskCount;
cout << "Task number: " << taskNumber << endl;

cout << endl;

struct Company {
    int companyCode;
    string companyName;
    string countryOfOrigin;
    double paidTaxesAmount;
    int taxationYearStart;
    int taxationYearEnd;
};

    map<string, string> currencies = {
            {"Latvia", "Euro"},
            {"Germany", "Euro"},
            {"UK", "Pound Sterling"},
            {"USA", "US Dollar"}
    };

const int companiesCount = 10;
const int minimalCompaniesCount = 1;
Company companies[companiesCount];

for (int i = 0; i < companiesCount; i++) {
    cout << "Enter company " << i + 1 << " code: ";
    cin >> companies[i].companyCode;
    cout << "Enter company name: ";
    getline(cin >> ws, companies[i].companyName);
    cout << "Enter country of origin: ";
    getline(cin >> ws, companies[i].countryOfOrigin);
    cout << "Enter " + companies[i].companyName + " paid taxes amount (millions): ";
    cin >> companies[i].paidTaxesAmount;
    cout << "Enter " + companies[i].companyName + " taxation year start: ";
    cin >> companies[i].taxationYearStart;
    cout << "Enter " + companies[i].companyName + " taxation year end: ";
    cin >> companies[i].taxationYearEnd;

    if (i > minimalCompaniesCount &&  i % 2 == 0) {
        cout << "Would you like to add another company? (yes/no): ";
        string answer;
        cin >> answer;
        if (answer != "yes") {
            break;
        }
    }
    cout << endl;
}

cout << "---------Provided companies list------------: " << endl;

for (int i = 0; i < companiesCount; i++) {
    cout << "Company " << i + 1 << " data: " << endl;
    cout << "Company code: " << companies[i].companyCode << endl;
    cout << "Company name: " << companies[i].companyName << endl;
    cout << "Taxation period: " << companies[i].taxationYearStart << " - " << companies[i].taxationYearEnd << endl;
    cout << "Paid taxes amount: " << companies[i].paidTaxesAmount << " " <<  currencies[companies[i].countryOfOrigin]
    << endl;
    cout << "--------------------------------------------" << endl;
}

cout << "---------Company that paid lowest taxes amount------------: " << endl;

float lowestTaxesAmount = companies[0].paidTaxesAmount;
int lowestTaxesAmountIndex = 0;
for (int i = 1; i < companiesCount; i++) {
    if (companies[i].paidTaxesAmount < lowestTaxesAmount) {
        lowestTaxesAmount = companies[i].paidTaxesAmount;
        lowestTaxesAmountIndex = i;
    }
}

cout << "Company that paid lowest taxes amount: " << companies[lowestTaxesAmountIndex].companyName << endl;























    return 0;
}
