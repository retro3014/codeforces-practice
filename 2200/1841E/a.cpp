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
const int MAX_N = 200000;

int T;
ll M;
int N;
ll A[MAX_N+1];

priority_queue<pair<int, pii> > pq;

struct SEG{
	struct NODE{
		int l, r;
		int mx;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void init(int idx, int s, int e){
		if(s==e){
			seg[idx].mx = s;
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
		if(A[seg[seg[idx].l].mx] > A[seg[seg[idx].r].mx]){
			seg[idx].mx = seg[seg[idx].l].mx;
		}else{
			seg[idx].mx = seg[seg[idx].r].mx;
		}
		//seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	void Init(int x){
		SZ = x;
		seg.clear();
		add();
		init(0, 1, SZ);
	}
	int mx(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y){
			return seg[idx].mx;
		}else if(x>e || y<s){
			return -1;
		}
		int lidx = mx(seg[idx].l, s, (s+e)/2, x, y);
		int ridx = mx(seg[idx].r, (s+e)/2+1, e, x, y);
		if(lidx==-1)	return ridx;
		if(ridx==-1)	return lidx;
		if(A[lidx]<A[ridx])	return ridx;
		return lidx;
		//return max(mx(seg[idx].l, s, (s+e)/2, x, y), mx(seg[idx].r, (s+e)/2+1, e, x, y));
	}
	int Mx(int x, int y){
		return mx(0, 1, SZ, x, y);
	}
} Seg;

ll ans;

int main(){
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%lld", &A[i]);
		}
		Seg.Init(N);
		A[0] = A[N+1] = (ll)N;
		scanf("%lld", &M);

		while(!pq.empty()){
			pq.pop();
		}
		pq.push({N, {1, N}});
		while(!pq.empty()){
			int s = pq.top().second.first, e = pq.top().second.second;
			pq.pop();
			ll w = e-s+1;
			int H = min(A[s-1], A[e+1]);
			int m = Seg.Mx(s, e);
			int L = A[m];
			ll h = H-L;
			ll D = min(M, h*w);
			M-=D;
			ans+=(D-(D+w-1)/w);
			if(s<m-1){
				pq.push({m-s, {s, m-1}});
			}
			if(m+1<e){
				pq.push({e-m, {m+1, e}});
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}
