#include <bits/stdc++.h>
using namespace std;

long long pow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	long long N;
	cin >> N;
	string S[N];
	for(int i=0;i<N;i++){
		cin >> S[i];
	}
	long long ans = 1;
	for(long long i=N-1;i>=1;i--){
		if(S[i] == "OR")ans += pow(2, i+1);
	}
	cout << ans << endl;
}
