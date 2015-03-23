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
const int maxn = 11111111;
const int INF = 1<<30;
int n,k;
int K[15];
LL gcd(LL a,LL b) {
	return b==0?a:gcd(b,a%b);
}
LL lcm(int i) {
	LL ret = 1;
	for(int j=0;j<k;++j)if(((1<<j) & i) > 0) {
		ret = (ret*(LL)K[j]) / gcd(ret,K[j]);
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	RII(n,k);
	REP(i,k)RI(K[i]);
	LL ans = n;
	for(int i=1; i<(1<<k);++i) {
		LL l = lcm(i);
		ans += (__builtin_popcount(i) % 2 ? -1 : 1) * ((LL)n/l);
	}
	OL(ans);
	return 0;
}