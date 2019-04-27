#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
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
	ll N;
	cin >> N;
	vector<ll> C(N), V(N);
	for(ll i=0;i<N;i++){
		cin >> V[i];
	}
	for(ll i=0;i<N;i++){
		cin >> C[i];
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(V[i] - C[i]>0){
			ans += V[i] - C[i];
		}
	}
	cout << ans << endl;
}