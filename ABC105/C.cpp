#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<int> v;
	while(N != 0){
		int rest = N % (-2);
		if(rest == -1){
			rest = 1;
			N = N / (-2) + 1;
		}
		else N /= -2;
		v.push_back(rest);
	}
	for(int i = (int)v.size() - 1;i>=0;i--){
		cout << v[i];
	}
	if((int)v.size() == 0) cout << 0;
	cout << endl;
}