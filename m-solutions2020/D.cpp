#include <bits/stdc++.h>
using namespace std;
int main(){
	long long N, K;
	cin >> N >> K;
	long long A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;K+i<N;i++){
		if(A[i] < A[K + i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
