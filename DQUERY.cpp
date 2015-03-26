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
const int maxn = 33333;
const int INF = 1<<30;
int n,m;
int a[maxn];
int sq;
struct q{
	int l,r,k,id;
	bool operator<(const q& rr)const {
		return (l)/sq < (rr.l)/sq || (l)/sq == (rr.l)/sq && r>rr.r;
	}
}qq[222222];
int A[222222];

bool ok(int x,int l,int r) {
	//OIII(x,l,r);
	return x>=l&&x<=r;
}
int cnt[1111111];
int main(int argc, char const *argv[])
{
	RI(n);
	sq = sqrt(n);
	//int cx = 1;
	REP(i,n){
		RI(a[i]);
	}
	RI(m);
	REP(i,m) {
		RII(qq[i].l,qq[i].r);
		qq[i].l--;
		qq[i].r--;
		qq[i].id = i;
	}
	sort(qq,qq+m);
	int ll = qq[0].l, rr = qq[0].r;
	int ans = 0;
	map<int,int> mm;
	for(int i=qq[0].l;i<=qq[0].r;++i){
		if(!cnt[a[i]])ans++;
		cnt[a[i]]++;
	}
	REP(i,m){
		//printf("%d %d\n",ll,qq[i].l);
		//OII(qq[i].r,rr);
		if(ll < qq[i].l){
			for(int j = ll;j<qq[i].l;++j)if(ok(j,ll,rr)){
				cnt[a[j]]--;
				if(cnt[a[j]]<=0)ans--;
			} else {
				//break;
			}
		}
		else if(ll>qq[i].l){
			for(int j = ll-1;j>=qq[i].l;--j)if(ok(j,qq[i].l,qq[i].r)){
				if(!cnt[a[j]])ans++;
				cnt[a[j]]++;
			} else;
		}
		if(rr < qq[i].r){
			for(int j = rr+1;j<=qq[i].r;++j)if(ok(j,qq[i].l,qq[i].r)) {
				if(!cnt[a[j]])ans++;
				cnt[a[j]]++;
			} else;
		}
		else if(rr>qq[i].r){
			//printf("Tes");
			for(int j = rr;j>qq[i].r;--j)if(ok(j,ll,rr)) {
				//printf("delete %d\n",a[i]);
				cnt[a[j]]--;
				if(cnt[a[j]]<=0)ans--;		
			} else {
				//break;
			}
		}

		ll = qq[i].l;rr = qq[i].r;
		//OIII(mm[1],mm[2],mm[3]);
		A[qq[i].id] = ans;
	}
	REP(i,m) OI(A[i]);
	return 0;
}