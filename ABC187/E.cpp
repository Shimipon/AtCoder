#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N-1], B[N-1];
	vector<vector<int>> near(N);
	for(int i=0;i<N-1;i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
		near[A[i]].push_back(B[i]);
		near[B[i]].push_back(A[i]);
	}
	int Q;
	cin >> Q;
	int t[Q], e[Q];
	long long x[Q];
	for(int i=0;i<Q;i++){
		cin >> t[i] >> e[i] >> x[i];
		e[i]--;
	}
	int D[N];
	long long C[N];
	for(int i=0;i<N;i++){
		D[i] = -1;
		C[i] = 0;
	}
	D[0] = 0;
	vector<int> st;
	st.push_back(0);
	while(!st.empty()){
		int now = st.back();
		st.pop_back();
		for(int i=0;i<(int)near[now].size();i++){
			if(D[near[now][i]] == -1){
				st.push_back(near[now][i]);
				D[near[now][i]] = D[now] + 1;
			}
		}
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
	st.push_back(0);
	while(!st.empty()){
		int now = st.back();
		st.pop_back();
		for(int i=0;i<(int)near[now].size();i++){
			if(D[near[now][i]] > D[now]){
				st.push_back(near[now][i]);
				C[near[now][i]] += C[now];
			}
		}
	}
	for(int i=0;i<N;i++){
		cout << C[i] << endl;
	}
}
