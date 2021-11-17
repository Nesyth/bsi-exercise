#include <iostream>

#include "headers/manual_switches.h"
#include "headers/probability_insulators.h"
#include "headers/obeying_exponential_law.h"
#include "headers/transformers_failure.h"
#include "headers/constant_failure_rate.h"

using namespace std;

/**
 * @author Mikołaj Jakubowski <s18860@pjwstk.edu.pl>
 * @author Kamil Głowienke <s21683@pjwstk.edu.pl>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Main function provides simple UI for user to move around coded exercises.
 */

int main() {
    char selection;

    do {
        cout << "=================================\n";
        cout << "1.  Manual Switches (3.1)\n";
        cout << "2.  Probability Insulators (3.2)\n";
        cout << "3.  Transformers Failure (3.3)\n";
        cout << "4.  Obeying Exponential Law (2.1)\n";
        cout << "5.  Constant Failure Rate (3.5)\n";
        cout << "\n";
        cout << "9.  Exit\n";
        cout << "=================================\n";
        cout << "Enter your selection: ";
        cin >> selection;
        cout << endl;

        switch (selection) {
            case '1':
                manual_switches();
                break;
            case '2':
                probability_insulators();
                break;
            case '3':
                transformers_failure();
                break;
            case '4':
                obeying_exponential_law();
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


