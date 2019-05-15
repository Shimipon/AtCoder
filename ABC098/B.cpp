#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	int ans = 0;
	bool check[2][26];
	for(int i=0;i<26;i++){
		check[0][i] = false;
		check[1][i] = false;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			check[0][S[j] - 'a'] = true;
		}
		for(int j=i;j<N;j++){
			check[1][S[j] - 'a'] = true;
		}
		int count = 0;
		for(int i=0;i<26;i++){
			if(check[0][i] && check[1][i])count++;
		}
		ans = max(ans,count);
		for(int i=0;i<26;i++){
			check[0][i] = false;
			check[1][i] = false;
		}
	}
	cout << ans << endl;
}