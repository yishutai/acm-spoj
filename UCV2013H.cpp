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
int bfs(int x,int y) {
	queue<PII> q;
	q.push(MP(x,y));
	int ret = 0;
	while(!q.empty()) {
		int xx = q.front().FT;
		int yy = q.front().SD;
		q.pop();
		if(a[xx][yy] == 1){
			ret++;
			a[xx][yy] = 0;
		} else continue;
		REP(i,4) {
			int nx = xx+dx[i];
			int ny = yy+dy[i];
			if(ok(nx,ny) && a[nx][ny] == 1) {
				q.push(MP(nx,ny));
			}
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	while(RII(n,m)==2) {
		if(n==0 || m== 0)break;
		REP(i,n)REP(j,m)RI(a[i][j]);
		map<int,int> mm;
		int ans = 0;
		REP(i,n)REP(j,m)if(a[i][j] == 1){
			int sz = bfs(i,j);
			if(sz>0) {
				ans++;
				mm[sz]++;
			}
		}
		OI(ans);
		REPIT(mm,itr)OII(itr->FT,itr->SD);
	}
	return 0;
}