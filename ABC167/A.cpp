#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    chk = true;
    for(int i=0;i<(int)S.length();i++){
        if(S[i] != T[i]) chk = false;
    }
    if(chk) cout << "Yes" << endl;
    else cout << "No" << endl;
}