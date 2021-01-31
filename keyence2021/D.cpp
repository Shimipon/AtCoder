#include <bits/stdc++.h>
using namespace std;

long long mod = 7;

long long modplus(long long a, long long b){
	long long ans = a + b;
	ans %= mod;
	return ans;
}

int main(){
	string S;
	S = "ABBBBBBB";
	int C[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			C[i][j] = 0;
		}
	}
	int now = 0;
	for(int l=0;l<21;l++){
		S = "ABBBBBBB";
		for(int i=0;i<3;i++){
			S[modplus(now, i) + 1] = 'A';
		}
		for(int i=3;i<7;i++){
			S[modplus(now, i) + 1] = 'B';
		}
		now = modplus(now, 3);
		cout << S << endl;
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				if(S[i] == S[j])C[i][j]++;
			}
		}
	}
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(i != j) cout << i << ":" << j << ":" << C[i][j] << endl;
		}
	}
}