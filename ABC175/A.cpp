#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	int ans = 0;
	for(int i=0;i<3;i++){
		if(S[i] == 'R') ans = 1;
	}
	if(S[0] == S[1] && S[0] == 'R') ans = 2;
	if(S[1] == S[2] && S[1] == 'R') ans = 2;
	if(S[0] == S[1] && S[1] == S[2] && S[0] == 'R') ans = 3;
	cout << ans <<endl;
}
