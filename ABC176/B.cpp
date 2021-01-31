#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	int am = 0;
	for(int i=0;i<(int)S.length();i++){
		am += S[i] - '0';
		am %= 9;
	}
	if(am == 0)cout << "Yes" << endl;
	else cout << "No" << endl;
}
