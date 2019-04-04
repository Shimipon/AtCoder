#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	long int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	vector<long int> l(Q),r(Q);
	for(int i=0;i<Q;i++){
		cin >> l[i] >> r[i];
	}
	vector<long int> v;
	v.push_back(0);
	for(int j=1;j<N;j++){
		if(*(S.begin() + j - 1) == 'A' && *(S.begin() + j) == 'C') v.push_back(v[j-1] + 1);
		else v.push_back(v[j-1]);
	}
	for(int i=0;i<Q;i++){
		cout << v[r[i]-1] - v[l[i]-1] << endl;
	}
}