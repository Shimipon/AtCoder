#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	string S;
	cin >> S;
	int K;
	cin >> K;
	int check = 1;
	string::iterator itr = S.begin();
	vector<string> v;
	for(int i = 1;i<=K;i++){
		if(i > (int)S.size())break;
		for(int j = 0;j < (int)S.size() - i + 1;j++){
			v.push_back(S.substr(j,i));
		}
	}
	sort(v.begin(),v.end());
	int count = 1;
	string ans = v[0];
	int i = 1;
	while(count < K){
		if(v[i-1] != v[i]){
			count++;
			ans = v[i];
		}
		i++;
	}
	cout << ans << endl;
}