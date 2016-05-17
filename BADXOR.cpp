#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <climits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <iostream>
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
#define SZ(x) ((int)(x).size())
#define FIN(f) freopen(f,"r",stdin)
#define FOUT(f) freopen(f,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<int,int> PII;
const int MOD = 1e8+7;
const int maxn = 1111;
int n,m;
int a[maxn],b[maxn];
LL dp[maxn][1<<11];
int main(int argc, char const *argv[])
{
    int t;
    RI(t);
    for(int kase=1;kase<=t;++kase) {
        RII(n,m);
        REP(i,n)RI(a[i]);
        REP(i,m)RI(b[i]);
        ZERO(dp);
        dp[0][0] = 1;
        for(int i=0;i<n;++i) {
            for(int j=0;j<1<<11;++j) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
                dp[i+1][j ^ a[i]] += dp[i][j];
                if(dp[i+1][j ^ a[i]] >= MOD)
                    dp[i+1][j ^ a[i]]-=MOD;
            }
        }
        //OL(dp[n][0]);
        LL ans = 1;
        REP(i,n)ans = (ans*2L)%MOD;
        REP(i,m)ans = (ans + MOD - dp[n][b[i]])%MOD;
        printf("Case %d: ",kase);
        OL(ans);
        //printf("\n");
    }
    return 0;
}
