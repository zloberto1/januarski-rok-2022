#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double n, s;

    cout << "Unesi prirodni broj n: "; cin >> n;

    s = 0;

    for(int i = 1; i <= n; i++) {
        cout << i << endl;
        s += 1 / pow((2 * i) + 1, 2);
    }

    cout << "Suma funkcije je: " << s;

    return 0;
}
