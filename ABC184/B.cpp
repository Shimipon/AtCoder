#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, X;
	cin >> N >> X;
	string S;
	cin >> S;
	for(int i=0;i<N;i++){
		if(S[i]=='o')X++;
		else if(X > 0) X--;
	}
	cout << X << endl;
}