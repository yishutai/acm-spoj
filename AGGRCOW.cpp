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
int t,n,c;
int a[maxn];
bool ok(int m) {
    int j = 1,p = 0;
    for(int i=1;i<c;++i) {
        while(j < n && a[j]-a[p] < m)j++;
        if(j==n)return 0;
        p = j;
        j++;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    RI(t);
    while(t--) {
        RII(n,c);
        REP(i,n) {
            RI(a[i]);
        }
        sort(a,a+n);
        int L = 0, R = a[n-1] - a[0];
        while(R>L) {
            int M = L + (R-L) / 2;
            if(ok(M)) L = M+1;
            else R = M;
        }
        OI(L-1);
    }
    return 0;
}