#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	string S;
	cin >> S;
	string::iterator itr = S.begin();
	int N = (int)S.size();
	int ans = 0;
	int now = 0;
	for(int i=0;i<N;i++){
		if(*(itr+i)=='A') now++;
		else if(*(itr+i)=='T') now++;
		else if(*(itr+i)=='C') now++;
		else if(*(itr+i)=='G') now++;
		else {
			ans = max(now,ans);
			now =0;
		}
	}
	ans = max(now,ans);
	cout << ans << endl;
}