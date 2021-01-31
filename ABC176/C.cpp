#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	long long MAX = A[0];
	long long ans = 0;
	for(int i=1;i<N;i++){
		if(A[i] < MAX){
			ans += MAX - A[i];
		}
		MAX = max(MAX, A[i]);
	}
	cout << ans << endl;
}
