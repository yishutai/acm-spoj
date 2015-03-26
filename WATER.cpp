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
const int maxn = 111;
const int INF = 1<<30;
int n,m;
int a[maxn][maxn];
int ans;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool r[maxn][maxn];
//bool inq[maxn][maxn];
bool ok(int x,int y) {
	return x>=0&&y>=0&&x<n&&y<m;
}
int main(int argc, char const *argv[])
{
	int t;
	RI(t);
	while(t--) {
		ZERO(r);
		RII(n,m);
		REP(i,n)REP(j,m)RI(a[i][j]);
		ans = 0;
		priority_queue< pair<int,PII> > pq;
		REP(i,n) {
			pq.push(MP(-a[i][0],MP(i,0)));
			r[i][0] = 1;
			pq.push(MP(-a[i][m-1],MP(i,m-1)));
			r[i][m-1] = 1;
		}
		REP(i,m) {
			pq.push(MP(-a[0][i],MP(0,i)));
			r[0][i] = 1;
			pq.push(MP(-a[n-1][i],MP(n-1,i)));
			r[n-1][i] = 1;
		}

		while(!pq.empty()) {
			PII p = pq.top().SD;
			int lev = -pq.top().FT;
			pq.pop();

			REP(i,4) {
				int nx = p.FT + dx[i];
				int ny = p.SD + dy[i];
				if(ok(nx,ny) && !r[nx][ny]) {
					if(a[nx][ny] < lev){
						ans += lev - a[nx][ny];
						a[nx][ny] = lev;
					}
					r[nx][ny] = 1;
					pq.push(MP(-a[nx][ny],MP(nx,ny)));
				}
			}
		}



		OI(ans);
	}
	return 0;
}