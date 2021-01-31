#include <bits/stdc++.h>
using namespace std;

int main(){
	string S, T;
	cin >> S >> T;
	int N = (int)S.length();
	int M = (int)T.length();
	int ans = M;
	for(int i=0;i+M-1<N;i++){
		int tmp = 0;
		for(int j=0;j<M;j++){
			if(S[i+j] != T[j])tmp++;
		}
		ans = min(tmp, ans);
	}
	cout << ans << endl;
}