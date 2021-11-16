#include <iostream>

#include "headers/probability_insulators.h"
#include "headers/constant_failure_rate.h"
#include "headers/operations.h"

using namespace std;

int main() {
//    int input;
//    vector<float> v;
//    while(cin >> input)
//        v.push_back(input);
//    cout << average(v) << endl << standardDeviation(v);

    char selection;

    do {
        cout << "=================================\n";
        cout << "1.  Manual Switches\n";
        cout << "2.  Probability Insulators\n";
        cout << "3.  xxx\n";
        cout << "4.  xxx\n";
        cout << "5.  Constant Failure Rate\n";
        cout << "\n";
        cout << "9.  Exit\n";
        cout << "=================================\n";
        cout << "Enter your selection: ";
        cin >> selection;
        cout << endl;

        switch (selection) {
            case '1':
                cout << "todo";
                break;
            case '2':
                probability_insulators();
                break;
            case '3':
                cout << "todo";
                break;
            case '4':
                cout << "todo";
                break;
            case '5':
                constant_failure_rate();
                break;
            case '9':
                break;
            default:
                cout << selection << " is not a valid menu item.\n\n";
        }
    }

    while (selection != '9');

    return 0;
}


