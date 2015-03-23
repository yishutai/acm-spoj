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
const int maxn = 1111;
const int INF = 1<<30;
vector<LL> p;
bool vis[100000];
LL POW(LL x,int y) {
	LL ret = 1;
	for(int i=0;i<y;++i)
		ret*=x;
	return ret;
}
int main(int argc, char const *argv[])
{
	for(int i=2;i<100000;++i)if(!vis[i]) {
		p.PB((LL)i);
		for(int j=i+i;j<100000;j+=i)vis[j] = 1;
	}
	int t;
	RI(t);
	while(t--) {
		LL m,n;
		cin>>(m)>>(n);
		//vector<int> f1(p.size(),0),f2(p.size(),0);
		LL ans = 1;
		REP(i,p.size()){
			int a=0,b=0;
			while(m%p[i] == 0) {
				m/=p[i];
				a++;
			}
			while(n%p[i] == 0) {
				n/=p[i];
				b++;
			}
			if(a!=b) {
				// Only different a,b should be contain in k
				ans *= POW(p[i],max(a,b));
			}
		}
		//OLL(m,n);
		if(m!=n) {
			if(m>1)ans*=m;
			if(n>1)ans*=n;
		}
		OL(ans);

	}


	return 0;
}