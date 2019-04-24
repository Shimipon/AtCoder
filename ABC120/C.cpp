#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
using namespace std;
int main(){
	string S;
	cin >> S;
	string::iterator itr = S.begin();
	int cnt = 0;
	int loop = 1;
	size_t i = 0;
	while(i + 1< S.length()){
		if(*(itr + i) != *(itr + 1 + i)){
			S.erase(itr + i, itr + 2 + i);
			cnt = cnt + 2;
			itr = S.begin();
			if(i > 0){
				i--;
			}
		}
		else{
			i++;
		}
	}
	cout << cnt << endl;
}