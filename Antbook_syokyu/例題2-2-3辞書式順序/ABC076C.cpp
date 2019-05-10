#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
using namespace std;

int main(){
	string Sdash, T;
	cin >> Sdash >>T;
	int N = (int)Sdash.size();
	int M = (int)T.size();
	vector<string> S;
	bool check = false;
	for(int i=0;i+M-1<N;i++){
		bool able = true;
		for(int j=0;j<M;j++){
			if(Sdash[i+j] != T[j] && Sdash[i+j] != '?'){
				able = false;
				break;
			}
		}
		if(able){
			string Sans = Sdash;
			for(int j=0;j<N;j++){
				if(j < i && Sans[j] == '?'){
					Sans[j] = 'a';
				}
				if(j >= i && j < i + M && Sans[j] == '?'){
					Sans[j] = T[j - i];
				}
				if(j >= i + M && Sans[j] == '?'){
					Sans[j] = 'a';
				}
			}
			S.push_back(Sans);
		}
	}
	sort(S.begin(), S.end());
	if((int)S.size()) cout << S[0] << endl;
	else cout << "UNRESTORABLE" << endl;
}