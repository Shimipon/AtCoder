#include <bits/stdc++.h>
using namespace std;

double P[101][101][101];

double prob(int x, int y, int z){
	double ans = 0.0;
	if(x < 0)return 0;
	if(y < 0)return 0;
	if(z < 0)return 0;
	if(P[x][y][z] >= 0.0)return P[x][y][z];
	double sum = x + y + z - 1;
	if(sum == 0)return 0;
	ans += (double(x - 1) / double(sum)) * prob(x - 1,y,z);
	ans += (double(y - 1) / double(sum)) * prob(x,y - 1,z);
	ans += (double(z - 1) / double(sum)) * prob(x,y,z - 1);
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
	P[A][B][C] = 1.0;
	P[0][0][0] = 0.0;
	double ans = 0.0;
	for(int i=A;i<100;i++){
		for(int j=B;j<100;j++){
			ans += double(i - A + j - B + 100 - C) * prob(i, j, 100);
			printf("確率　%.8f\n", prob(i, j, 100));
			printf("期待値%.8f\n", ans);
		}
	}
	
	for(int i=A;i<100;i++){
		for(int j=C;j<100;j++){
			ans += double(i - A + j - B + 100 - C) * prob(i, 100, j);
			printf("確率　%.8f\n", prob(i, 100, j));
			printf("期待値%.8f\n", ans);
		}
	}

	for(int i=B;i<100;i++){
		for(int j=C;j<100;j++){
			ans += double(i - A + j - B + 100 - C) * prob(100, i, j);
			printf("確率　%.8f\n", prob(100, i, j));
			printf("期待値%.8f\n", ans);
		}
	}
}
