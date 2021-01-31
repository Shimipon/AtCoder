#include <bits/stdc++.h>
using namespace std;


int main(){
	long N;
	cin >> N;
	int A[100001];
	for(int i=0;i<100001;i++){
		A[i] = 0;
	}
	long sum = 0;
	for(int i=0;i<N;i++){
		long x;
		cin >> x;
		A[x]++;
		sum += x;
	}
	long Q;
	cin >> Q;
	for(long i=0;i<Q;i++){
		long B, C;
		cin >> B >> C;
		sum -= B * A[B];
		sum += C * A[B];
		cout << sum << endl;
		A[C] += A[B];
		A[B] = 0;
	}
}
