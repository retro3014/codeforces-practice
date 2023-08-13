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
const int MAX_N = 1000;

int T;
ll K, S;


ll calc(ll x){
	ll op = x;
	ll m = K-x;
	ll P = S;

	while(op>0){
		ll d = P%10LL;
		if(d==2 || d==4 || d==8 || d==6){
			if(op>=4){
				P+=(op/4)*20LL;
				op = op%4;
			}else{
				P+=d;
				op--;
			}
		}else if(d==0){
			break;
		}else{
			P+=d;
			op--;
		} 
	}
	return P*m;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &S, &K);
		ll ans = 0;
		while(1){
			ll d = S%10;
			if(d%2==0){
				break;
			}
			ans = max(ans, calc(0));
			K--;
			S+=d;
		}
		for(ll d=0; d<4; d++){
			ll s = 0, e = K/4, m;
			if(e*4+d>K){
				e--;
			}	
			if(e<0){
				continue;
			}
			while(s<e){
				if(s==e-1){
					if(calc(s*4+d) > calc(e*4+d)){
						e = s;
					}else{
						s = e;
					}
				}else{
					m = (s+e)/2;
					if(calc(m*4+d) > calc((m+1)*4+d)){
						e = m;
					}else{
						s = m+1;
					}
				}
			}
			ans = max(ans, calc(s*4+d));

		}
		printf("%lld\n", ans);
	}
    return 0;
}
