#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int A = 0, W = 0, T = 0, R = 0;
	for(int i=0;i<N;i++){
		string S;
		cin >> S;
		if(S == "AC") A++;
		if(S == "WA") W++;
		if(S == "TLE") T++;
		if(S == "RE") R++;
	}
	cout << "AC x " << A << endl;
	cout << "WA x " << W << endl;
	cout << "TLE x " << T << endl;
	cout << "RE x " << R << endl;
}
