#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
long int mod = 1000000007;

long int mul(long int A, long int B){
	return (A * B) % mod;
}
long int pl(long int A, long int B){
	return (A + B) % mod;
}
long int mi(long int A, long int B){
	long int ans =  (A - B) % mod;
	if(ans < 0) ans += mod;
	return ans;
}

long int pow(long int P, long int N){
	if(N == 0) return 1;
	if(N == 1) return P;
	return pow(P*P,N / 2) * pow(P, N % 2);
}

long int dp[4][4][4][98];

int main(){
	long int N;
	cin >> N;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(i == 0 && j == 1 && k == 2) dp[i][j][k][0] = 0;
				else if(i == 0 && j == 2 && k == 1) dp[i][j][k][0] = 0;
				else if(i == 2 && j == 0 && k == 1) dp[i][j][k][0] = 0;
				else dp[i][j][k][0] = 1;
			}
		}
	}
	for(int n=1;n<=N-3;n++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				long int sum0 = 0;
				long int sum1 = 0;
				long int sum2 = 0;
				long int sum3 = 0;
				for(int i=0;i<4;i++){
					sum0 = pl(sum0,dp[i][j][k][n-1]);
					sum3 = pl(sum3,dp[i][j][k][n-1]);
					if(!(i == 0 && k == 2) && !(i == 0 && j == 2) && !(j == 0 && k == 2) && !(j == 2 && k == 0)){
						sum1 = pl(sum1,dp[i][j][k][n-1]);
					}
					if(!(j == 0 && k == 1)){
						sum2 = pl(sum2,dp[i][j][k][n-1]);
					}
				}
				dp[j][k][0][n] = sum0;
				dp[j][k][1][n] = sum1;
				dp[j][k][2][n] = sum2;
				dp[j][k][3][n] = sum3;
			}
		}
	}
	long int ans = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				ans = pl(ans,dp[i][j][k][N-3]);
			}
		}
	}
	cout << ans << endl;
}