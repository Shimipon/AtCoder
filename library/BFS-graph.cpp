#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<int>> R(N, vector<int>(0));
	for(int i=0;i<M;i++){
		int A, B;
		cin >> A >> B;
		A--;
		B--;
		R[A].push_back(B);
		R[B].push_back(A);
	}
	int D[N];
	for(int i=0;i<N;i++){
		mark[i] = -1;
	}
	D[0] = 0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int P = que.front();
		que.pop();
		for(int i=0;i<(int)R[P].size();i++){
			if(D[R[P][i]] == -1){
				que.push(R[P][i]);
				D[R[P][i]] = D[P] + 1;
			}
		}
	}
}