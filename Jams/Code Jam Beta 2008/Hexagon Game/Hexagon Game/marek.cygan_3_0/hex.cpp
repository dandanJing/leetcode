#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<n; ++i)
#define FOR(var,pocz,koniec) for (int var=pocz; var<=koniec; ++var)
#define FORD(var,pocz,koniec) for (int var=pocz; var>=koniec; --var)
#define FOREACH(it, X) for(__typeof(X.begin()) it = X.begin(); it != X.end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()


VI Hungarian(int **w,int n){
  int lx[n],ly[n],skojx[n],skojy[n];
  int markx[n],marky[n],slack[n],par[n],q[n];
  REP(i,n){ skojx[i]=skojy[i]=-1; ly[i]=0; lx[i]=*max_element(w[i], w[i]+n); }
  REP(k,n){
    int v=-1,qb=0,qe=0;
    REP(i,n){ marky[i]=markx[i]=0; slack[i]=-1; if (skojx[i]==-1) q[qe++]=i;}
    while (v==-1){
      while (qb<qe){
        int i=q[qb++]; markx[i]=1;
        REP(j,n)
          if (!marky[j] && (slack[j]==-1 || slack[j]>lx[i]+ly[j]-w[i][j])){
            if ((slack[j] = lx[ par[j]=i ]+ly[j]-w[i][j]) == 0){
              marky[j]=1;
              if (skojy[j]!=-1) q[qe++]=skojy[j]; else {v=j; goto koniec;}
            }
          }
      }
      int x=-1; REP(i,n) if (!marky[i] && (x==-1 || slack[i] < x)) x=slack[i];
      REP(i,n){
        if (markx[i]) lx[i]-=x; 
        if (marky[i]) ly[i]+=x; else
          if ((slack[i] -= x) == 0){
            marky[i]=1; if (skojy[i] != -1) q[qe++]=skojy[i]; else v=i;
          }
      }
    }
koniec:
    while (v!=-1){int y=skojx[par[v]]; skojx[par[v]]=v; skojy[v]=par[v]; v=y;}
  }
  return VI(skojx,skojx+n);
}

const int K=110000;
char txt[K];
const int N=210;
int numer[N][N],dlugosci[N];
int pozycje[N];
int gdzie[N][2];
int dist[N][N];
int waga[N];

VI bfs(int wiersz,int kol,VPII cele){
  int n=SIZE(cele);
  VPII q;
  REP(i,n) REP(j,dlugosci[i]) dist[i][j]=-1;
  dist[wiersz][kol]=0;
  q.PB(MP(wiersz,kol));
#define ruch if (nwiersz>=0 && nwiersz<n && nkol>=0 && nkol<dlugosci[nwiersz] && dist[nwiersz][nkol]==-1) { \
    dist[nwiersz][nkol]=dist[wiersz][kol]+1; q.PB(MP(nwiersz,nkol)); \
  }

  REP(foo,SIZE(q)){
    wiersz=q[foo].ST;
    kol=q[foo].ND;

    int nwiersz,nkol;
    nwiersz=wiersz; nkol=kol-1; ruch
    nwiersz=wiersz; nkol=kol+1; ruch

    if (wiersz<=n/2){
      nwiersz=wiersz-1; nkol=kol-1; ruch
      nwiersz=wiersz-1; nkol=kol; ruch
    } else{
      nwiersz=wiersz-1; nkol=kol+1; ruch
      nwiersz=wiersz-1; nkol=kol; ruch
    }

    if (wiersz>=n/2){
      nwiersz=wiersz+1; nkol=kol-1; ruch
      nwiersz=wiersz+1; nkol=kol; ruch
    } else{
      nwiersz=wiersz+1; nkol=kol+1; ruch
      nwiersz=wiersz+1; nkol=kol; ruch
    }
  }
  VI res;
  REP(i,n) res.PB(dist[cele[i].ST][cele[i].ND]);
  return res;
}

LL licz(VPII v){
  int n=SIZE(v);
  int *w[n];
  int maxi=(n*n*2+1)**max_element(waga,waga+n);

  //printf("licz n=%d\n",n);
  //REP(i,n) printf("(%d,%d) ",v[i].ST,v[i].ND);
  //puts("");

  REP(i,n) w[i] = new int[n];
  REP(ktory,n){
    REP(i,n) REP(j,dlugosci[i]) if (numer[i][j]==pozycje[ktory]){
      gdzie[ktory][0]=i;
      gdzie[ktory][1]=j;
      goto hell;
    }
    assert(0);
hell:
    VI koszty=bfs(gdzie[ktory][0],gdzie[ktory][1],v);
    REP(i,n) w[ktory][i]=maxi-koszty[i]*waga[ktory];
  }

  VI skoj = Hungarian(w,n);
  LL res = 0LL; REP(i,n) res += w[i][skoj[i]];
  REP(i,n) delete[]w[i];
  res=n*maxi-res;
  //printf("res=%lld\n",res);
  //puts("");
  return res;
}

int main(){
  int testy;
  fgets(txt,K-1,stdin);
  sscanf(txt,"%d",&testy);
  REP(foo,testy){
    printf("Case #%d:",foo+1);
    int n=0;
    {
      fgets(txt,K-1,stdin);
      string s=txt;
      istringstream in(s);
      int x;
      while (in >> x) pozycje[n++]=--x;
    }

    {
      fgets(txt,K-1,stdin);
      string s=txt;
      istringstream in(s);
      REP(i,n) in >> waga[i];
    }
    int brzeg=(n+1)/2;
    int wiersze=0;
    int pola=0;
    FOR(i,brzeg,n){
      dlugosci[wiersze]=i;
      REP(j,i) numer[wiersze][j]=pola++;
      wiersze++;
    }
    FORD(i,n-1,brzeg){
      dlugosci[wiersze]=i;
      REP(j,i) numer[wiersze][j]=pola++;
      wiersze++;
    }

    const LL INF=1000000000LL*1000000000LL;
    LL res=INF;

    VPII v;
    int gora=n/2;
    v.clear(); REP(i,n) v.PB(MP(gora,i));
    res=min(res,licz(v));

    int pos=0;
    v.clear(); REP(i,n){
      v.PB(MP(i,pos));
      if (i<gora) pos++;
    }
    res=min(res,licz(v));

    pos=gora;
    v.clear(); REP(i,n){
      v.PB(MP(i,pos));
      if (i>=gora) pos--;
    }
    res=min(res,licz(v));
    printf(" %lld\n",res);
  }
  return 0;
}
