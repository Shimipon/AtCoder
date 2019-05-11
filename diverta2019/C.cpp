#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	string S[N];
	for(int i=0;i<N;i++){
		cin >> S[i];
	}
	int ans = 0, A = 0, B=0,AB = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j+1<(int)S[i].size();j++){
			if(S[i][j] == 'A' && S[i][j+1] == 'B')ans++;
		}
		if(S[i][0] == 'B')B++;
		if(S[i][(int)S[i].size()-1] == 'A')A++;
		if(S[i][0] == 'B' && S[i][(int)S[i].size()-1] == 'A')AB++;
	}
	ans += min(A,B);
	if(A == AB && B == AB && AB)ans--;
	cout << ans << endl;
}