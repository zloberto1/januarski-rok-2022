#include <iostream>

using namespace std;

int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int x;

    do {
        cout << "Unesite broj: "; cin >> x;
    } while(x < 0);

    cout << "Clan " << x << " Fibonaccijevog niza je: " << fibonacci(x);

    return 0;
}
