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
const int maxn = 2222222;
int n;
int x[maxn];
int a,b,c;
vector<LL> M, B;
LL dp[maxn];


int ptr = 0;
LL query(LL x) {
    ptr = min(ptr, SZ(M)-1);
    while(ptr < M.size()-1 && M[ptr]*x + B[ptr] < M[ptr+1]*x + B[ptr+1]) ptr++;
    return M[ptr] * x + B[ptr];
}

bool ok(LL m, LL b, int l2, int l3) {
    return (B[l2]-b) * (M[l2] - M[l3]) < (B[l3]-B[l2]) * (m - M[l2]);
}

void ins(LL m, LL b) {
    while(M.size() >= 2 && ok(m, b, M.size()-1, M.size()-2)) {
        M.pop_back();
        B.pop_back();
    }
    M.PB(m);
    B.PB(b);
}
LL sum[maxn];
int main(int argc, char const *argv[])
{
    int t;
    RI(t);
    while(t--) {
        M.clear();
        B.clear();
        ZERO(sum);
        ZERO(dp);
        ptr = 0;

        RI(n);
        RIII(a,b,c);
        for(int i=1;i<=n; ++i) {
            RI(x[i]);
            sum[i] = sum[i-1] + x[i];
        }

        dp[1] = a * x[1] * x[1] + b * x[1] + c;
        ins(-2 * a * sum[1], dp[1] + a*sum[1]*sum[1] - b * sum[1]);

        for(int i=2;i<=n;++i) {
            dp[i] = a * sum[i] * sum[i] + b * sum[i] + c;
            dp[i] = max(dp[i], a * sum[i] * sum[i] + b * sum[i] + c + query(sum[i]));
            ins(-2 * a * sum[i], dp[i] + a*sum[i]*sum[i] - b * sum[i]);
        }
        OL(dp[n]);

    }
    return 0;
}