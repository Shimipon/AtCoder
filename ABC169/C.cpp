#include <bits/stdc++.h>
using namespace std;
int main(){
    long A;
    double B;
    cin >> A >> B;
    B *= 100;
    double B1 = B + 0.1;
    long c =  long(B1);
    cout << (A * c) / 100 << endl;
}
