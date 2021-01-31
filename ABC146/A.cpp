#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	string S[8];
    S[0] = "";
    S[1] = "SAT";
    S[2] = "FRI";
    S[3] = "THU";
    S[4] = "WED";
    S[5] = "TUE";
    S[6] = "MON";
    S[7] = "SUN";
    string l;
    cin >> l;
    for(int i=0;i<8;i++){
        if(S[i] == l)cout << i << endl;
    }
}
