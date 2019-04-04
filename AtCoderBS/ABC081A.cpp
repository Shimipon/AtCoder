#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	string S;
	cin >> S;
	int count = 0;
	for(int i=0;i<3;i++){
		if(S[i] == '1')count++;
	}
	cout << count << endl;
}