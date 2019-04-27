#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int GCD(int a, int b){
	if(a % b == 0) return b;
	if(b % a == 0) return a;
	if(a > b) return GCD(b, a%b);
	else return GCD(a, b%a);
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	vector<int> B(N);
	B[0] = A[0];
	for(int i=1;i<N;i++){
		B[i] = GCD(B[i-1],A[i]);
	}
	vector<int> C(N);
	C[0] = 1;
	C[1] = max(A[0],A[1]);
	if(N > 2){
			C[2] = max(GCD(A[0],A[2]),GCD(A[1],A[2]));
	}
	for(int i=3;i<N;i++){
		C[i] = max(B[i-1], GCD(C[i-1],A[i]));
	}
	cout << C[N-1] << endl;
}