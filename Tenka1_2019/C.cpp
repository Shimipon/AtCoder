#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;
	int num[N];
	num[0] = 0;
	if(S[0] == '#')num[0] = 1;
	for(int i=1;i<N;i++){
		if(S[i] == '#') num[i] = num[i-1] + 1;
		else num[i] = num[i-1];
	}
	int ans = N - num[N-1];
	for(int i=0;i<N-1;i++){
		ans = min(num[i] + N - i - 1 - num[N-1] + num[i],ans);
	}
	ans = min(ans, num[N-1]);
	cout << ans << endl;
}