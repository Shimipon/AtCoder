#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> Pos;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int INF = 99999999;

bool check(Pos p, int r, int c){
	if (p.first < 0) return false;
	if (p.first >= r) return false;
	if (p.second < 0) return false;
	if (p.second >= c) return false;
	return true;
}
	

int main(){
	int R, C;
	cin >> R >> C;
	Pos S, G;
	cin >> S.first >> S.second >> G.first >> G.second;
	S.first--;
	S.second--;
	G.first--;
	G.second--;
	vector<string> c(R);
	for(int i=0;i<R;i++){
		cin >> c[i];
	}
	int Reach[R][C];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			Reach[i][j] = INF;
		}
	}
	queue<Pos> Q;
	Q.push(S);
	Reach[S.first][S.second] = 0;
	while(!Q.empty()){
		Pos now = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			Pos next;
			next.first = now.first + dx[i];
			next.second = now.second + dy[i];
			if(check(next, R, C) && c[next.first][next.second] == '.' && Reach[next.first][next.second] == INF){
				Reach[next.first][next.second] = Reach[now.first][now.second] + 1;
				Q.push(next);
			}
		}
	}
	cout << Reach[G.first][G.second] << endl;
}