#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N, K;
	string S;
	cin >> N >> S >> K;
	for(int i=0;i<N;i++){
		if(S[K-1] != S[i])S[i] = '*';
	}
	cout << S << endl;
}