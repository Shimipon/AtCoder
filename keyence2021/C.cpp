#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

long long modplus(long long a, long long b){
	long long ans = a + b;
	ans %= mod;
	return ans;
}

long long modminus(long long a, long long b){
	long long ans = a - b;
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}

long long modmul(long long a, long long b){
	long long ans = (a % mod) * (b % mod);
	ans = ((ans % mod) + mod) % mod;
	return ans;
}

long long modpow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = modmul(a,a);
	if(p % 2) return modmul(modpow(adash, p / 2), a);
	else return modpow(adash, p / 2);
}

long long moddiv(long long a, long long b){
	long long divisor = modpow(b, mod - 2);
	return modmul(a,divisor);
}

int main(){
	int H, W, K;
	cin >> H >> W >> K;
	char B[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			B[i][j] = '.';
		}
	}
	for(int k=0;k<K;k++){
		int h,w;
		cin >> h >> w;
		cin >> B[h-1][w-1];
	}
	long long D[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			D[i][j] = 0;
		}
	}
	// cout << "OK" << endl;
	D[0][0] = modpow(3, H * W - K);
	long long div = modpow(3, mod - 2);
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(B[i][j] == 'X'){
				if(j<W-1) D[i][j+1] = modplus(D[i][j], D[i][j+1]);
				if(i<H-1) D[i+1][j] = modplus(D[i][j], D[i+1][j]);
			}
			else if(B[i][j] == 'R'){
				if(j<W-1) D[i][j+1] = modplus(D[i][j], D[i][j+1]);
			}
			else if(B[i][j] == 'D'){
				if(i<H-1) D[i+1][j] = modplus(D[i][j], D[i+1][j]);	
			}
			else{
				long long tmp = modmul(D[i][j] * 2 , div);
				if(j<W-1) D[i][j+1] = modplus(tmp, D[i][j+1]);
				if(i<H-1)D[i+1][j] = modplus(tmp, D[i+1][j]);
			}
		}
		// if(i % 100 == 0)cout << i << endl;
	}
	cout << D[H-1][W-1] << endl;
}