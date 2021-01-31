#include <bits/stdc++.h>
using namespace std;

int main(){
    long A, B, C, K;
    cin >> A >> B >> C >> K;
    long ans = 0;
    if(A > K){
        ans += K;
        K = 0;
    }
    else{
        ans += A;
        K -= A;
    }
    if(B > K){
        K = 0;
    }
    else{
        K -= B;
    }
    if(C > K){
        ans -= K;
        K = 0;
    }
    else{
        ans -= C;
        K -= C;
    }
    cout << ans << endl;
}