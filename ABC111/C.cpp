#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long int n;
	cin >> n;
	vector<long int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	vector<long int> numodd(100001,0);
	vector<long int> numeven(100001,0);
	long int maxoddnum = 0;
	long int maxevennum = 0;
	long int maxoddnum2 = 0;
	long int maxevennum2 = 0;
	for(int i=0;i<n/2;i++){
		numeven[v[2 * i]]++;
		numodd[v[2 * i + 1]]++;
		if((numeven[v[2 * i]] >= numeven[maxevennum]) &&(maxevennum != v[2 * i])){
			maxevennum2 = maxevennum;
			maxevennum = v[2 * i];
		}
		if((numodd[v[2 * i + 1]] >= numodd[maxoddnum]) &&(maxoddnum != v[2 * i + 1])){
			maxoddnum2 = maxoddnum;
			maxoddnum = v[2 * i + 1];
		}
	}
	long int ans = n - numodd[maxoddnum] - numeven[maxevennum];
	if(maxoddnum == maxevennum){
		ans = min(n - numodd[maxoddnum2] - numeven[maxevennum], n - numodd[maxoddnum] - numeven[maxevennum2]);
	}
	cout << ans << endl;
}