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
	string::iterator itr = S.begin();
	vector<int> v(N,0);
	int countw = 0;
	for(int i=0;i<N;i++){
		if(*(itr + i) == 'W'){
			countw++;
		}
		v[i] = countw;
	}
	int ans = N - v[N-1] - 1 + v[0];
	for(int i=1;i<N-1;i++){
		ans = min(v[i-1] + N - v[N-1] - (i + 1) + v[i],ans);
	}
	ans = min(v[N-2],ans);
	cout << ans << endl;
}