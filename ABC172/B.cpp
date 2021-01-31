#include <bits/stdc++.h>
using namespace std;
int main(){
	string S, T;
	cin >> S >> T;
	int N = (int)S.size();
	int cnt = 0;
	for(int i = 0;i<N;i++){
		if(S[i] != T[i])cnt++;
	}
	cout << cnt << endl;
}
