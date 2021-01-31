#include <bits/stdc++.h>
using namespace std;
//
typedef pair<int, int> node;

int MAX_N = 200000;
int SIZE[200000];
vector<node> unionfind(MAX_N);

void init(int N){
	for(int i=0;i<N;i++){
		unionfind[i].first = i;
		unionfind[i].second = 0;
		SIZE[i] = 1;
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
	if(unionfind[x].second > unionfind[y].second){
		unionfind[x].first = y;
	} 
	else{
		unionfind[y].first = x;
	}
	if(unionfind[x].second == unionfind[y].second){
		unionfind[x].second++;
	}
	int tmp = SIZE[x];
	SIZE[x] += SIZE[y];
	SIZE[y] += tmp;
}

int main(){
	int N, M;
	cin >> N >> M;
	int A[M], B[M];
	init(N);
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i];
		unite(A[i], B[i]);
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		ans = max(SIZE[i], ans);
	}
	cout << ans << endl;
}