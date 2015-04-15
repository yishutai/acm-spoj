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
vector<int> p;
bool vis[1111111];
int main(int argc, char const *argv[])
{
	for(int i=2;i<=1000000;++i)if(!vis[i]) {
		p.PB(i);
		for(int j=i+i;j<=1000000;j+=i)vis[j] = 1;
	}
	int t = 0;
	int a,b;
	while(RII(a,b)==2) {
		if(a==0&&b==0)break;
		int d = 0,x = 0;
		for(int i=0;i<p.size();++i) {
			if(a%p[i]==0 || b%p[i] == 0) {
				x++;
				int x1=0,x2=0;
				while(a%p[i] == 0) {
					a/=p[i];
					x1++;
				}
				while(b%p[i] == 0) {
					b/=p[i];
					x2++;
				}
				d += abs(x1-x2);
			}
		}
		printf("%d. %d:%d\n",++t,x,d);
	}
	return 0;
}