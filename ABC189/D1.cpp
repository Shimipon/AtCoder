#include <bits/stdc++.h>
using namespace std;

long long POW(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = a * a;
	if(p % 2) return POW(adash, p / 2) * a;
	else return POW(adash, p / 2);
}

int main(){
	long long N;
	cin >> N;
	string S[N];
	long long ans = 0;
	for(int i=0;i<N;i++){
		cin >> S[i];
	}
	for(long long i=N-1;i>=1;i--){
		if(S[i] == "OR")ans += POW(2, i+1);
	}
	if(S[0] == "OR")ans += 3;
	else ans += 1;
	cout << ans << endl;
}
