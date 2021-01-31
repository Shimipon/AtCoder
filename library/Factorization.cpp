// 適宜書き換える
#define MAX_N = 1000001;
int D[MAX_N];
int IN[MAX_N];
void init(){
	for(int i=0;i<MAX_N;i++){
		D[i] = i;
		IN[i] = 0;
	}
	for(int i=2;i*i<=MAX_N - 1;i++){
		for(int j=1;j*i<MAX_N;j++){
			D[i*j] = max(D[i*j], i);
		}
	}
}

void factorize(int x){
	if(x == 0)return;
	if(x == 1)return;
	int tmp = x;
	while(tmp > 1){
		IN[D[tmp]]++;
		tmp /= D[tmp];
	}
	if(tmp > 1)IN[tmp]++;
}