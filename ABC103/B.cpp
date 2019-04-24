#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	string S, T;
	cin >> S >> T;
	int N = (int)S.size();
	int ok = 0;
	for(int i=0;i<N;i++){
		int check = 1;
		for(int j=0;j<N;j++){
			if(S[(i + j) % N] != T[j])check = 0;
		}
		if(check)ok = 1;
	}
	if(ok)cout << "Yes" << endl;
	else cout << "No" << endl;
}
