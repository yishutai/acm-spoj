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
const int BIT_MAX = 10000001;
int BIT[BIT_MAX];
void ins(int x,int v) {
    while(x<BIT_MAX){
        BIT[x] += v;
        x+=x&-x;
    }
}
int get(int x) {
    int ret = 0;
    while(x>0) {
        ret += BIT[x];
        x -= x&-x;
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int t;
    RI(t);
    while(t--) {
        int n;
        RI(n);
        ZERO(BIT);
        LL ans = 0;
        REP(i,n) {
            int x;
            RI(x);
            ans += i - get(x-1);
            ins(x,1);
        }
        OL(ans);
    }   
    return 0;
}