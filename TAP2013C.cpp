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
const int maxn = 33333;
const int INF = 1<<30;
int n,m;
LL d[maxn];
vector<int> G[maxn];
bool vis[maxn];
LL dfs(int x) {
	if(x==n)return d[x] = 1;
	if(vis[x])return d[x];
	vis[x] = 1;
	REP(i,G[x].size()){
		d[x] += dfs(G[x][i]);
	}
	return d[x];
}
LL dp[maxn];
LL dfs2(int x) {
	if(x==n) return 1;
	if(vis[x])return dp[x];
	vis[x] = 1;
	LL & ret = dp[x];
	REP(i,G[x].size()){
		ret = max(ret,dfs2(G[x][i]));
	}
	return ret+=d[x];	
}
int main(int argc, char const *argv[])
{
	RII(n,m);
	int a,b;
	REP(i,m) {
		RII(a,b);
		G[a].PB(b);
	}
	dfs(1);
	ZERO(vis);
	OL(dfs2(1));
	return 0;
}