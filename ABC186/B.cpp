#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	int A[H][W];
	int Min = 100;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> A[i][j];
			Min = min(A[i][j], Min);
		}
	}
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			ans += A[i][j] - Min;
		}
	}
	cout << ans << endl;
}
