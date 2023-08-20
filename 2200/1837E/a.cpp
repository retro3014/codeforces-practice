#include <bits/stdc++.h>

#define pb push_back
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = (1<<20);

int K;
int N;
int A[MAX_N+1];

ll ans = 1LL;
ll p[MAX_N+1];
void mult(ll x){
	ans = (ans * x) % MOD;
}

int main(){
	p[0] = 1;
	for(int i=1; i<=MAX_N; i++){
		p[i] = (p[i-1] * (ll)i) % MOD;
	}
	scanf("%d", &K);
	N = (1<<K);
	for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	while(K>0){
		ll cnt = 0;
		for(int i=1; i<=N; i+=2){
			int j = i+1;
			int ni = j/2;
			if(A[i]==-1 && A[j]==-1){
				mult(2LL);
				cnt++;
				A[ni] = -1;
			}else if(A[i]!=-1 && A[j]!=-1){
				if(A[i]<=N/2 && A[j]<=N/2){
					mult(0LL);
				}else if(A[i]>N/2 && A[j]>N/2){
					mult(0LL);
				}
				A[ni] = min(A[i], A[j]);
			}else{
				int n = max(A[i], A[j]);
				if(n<=N/2){
					A[ni] = n;
					cnt++;
				}else{
					A[ni] = -1;
				}
			}
		}
		mult(p[cnt]);
		K--;
		N = (1<<K);
	}
	printf("%lld\n", ans);
    return 0;
}
