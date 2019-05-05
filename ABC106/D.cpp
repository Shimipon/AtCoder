#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> L(M), R(M);
	for(int i=0;i<M;i++){
		cin >> L[i] >> R[i];
	}
	vector<int> p(Q),q(Q);
	for(int i=0;i<Q;i++){
		cin >> p[i] >> q[i];
	}
	int X[501][501];
	int C[501][501];
	for(int i=0;i<M;i++){
		X[L[i]][R[i]]++;
	}
	for(int i=0;i<N+1;i++){
		for(int j=0;j<N+1;j++) C[i][j] = C[i][j-1] + X[i][j];
	}
	for(int i=0;i<Q;i++){
		int sum = 0;
		for(int j=p[i];j<=q[i];j++) sum += C[j][q[i]] - C[j][p[i] - 1];
		cout << sum << endl;
	}
}