#include <iostream>

using namespace std;

bool IsPrime(int n) {
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool IsGrowing(int n) {

    if(n < 10 && n != 0) return true;
    else if(n > 9 && n < 100) {
        if(n % 10 >= n / 10) return true;
        else return false;
    } else if(n > 99 && n < 1000) {
        if((n / 10) % 10 >= n / 100) {
            if(n % 10 >= (n / 10) % 10) return true;
            else return false;
        } else return false;
    }
    return false;
}

int main()
{
    int x;

    do {
        cout << "Unesi broj(10-1000): "; cin >> x;
    } while(x < 10 || x > 1000);

    for(int i = 0; i <= x; i++) {
        if(IsPrime(i) && IsGrowing(i)) {
                cout << i << endl;
        }
    }

    return 0;
}
