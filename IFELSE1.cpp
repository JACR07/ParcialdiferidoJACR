#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "ingresa tu primer numero ";
    cin >> a;
    cout << "ingresa tu segundo numero ";
    cin >> b;

    if (a > b)
    {
        cout << "Tu primer numero es mayor que tu segundo numero";
    }
    else if (a < b)
    {
        cout << "tu segundo numero es mayor que tu primer numero";
    }
    else if (a == b)
    {
        cout << "numeros iguales";
    }
    else
        cout << "numero invalido";

    return 0;
}