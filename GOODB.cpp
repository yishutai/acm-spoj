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
// Preprocess factorial , inverse , inverse Factorial in O(n)
LL fac[maxn],ifac[maxn];
LL inv[maxn];
void pre() {
    fac[0] = ifac[0] = 1;
    fac[1] = ifac[1] = 1;
    inv[1] = inv[0] = 1;
    for(int i=2;i<maxn;++i) {
        fac[i] = (fac[i-1] * i)%MOD;
        inv[i] = (MOD - (MOD/i) * inv[MOD%i]%MOD)%MOD;
        ifac[i] = (ifac[i-1]*inv[i])%MOD;
    }
}
int main(int argc, char const *argv[])
{
	pre();
	int n,w,t,r;
	RII(n,w);RII(t,r);
	LL ans = (((((fac[n]*ifac[w])%MOD)*ifac[t])%MOD)*ifac[r])%MOD;
	OL(ans);
	return 0;
}