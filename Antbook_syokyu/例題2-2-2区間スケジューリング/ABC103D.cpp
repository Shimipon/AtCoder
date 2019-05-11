#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
vector<int> coin = {500, 100, 50, 10, 5, 1};

int main(){
	int N;
	cin >> N;
	N = 1000 - N;
	int count = 0;
	for(int i=0;i<6;i++){
		while(N >= coin[i]){
			N -= coin[i];
			count++;
		}
	}
	cout << count << endl;
}