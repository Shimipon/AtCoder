#include <bits/stdc++.h>
using namespace std;

int pow(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int H, W, K;
	cin >> H >> W >> K;
	char c[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> c[i][j];
		}
	}
	int ans = 0;
	for(int l=0;l<pow(2,H);l++){
		for(int m=0;m<pow(2,W);m++){
			int cnt = 0;
			for(int i=0;i<H;i++){
				for(int j=0;j<W;j++){
					if((l >> i) % 2 == 0 && (m >> j) % 2 == 0 && c[i][j] == '#') cnt++;
				}
			}
			if(cnt == K)ans++;
		}
	}
	cout << ans << endl;
}
