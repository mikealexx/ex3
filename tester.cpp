#include <iostream>
#include "HealthPoints.h"
#include "Queue.h"

using std::cout;
using std::endl;

#define DIVIDER "=========="

static int isEven(int n) {
        return n%2==1;
}

static void setFortyTwo(int &n) {
    n = 42;
}

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
    q.pushBack(4);
    q.pushBack(12);
    q.pushBack(32);
    q.pushBack(5);
    q.pushBack(25);
    q.pushBack(8);
    q.pushBack(9);

    transform(q, setFortyTwo);

    for(Queue<int>::Iterator it = q.begin(); it != q.end(); ++it) {
       cout << *it << endl;
    }

    return 0;
}