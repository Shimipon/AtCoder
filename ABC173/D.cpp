#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<long> A;
	for(int i=0;i<N;i++){
		long a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end(), greater<long>());
	long ans = 0;
	for(int i=1;i<N;i++){
		if(i % 2 == 1) ans += A[(i - 1) / 2];
		else ans += A[i / 2];
	}
	cout << ans << endl;
}
