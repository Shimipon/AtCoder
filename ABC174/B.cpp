#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, D;
	cin >> N >> D;
	long long X[N], Y[N];
	int ans = 0;
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i];
		if(X[i] * X[i] + Y[i] * Y[i] <= D * D)ans++;
	}
	cout << ans << endl;
}
