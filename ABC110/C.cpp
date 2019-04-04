#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string S, T;
	cin >> S >> T;
	vector<char> trans(26, '0');
	vector<int> use(26, 0);
	string::iterator itrs = S.begin();
	string::iterator itrt = T.begin();
	int check = 1;
	for(int i=0;i<(int)S.size();i++){
		if(trans[*(itrs + i) - 'a'] == '0') {
			trans[*(itrs + i) - 'a'] = *(itrt + i);
			if(use[*(itrt + i) - 'a'] == 1) check = 0;
			use[*(itrt + i) - 'a'] = 1;
		}
		else if(trans[*(itrs + i) - 'a'] != *(itrt + i)) {
			check = 0;
		}
	}
	if(check) cout << "Yes" << endl;
	else cout << "No" << endl;
}