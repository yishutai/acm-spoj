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
const int MOD = 1e9+7;
const int maxn = 222222;
int n,q;
int a[maxn];
int rmq[22][maxn];
void pre() {
    for(int i=1;i<=n;++i)rmq[0][i] = a[i];
    for(int j=1;j<22;++j) 
        for(int i=1;i<=n;++i)if(i + (1<<(j)) - 1 <= n)
            rmq[j][i] = min(rmq[j-1][i],rmq[j-1][i + (1<<(j-1))]);
}
int get(int i, int j) {
    int k=0;
    while(i + (1<<(k+1)) -1 <= j)++k;
    return min(rmq[k][i], rmq[k][j - (1<<k) + 1]);
}
int main(int argc, char const *argv[])
{
    int t;
    RI(t);
    REP(kase, t) {
        RII(n,q);
        REP(i,n)RI(a[i+1]);
        pre();
        printf("Scenario #%d:\n", kase+1);
        while(q--) {
            int a,b;
            RII(a,b);
            OI(get(a,b));
        }
    }
    return 0;
}