
int POW(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return POW(adash, p / 2) * a;
	else return POW(adash, p / 2);
}


long long POW(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = a * a;
	if(p % 2) return POW(adash, p / 2) * a;
	else return POW(adash, p / 2);
}