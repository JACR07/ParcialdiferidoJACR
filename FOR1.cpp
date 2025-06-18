#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "Ingrese un numero N: ";
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cout << "1/" << i;
        if (i != N)
            cout << ", ";
    }
    cout << endl;
    return 0;
}