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
const int maxn = 111111;
const int INF = 1<<30;
int n;
vector<PII> G[maxn];
int dfs(int x,int u,int& md,int w) {
	//OIII(x,u,md);
	int r = 0,m1 = 0,m2 = 0;
	//md = lev;
	REP(i,G[x].size())if(G[x][i].FT!=u) {
		int dd=0;
		r = max(r,dfs(G[x][i].FT,x,dd,G[x][i].SD));
		if(dd >= m1){
			m2 = m1;
			m1 = dd;
		}
		else if(dd>m2) {
			m2 = dd;
		}
	}
	//OII(x,m1+1);
	md = m1+w;
	r = max(r,m1+m2);
	//OII(x,md);
	return r;
}
int main(int argc, char const *argv[])
{
	/* code */
	int t;
	RI(t);
	while(t--) {
		RI(n);
		REP(i,n)G[i].clear();
		int a,b;
		REP(i,n-1) {
			RII(a,b);
			G[a].PB(MP(b,1));
			G[b].PB(MP(a,1));
		}
		int dd=0;
		OI((dfs(0,-1,dd,0)+1)/2);
	}
	return 0;
}