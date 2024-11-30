#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    bool hasDecimal = false;
    bool hasDigits = false;
    int signCount = 0;

    for (size_t i = 0; i < str.length(); ++i) { 
        char ch = str[i];

        if (isdigit(ch)) {
            hasDigits = true;
        } else if (ch == '.') {
            if (hasDecimal) {
                return -999999.99;
            }
            hasDecimal = true;
        } else if (ch == '+' || ch == '-') {
            if (i != 0 || ++signCount > 1) {
                return -999999.99;
            }
        } else {
            return -999999.99;
        }
    }

    if (!hasDigits) {
        return -999999.99;
    }

    try {
        return stod(str); 
    } catch (...) {
        return -999999.99;
    }
}
