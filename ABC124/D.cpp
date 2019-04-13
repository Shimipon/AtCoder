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
	int ans = 0;
	int kdash = K;
	int check = 0;
	int count = 0;
	vector<int> left1;
	left1.push_back(0);
	for(int i=0;i<N;i++){
		if(S[i] == '0' && !check){
			check = 1;
			count++;
		}
		if(S[i] == '1' && check){
			check = 0;
			left1.push_back(i);
		}
		if(count > K){
			count--;
			ans = max(ans, i - left1[0]);
			left1.erase(left1.begin());
		}
		if(i == N - 1) {
			ans = max(ans, i - left1[0] + 1);
		}
	}
	cout << ans << endl;
}