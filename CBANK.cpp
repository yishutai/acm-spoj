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
const int maxn = 333;
const int INF = 1<<30;
const int logN = 18;
LL POW(LL x,int y) {
	LL ret = 1;
	while(y) {
		if(y&1)ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y>>=1;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	int t;
	RI(t);
	LL i6 = POW(6,MOD-2);
	while(t--) {
		LL n;
		cin>>(n);
		LL ans = ((n+1)*(n+2))%MOD;
		ans = (ans*(n+3))%MOD;
		ans = (ans*i6)%MOD;
		OL(ans);
	}
}