#include <iostream>
#include <cmath>
#include "nrcomplex.h"
#include "matrice.h"
using namespace std;


int main()
{


    Matrice_Complexa a(1,1);
    cin >> a;
    cout << a;

    Matrice_Complexa b(1,1);
    cin >> b;
    b = b + a;
    cout << b;



}
