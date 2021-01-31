#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	long long A[N];
	long long M = 1000;
	long long kab = 0;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N-1;i++){
		if(A[i] <= A[i+1]){
			long long tmp = M / A[i];
			M %= A[i];
			kab += tmp;
		}
		else{
			M += A[i] * kab;
			kab = 0;
		}
	}
	M += A[N-1] * kab;
	cout << M << endl;
}
