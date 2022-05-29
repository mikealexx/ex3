#include <iostream>
#include "HealthPoints.h"
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;

#define DIVIDER "=========="

static int isEven(int n) {
    int i;
    cin >> i;
    return n%i==0;
}

/*
static void setFortyTwo(int &n) {
    n = 42;
}*/

int main() {
    /*
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
    HealthPoints hp5 = 10 + hp4;
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
    */

    

    Queue<int> q;
    q.pushBack(6);
    q.pushBack(8);
    q.pushBack(7);

    Queue<int> fq = filter(q, isEven);

    return 0;
}