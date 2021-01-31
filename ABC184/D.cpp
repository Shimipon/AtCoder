#include <bits/stdc++.h>
using namespace std;

double P[101][101][101];

double prob(int x, int y, int z){
	double ans = 0.0;
	if(x == 100)return 0;
	if(y == 100)return 0;
	if(z == 100)return 0;
	if(P[x][y][z] >= 0)return P[x][y][z];
	double Sum = x + y + z;
	ans += (x / Sum) * (prob(x+1,y,z) + 1);
	ans += (y / Sum) * (prob(x,y+1,z) + 1);
	ans += (z / Sum) * (prob(x,y,z+1) + 1);
	P[x][y][z] = ans;
	return ans;
}

int main(){
	int A, B, C;
	cin >> A >> B >> C;
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<101;k++){
				P[i][j][k] = -1.0;
			}
		}
	}
	printf("%.8f\n", prob(A,B,C));
}
