#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<string> S;
vector<vector<int>> reach;
void search(int i, int j, int H, int W){
	if(i < 0 || i >= H) return;
	if(j < 0 || j >= W) return;
	if(reach[i][j]) return;
	if(S[i][j] == '#') return;
	reach[i][j] = 1;
	search(i+1, j, H, W);
	search(i-1, j, H, W);
	search(i, j+1, H, W);
	search(i, j-1, H, W);
}

int main(){
	int H, W;
	cin >> H >> W;
	for(int i=0;i<H;i++){
		string ssub;
		cin >> ssub;
		S.push_back(ssub);
	}
	for(int i=0;i<H;i++){
		vector<int> subreach(W, 0);
		reach.push_back(subreach);
	}
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(S[i][j] == 's')search(i, j, H, W);
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(S[i][j] == 'g')ans = reach[i][j];
		}
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}