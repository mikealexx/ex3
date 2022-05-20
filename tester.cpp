#include <iostream>
#include "HealthPoints.h"

using std::cout;
using std::endl;

#define DIVIDER "=========="

int main() {
    cout << DIVIDER << " Default Constructor " << DIVIDER << endl;
    HealthPoints hp1;
    cout << hp1 << endl;

    cout << DIVIDER << " Constructor " << DIVIDER << endl;
    HealthPoints hp2(150);
    cout << hp2 << endl;

    cout << DIVIDER << " Copy Constructor " << DIVIDER << endl;
    HealthPoints hp3(hp1);
    cout << hp3 << endl;

    cout << DIVIDER << " Assignment Operator " << DIVIDER << endl;
    HealthPoints hp4;
    hp4 = hp2;
    cout << hp4 << endl;

    cout << DIVIDER << " += Operator " << DIVIDER << endl;
    hp4 += 20;
    cout << hp4 << endl;

    cout << DIVIDER << " -= Operator " << DIVIDER << endl;
    hp4 -= 20;
    cout << hp4 << endl;

    cout << DIVIDER << " + Operator " << DIVIDER << endl;
    HealthPoints hp5 = hp4 + 10;
    cout << hp5 << endl;

    cout << DIVIDER << " - Operator " << DIVIDER << endl;
    HealthPoints hp6 = hp5 - 34;
    cout << hp6 << endl;

    cout << DIVIDER << " == Operator " << DIVIDER << endl;
    cout << (hp6 == hp5) << endl;

    cout << DIVIDER << " != Operator " << DIVIDER << endl;
    cout << (hp6 != hp5) << endl;

    cout << DIVIDER << " < Operator " << DIVIDER << endl;
    cout << (hp6 < hp5) << endl;

    cout << DIVIDER << " > Operator " << DIVIDER << endl;
    cout << (hp6 > hp5) << endl;

    cout << DIVIDER << " <= Operator " << DIVIDER << endl;
    cout << (hp6 <= hp5) << endl;

    cout << DIVIDER << " >= Operator " << DIVIDER << endl;
    cout << (hp6 >= hp5) << endl;

    return 0;
}