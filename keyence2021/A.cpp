#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long A[N], B[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N;i++){
		cin >> B[i];
	}
	long long C[N];
	int maxi = 0;
	long long maxa = A[0];
	C[0] = A[0] * B[0]; 
	for(int l=1;l<N;l++){
		long long nmax = 0;
		if(A[l] >= maxa){
			maxi = l;
			maxa = A[l];
		}
		nmax = max(A[l] * B[l], maxa * B[l]);
		C[l] = max(C[l-1], nmax);
	}
	for(int i=0;i<N;i++){
		cout << C[i] << endl;
	}
}