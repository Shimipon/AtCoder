#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	for(int i=0;i<M;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<M;i++){
		a[i]--;
		b[i]--;
	}
	
}