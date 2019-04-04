#include <iostream>
#include <vector>
using namespace std;
int H, W;
vector<vector<int>> how;
vector<vector<int>> A;
vector<vector<int>> izen;

void func(int x, int y){
	izen[x][y] = 1;
	if(y < W-1 && izen[x][y+1] == 0){
		if(A[x][y] % 2 == 1){
			A[x][y] -=  1;
			A[x][y+1] += 1;
			int xdash = x;
			int ydash = y+1;
			vector<int> v = {x+1,y+1,xdash+1,ydash+1};
			how.push_back(v);
		}
		func(x,y+1);
	}
	else if(y > 0 && izen[x][y-1] == 0){
		if(A[x][y] % 2 == 1){
			A[x][y] -= 1;
			A[x][y-1] += 1;
			int xdash = x;
			int ydash = y-1;
			vector<int> v = {x+1,y+1,xdash+1,ydash+1};
			how.push_back(v);
		}
		func(x,y-1);
	}
	else if(x < H-1 && izen[x+1][y] == 0){
		if(A[x][y] % 2 == 1){
			A[x][y] -= 1;
			A[x+1][y] += 1;
			int xdash = x+1;
			int ydash = y;
			vector<int> v = {x+1,y+1,xdash+1,ydash+1};
			how.push_back(v);
		}
		func(x+1,y);
	}
	else return;
}

int main(){
	cin >> H >> W;
	for(int j=0;j<H;j++){
		vector<int> v(W);
		for(int i=0;i<W;i++){
			cin >> v[i];
		}
		A.push_back(v);
	}
	for(int j=0;j<H;j++){
		vector<int> v(W);
		for(int i=0;i<W;i++){
			v.push_back(0);
		}
		izen.push_back(v);
	}
	func(0,0);
	int howlong = how.size();
	cout << howlong << endl;
	for(int i=0;i<(int)howlong;i++){
		for(int j=0;j<4;j++){
			if(j>0) cout << " ";
			cout << how[i][j];
		}
		cout << endl;
	}
}