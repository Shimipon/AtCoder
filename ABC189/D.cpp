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
	long long dp[N+1][2];
	for(int i=0;i<N;i++){
		cin >> S[i];
	}
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i=0;i<N;i++){
		if(S[i] == "AND") {
			dp[i+1][0] = 2 * dp[i][0] + dp[i][1];
			dp[i+1][1] = dp[i][1];
		}
		else{
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = 2 * dp[i][1] + dp[i][0];
		}
	}
	cout << dp[N][1] << endl;
}
