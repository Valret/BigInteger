#include "DuzaLiczba.h"
#include <iostream>

using namespace std;

int main(){
    DuzaLiczba l1;
    DuzaLiczba l2(172834);
    DuzaLiczba l3("172839023498234792834798237494");
    DuzaLiczba l4(l3);
    DuzaLiczba l5=l4;
    DuzaLiczba l6(-172834);

    DuzaLiczba *l7 = new DuzaLiczba("-172839023498234792834798237494");



    cin >> l1;
    cout << l1 << l2 << l3 << l4 << l5 << l6 << *l7;


    delete l7;

    l1 = l2;
    l1 = l1 + l2 - l3 * l4 / l5;

    cout << DuzaLiczba("555183") / DuzaLiczba("1488");

    l1 += 23;
    l1 += l4;
    l2 -= l3;
    l3 *= l4;

    if(l4 == "23424")
        l4 /= l5;

    if(l5 != l4) {
        l5 = -l5;
        cout << l5;
    }


    l2 = "1221";

    DuzaLiczba silnia = 0;
    if(l2 >= 0 && l2 < "1223")
    {
        silnia = !l2;
        cout << silnia ;
    }
    return 0;
}