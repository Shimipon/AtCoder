#include <bits/stdc++.h>
using namespace std;

int janken(int r, int s, int p, char a){
	if(a == 'r')return p;
	else if(a == 's')return r;
	else if(a == 'p')return s;
	else return 0;
}

int main(){
	int N, K, R, S, P;
	cin >> N >> K >> R >> S >> P;
	string T;
	cin >> T;
	int dp[N][2];
	dp[0][0] = 0;
	dp[0][0] = janken(R,S,P,T[0]);
	for(int i=1;i<N;i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		
	}
}