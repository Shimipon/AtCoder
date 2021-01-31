#include <bits/stdc++.h>
using namespace std;
#define MAX 400000

// 一つ目が親ノードを、二つ目が深さを示す
typedef pair<int, int> node;

int MAX_N = 400000;
int M[MAX];
vector<node> unionfind(MAX_N);

void init(int N){
	for(int i=0;i<N;i++){
		unionfind[i].first = i;
		unionfind[i].second = 0;
	}
}

int find(int n){
	if(unionfind[n].first == n){
		return n;
	}
	else{
		unionfind[n].first = find(unionfind[n].first);
		return unionfind[n].first;
	}
}


void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	int tmp = M[x];
	M[x] += M[y];
	M[y] += tmp;
	if(unionfind[x].second > unionfind[y].second){
		unionfind[x].first = y;
	} 
	else{
		unionfind[y].first = x;
	}
	if(unionfind[x].second == unionfind[y].second){
		unionfind[x].second++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	int N;
	cin >> N;
	init(MAX);
	int A[N], B[N], C[MAX], MC[MAX];
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	for(int i=0;i<MAX;i++){
		MC[i] = 0;
		M[i] = 1;
		C[i] = 0;
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		int tmp = C[find(A[i])];
		C[find(A[i])] += C[find(B[i])] + 1;
		C[find(B[i])] += tmp + 1;
		unite(A[i], B[i]);
	}
	for(int j=0;j<MAX;j++){
		if(MC[find(j)] != 0) continue;
		if(C[find(j)] == 0) continue;
		// cout << j << ":" << find(j) << endl;
		if(M[find(j)] - 1 == C[find(j)]){
			ans += M[find(j)] - 1;
			// cout << ans << endl;
		}
		else {
			ans += M[find(j)];
			// cout << ans << endl;
		}
		MC[find(j)] = 1;
	}
	cout << ans << endl;
}