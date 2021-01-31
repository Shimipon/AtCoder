#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main(){
	int H, W, Ch, Dh, Cw, Dw;
	cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
	char S[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> S[i][j];
		}
	}
	int dh[4] = {1, 0, -1, 0}, dw[4] = {0, 1, 0, -1};
	queue<P> queA;
	int D[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			D[i][j] = -1;
		}
	}
	queA.push(P(Ch - 1, Cw - 1));
	D[Ch - 1][Cw - 1] = 0;
	while(queA.size() > 0){
		P p = queA.front();
		queA.pop();
		if(p.first == Dh - 1 && p.second == Dw - 1) break;
		for(int i=0;i<4;i++){
			int nh = p.first + dh[i];
			int nw = p.second + dw[i];
			if(0 <= nh && nh < H &&
				0 <= nw && nw < W && 
				S[nh][nw] == '.' && D[nh][nw] == -1){
				queA.push(P(nh, nw));
				D[nh][nw] = D[p.first][p.second];
				//cout << "A:" << nh << ":" << nw << ":" << D[nh][nw] << endl; 
			}
		}
	}
	cout << D[Dh - 1][Dw - 1] << endl;
}
