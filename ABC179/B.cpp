#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int D[N][2];
	for(int i=0;i<N;i++){
		cin >> D[i][0] >> D[i][1];
	}
	string ans = "No";
	for(int i=0;i<N-2;i++){
		if(D[i][0] == D[i][1]
			&& D[i+1][0] == D[i+1][1]
			&& D[i+2][0] == D[i+2][1]) {
			ans = "Yes";
		}
	}
	cout << ans << endl;
}
