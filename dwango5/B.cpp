#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll pow(ll A, ll P){
	ll a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	ll adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	vector<ll> B;
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			ll sum = 0;
			for(int l=i;l<=j;l++){
				sum += A[l];
			}
			B.push_back(sum);
		}
	}
	ll x = 0;
	for(int m=39;m>=0;m--){
		int count = 0;
		for(int i=0;i<(int)B.size();i++){
			ll xdash = x + pow(2,m);
			if((xdash & B[i]) == xdash) count++;
		}
		if(count >= K) x += pow(2,m);
	}
	cout << x << endl;
}