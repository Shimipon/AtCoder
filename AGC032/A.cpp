#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> b(N);
	for(int i=0;i<N;i++){
		cin >> b[i];
	}
	vector<int> a;
	int check = 1;
	while(check){
		if((int)b.size() == 0) check = 0;
		for(int i=(int)b.size() - 1;i>=0;i--){
			if(b[i] == i+1) {
				b.erase(b.begin() + i);
				a.push_back(i+1);
				break;
			}
			if(i == 0){
				check = 0;
			}
		
		}
	}
	if((int)b.size() > 0) cout << -1 << endl;
	else{
		for(int i=0;i<(int)a.size();i++){
			cout << a[(int)a.size() - 1 - i] << endl;
		}
	}
}