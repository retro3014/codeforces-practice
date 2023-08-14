#include <bits/stdc++.h>

#define pb push_back
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000000;
const int MAX_K = 1010;

int X;
int loc[MAX_N+1];
int A[MAX_N+1];
int ans = 0;

int now=1;

int query(int x){
	printf("+ %d\n", x);
	fflush(stdout);
	//now=(now+x-1)%MAX_N+1;
	scanf("%d", &x);
	//return now;
	return x;
}

void printans(){
	printf("! %d\n", ans);
}

int main(){
	scanf("%d", &X);
	for(int i=1; i<=MAX_N; i++){
		loc[i] = A[i] = -1;
	}
	A[0] = X;
	loc[X] = 0;
	int idx = 0;
	for(int i=1; i<=MAX_K; i++){
		int n = query(1);
		idx++;
		A[i] = n;
		if(loc[n]!=-1){
			ans = i;
			printans();
			return 0;
		}else{
			loc[n] = i;
		}
	}
	for(int i=1; i<=MAX_K; i++){
		int d = MAX_K-10;
		idx+=d;
		int n = query(d);
		if(loc[n]!=-1){
			ans = idx - loc[n];
			printans();
			return 0;
		}
	}
    return 0;
}
