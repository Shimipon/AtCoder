#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> A;
	for(int i=0;i<N;i++){
		long long x;
		cin >> x;
		A.push_back(x);
	}
	vector<long long> B;
	for(int i=1;i<N;i++){
		B.push_back(A[0] - A[i]);
	}
	sort(B.begin(), B.end(), greater<int>{});
	long long ans = 0;
	for(int i=0;i<N-1;i++){
		ans += abs(B[i]);
	}
	long long c = N - 2;
	for(int i=0;i<N-1;i++){
		ans += c * B[i];
		c -= 2;
	}
	cout << ans << endl;
}
