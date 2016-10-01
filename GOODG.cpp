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
#include <cassert>
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
const int MOD = 1e9+7;
const int maxn = 1111111;
int n;
int a[maxn],d[maxn];
LL dp[maxn];
vector<LL> M, B;
LL query(LL x) {
    while(SZ(M)>1 && M[SZ(M)-1] * x + B[SZ(B)-1] <= M[SZ(M)-2] * x + B[SZ(B)-2]){
        M.pop_back();
        B.pop_back();
    }
    return M[SZ(M)-1] * x + B[SZ(B)-1];
}

void ins(LL m, LL b) {
    M.PB(m);
    B.PB(b);
}


int main(int argc, char const *argv[])
{
    RI(n);
    REP(i,n) RII(a[i+1],d[i+1]);

    ins(-d[1],a[1] + d[1]);
    for(int i=2;i <= n+1;++i) {
        dp[i] = max(query(i), 0LL);
        ins(-(LL)d[i], dp[i] + (LL)a[i] + (LL)i * (LL)d[i]);
    }

    OL(dp[n+1]);

    return 0;
}