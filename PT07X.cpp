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
const int MOD = 761238923;
const int maxn = 111111;
const int INF = 1<<30;
const int logN = 18;
int n;
vector<int> G[maxn];
int dp[maxn][2];
int mem(int x,int ch,int p) {
	if(dp[x][ch]!=-1)return dp[x][ch];
	int & ret = dp[x][ch];
	ret = ch;
	if(ch==0) {
		int s1 = 0;
		for(int i=0;i<G[x].size();++i)if(G[x][i]!=p) {
			s1 += mem(G[x][i],1,x);
		}
		ret += s1;
	}
	else if(ch) {
		int s2 = 0;
		for(int i=0;i<G[x].size();++i)if(G[x][i]!=p) {
			s2 += min(mem(G[x][i],0,x),mem(G[x][i],1,x));
		}
		ret += s2;
	}

	//ret += min(s1,s2);
	return ret;
}
int main(int argc, char const *argv[])
{
	RI(n);
	REP(i,n-1) {
		int a,b;
		RII(a,b);
		G[a].PB(b);
		G[b].PB(a);
	}
	NEG(dp);
	OI(min(mem(1,0,0),mem(1,1,0)));
	return 0;
}