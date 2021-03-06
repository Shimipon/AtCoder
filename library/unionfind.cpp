// 一つ目が親ノードを、二つ目が深さを示す
typedef pair<int, int> node;

int MAX_N = 100000;
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