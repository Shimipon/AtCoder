#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main(){
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector<int> change;
	change.push_back(0);
	for(int i = 1;i<N;i++){
		if(S[i-1] != S[i]) change.push_back(i);
	}
	int R = (int)change.size();
	int ans = 0;
	for(int i=0;i<R;i++){
		if(S[change[i]] == '1')
			if(i + 2 * K + 1 < R){
				ans = max(ans, change[i + 2 * K + 1] - change[i]);
			}
			else ans = max(ans, N - change[i]);
		if(S[change[i]] == '0'){
			if(i + 2 * K < R){
				ans = max(ans, change[i + 2 * K] - change[i]);
			}
			else ans = max(ans, N - change[i]);
		}
	}
	cout << ans << endl;
}