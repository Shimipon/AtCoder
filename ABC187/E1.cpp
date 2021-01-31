#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N-1], B[N-1];
	for(int i=0;i<N-1;i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	int Q;
	cin >> Q;
	int t[Q], e[Q];
	long long x[Q];
	for(int i=0;i<Q;i++){
		cin >> t[i] >> e[i] >> x[i];
		e[i]--;
	}
	vector<pair<int, int>> E;
	for(int i=0;i<N-1;i++){
		pair<int, int> x;
		x.first = min(A[i], B[i]);
		x.second = max(A[i], B[i]);
		E.push_back(x);
	}
	long long C[N];
	int D[N];
	for(int i=0;i<N;i++){
		C[i] = 0;
		D[i] = 0;
	}
	sort(E.begin(), E.end());
	for(int i=0;i<N-1;i++){
		D[E[i].second] = D[E[i].first] + 1;
	}
	for(int j=0;j<Q;j++){
		if(t[j] == 1){
			if(D[A[e[j]]] > D[B[e[j]]]) C[A[e[j]]] += x[j];
			else{
				C[0] += x[j];
				C[B[e[j]]] -= x[j];
			}
		}
		else{
			if(D[B[e[j]]] > D[A[e[j]]]) C[B[e[j]]] += x[j];
			else{
				C[0] += x[j];
				C[A[e[j]]] -= x[j];
			}
		}
	}
	for(int i=0;i<N-1;i++){
		C[E[i].second] += C[E[i].first];
		cout << E[i].first << ":" << E[i].second << endl;
	}
	for(int i=0;i<N;i++){
		cout << C[i] << endl;
	}
}
