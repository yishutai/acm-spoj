#include<bits/stdc++.h>
#define REP(i,n) for(int (i)=0;i<(int)(n);++(i))
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PB push_back
#define FT first
#define SD second
#define ZERO(x) memset(x,0,sizeof(x))
#define NEG(x) memset(x,-1,sizeof(x))
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d%d",&(x),&(y))
#define RIII(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define OIII(x,y,z) printf("%d %d %d\n",(x),(y),(z))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define OI(x) printf("%d\n",(x))
#define OL(x) cout<<(x)<<endl
#define OLL(x,y) cout<<(x)<<" "<<(y)<<endl
#define OLLL(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define RS(s) scanf("%s",(s))
#define MP(x,y) make_pair((x),(y))
#define FIN(f) freopen(f,"r",stdin)
#define FOUT(f) freopen(f,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<int,int> PII;
const int MOD = 1e9+7;
const int maxn = 11111;
const int INF = 1<<30;
const int logN = 18;
int n;
vector<PII> G[maxn];
int dep[maxn];
int dist[maxn];
int fa[logN][maxn];
void dfs(int x,int u,int l, int d) {
	dep[x] = l;
	dist[x] = d;
	fa[0][x] = u;
	for(int i=0;i<G[x].size();++i)if(G[x][i].FT!=u) {
		dfs(G[x][i].FT,x,l+1,d+G[x][i].SD);
	}
}
void build() {
	//puts("build");
	dfs(1,0,0,0);
	for(int i=1;i<logN;++i) {
		for(int j=1;j<=n;++j) {
			//OII(i,j);
			fa[i][j] = fa[i-1][fa[i-1][j]];
		}
	}
}
int climb(int x, int h) {
	//OII(x,h);
	int hh = 0;
	while(h) {
		if(h&1)x = fa[hh][x];
		hh++;
		h>>=1;
	}
	return x;
}
int lca(int u,int v) {
	if(dep[u] > dep[v]) swap(u,v);
	v = climb(v,dep[v]-dep[u]);
	//OII(u,v);
	int k = logN-1;
	while(u!=v) {
		while(fa[k][u]==fa[k][v]&&k>0)k--;
		u = fa[k][u];
		v = fa[k][v];
	}
	return u;
}
int main(int argc, char const *argv[])
{
	int t;
	RI(t);
	while(t--) {
		RI(n);
		REP(i,n)G[i+1].clear();
		REP(i,n-1) {
			int a,b,c;
			RIII(a,b,c);
			G[a].emplace_back(b,c);
			G[b].emplace_back(a,c);
		}
		build();
		char s[10];
		while(RS(s)) {
			if(s[1]=='O')break;
			int u,v,k;
			if(s[1]=='T') {
				RIII(u,v,k);
				int mid = lca(u,v);
				int ans = -1;
				//OIII(mid,k,dep[u] - dep[mid] + 1);
				if(k > dep[u] - dep[mid] + 1) {
					int dd = dep[u] + dep[v]  - 2*dep[mid] - k + 1;
					//OI(dd);
					ans = climb(v,dd);
				} else {
					ans = climb(u,k-1);
				}
				OI(ans);
			} else {
				RII(u,v);
				int mid = lca(u,v);
				//OI(mid);
				OI(dist[u] - dist[mid] + dist[v] - dist[mid]);
			}
		}
		puts("");
	}
	return 0;
}