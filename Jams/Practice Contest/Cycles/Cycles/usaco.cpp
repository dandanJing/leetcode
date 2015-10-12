<<<<<<< HEAD
#pragma warning(disable : 4018)
#include <map>
#include <assert.h>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include "top.h"

#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
#endif

using namespace std;

#define FOR(iter, bound) for(size_t iter=0; iter < (bound); iter++)
#define SFOR(iter, start, bound) for (int iter = (start); iter<(bound); iter++)
#define ALL(C) C.begin(), C.end()
#define VSORT(vec) sort(ALL(vec))
#define MP(a, b) make_pair((a), (b))

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<int> VI;
typedef vector<lint> VL;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef vector<VP> VVP;

static int case_num=1;
VS Parse(string str, string look_for = " ", bool i_push_empty = false)
{
    VS ans;
    if (look_for.length() == 0)
    {
        ans.push_back(str);
        return ans;
    };
    string last = "";
    int pos = 0;
    while (true)
    {
        if (pos == str.length())
        {
            if (last.length() != 0)
                ans.push_back(last);
            return ans;
        };
        if (look_for.find(str[pos]) == string::npos)
            last.append(1, str[pos]);
        else
        {
            if (i_push_empty || last.length() != 0)
                ans.push_back(last);
            last = "";
        };
        pos++;
    };
    return ans;
};



template<class C>
void PRV(vector<C> vec)
{
    cout << "{";
    FOR(i, vec.size()) {cout << vec[i] << ",";};
    cout << "}";
};


lint GetLint(string ss)
{
    lint ans = 0;
    int pos = 0;
    while (pos < ss.length() && !isdigit(ss[pos]))
        pos++;
    while (pos < ss.length() && isdigit(ss[pos]))
        ans *= lint(10), ans += lint(ss[pos++] - '0');
    return ans;
}

int ones(int k) {
    return k ? 1 + ones(k & (k - 1)) : 0;
}


int N, K;
VI s, f;
int M;
VI inv;
VVI rrr;

VI trt(VI& a, int mask) {
    VI ans;
    FOR(i, K)
        if ((1 << i) & mask)
            ans.push_back(a[i]);
    return ans;
}

void arr(VI& a, VI& b, int ind) {
    if (a[ind] > b[ind])
        swap(a[ind], b[ind]);
}

int razb(int A, int B) {
    int& ans = rrr[A][B];
    if (ans != -1)
        return ans;
    ans = 0;
    if (A == 0 || B == 1)
        return ans = 1;
    FOR(i, A + 1)
        ans = (ans + razb(A - i, B - 1)) % M;
    return ans;
}


int solve(int mask) {
    int V = N;
    int R = ones(mask);
    if (R == 0) {
        int ans= 1;
        FOR(i, V)
            ans = (ans * (i + 1)) % M;
        ans *= inv[(2 * V) % M];
        return ans % M;
    }
        
    VI vx = trt(s, mask);
    VI vy = trt(f, mask);
    VI order(N, 0);
    FOR(i, R)
        order[vx[i]]++, order[vy[i]]++;
    FOR(i, N)
        if (order[i] > 2)
            return 0;
    FOR(i, R)
        arr(vx, vy, i);
    int elim = 0;
    FOR(q, R) FOR(i, R) if (vx[i] != -1) FOR(j, i) if (vx[j] != -1) {
        bool ok = false;
        if (vx[i] == vx[j]) {
            if (vy[i] == vy[j])
                return (elim == N - 2) ? 1 : 0;
            ok = true;
            vx[i] = vy[j];
        } else {
            if (vy[i] == vy[j]) {
                ok = true;
                vy[i] = vx[j];
           } else
               if (vx[i] == vy[j]) {
                   ok = true;
                   vx[i] = vx[j];
               } else 
                   if (vy[i] == vx[j]) {
                       ok = true;
                       vy[i] = vy[j];
                   }
        }
         if (ok) {
            arr(vx, vy, i);
            vx[j] = vy[j] = -1;
            elim++;
        }
    }
    V -= elim;
    R -= elim;
    int ans = (1 << R);
    ans %= M;
    FOR(i, V - 2*R)
        ans = (ans * (i + 1)) % M;
    FOR(i, R)
        ans = (ans * (i + 1)) % M;
    ans *= razb(V - 2*R, R);
    ans %= M;
    ans *= inv[(2 * R) % M];
    return ans % M;
}
FILE* out;
void ff() {
    M = 9901;
    int T = 0;

    rrr = VVI(N + 1, VI(K + 1, -1));

    inv = VI(M);
    SFOR(i, 1, M)
        FOR(j, M)
        if ((i * j) % M == 1) {
            inv[i] = j;
            break;
        }
	int edge_index=1;
    FOR(i, (1 << K)) {
        int t = solve(i);
        int oo = ones(i);
		if(!COUNT_VALUE){
		  // if(oo==EDGE_NUM&&t) printf(" edge_index:%i value:%i index value:%i \n",edge_index++,t,i);
		}else {
			if(oo==EDGE_NUM&&t&&t==TEMP_VALUE) printf(" edge_index:%i value:%i index value:%i\n",edge_index++,t,i);
		}
        if ((oo % 2) == 0)
            T += t;
        else
            T += (M - t);
        T %= M;
    }

	fprintf(out,"Case #%i: %i\n",case_num,(T % M));
	cout << "Case #" << case_num++ << ": ";
    cout << (T % M)<<endl;
}

void usaco() {
	FILE * in = fopen("C-small-practice.in","r");
    //FILE * in = fopen("test.txt","r");
    out = fopen(("usaco.out"), "w+");

    int T;
	cout << "\n---------------usaco---------------------"<<endl;
	fscanf(in,"%i",&T);
    FOR(q, T) {
		fscanf(in,"%i  %i",&N, &K);
        s = VI(K);
        f = VI(K);
        FOR(i, K) {
            int x; int y;
			fscanf(in,"%i %i",&x,&y);
            s[i] = x - 1;
            f[i] = y - 1;
        }

        //cout << "Case #" << (q + 1) << ": ";
        ff();
    }
    fclose(in);
    fclose(out);
}
=======
#pragma warning(disable : 4018)
#include <map>
#include <assert.h>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include "top.h"

#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
#endif

using namespace std;

#define FOR(iter, bound) for(size_t iter=0; iter < (bound); iter++)
#define SFOR(iter, start, bound) for (int iter = (start); iter<(bound); iter++)
#define ALL(C) C.begin(), C.end()
#define VSORT(vec) sort(ALL(vec))
#define MP(a, b) make_pair((a), (b))

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<int> VI;
typedef vector<lint> VL;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef vector<VP> VVP;

static int case_num=1;
VS Parse(string str, string look_for = " ", bool i_push_empty = false)
{
    VS ans;
    if (look_for.length() == 0)
    {
        ans.push_back(str);
        return ans;
    };
    string last = "";
    int pos = 0;
    while (true)
    {
        if (pos == str.length())
        {
            if (last.length() != 0)
                ans.push_back(last);
            return ans;
        };
        if (look_for.find(str[pos]) == string::npos)
            last.append(1, str[pos]);
        else
        {
            if (i_push_empty || last.length() != 0)
                ans.push_back(last);
            last = "";
        };
        pos++;
    };
    return ans;
};



template<class C>
void PRV(vector<C> vec)
{
    cout << "{";
    FOR(i, vec.size()) {cout << vec[i] << ",";};
    cout << "}";
};


lint GetLint(string ss)
{
    lint ans = 0;
    int pos = 0;
    while (pos < ss.length() && !isdigit(ss[pos]))
        pos++;
    while (pos < ss.length() && isdigit(ss[pos]))
        ans *= lint(10), ans += lint(ss[pos++] - '0');
    return ans;
}

int ones(int k) {
    return k ? 1 + ones(k & (k - 1)) : 0;
}


int N, K;
VI s, f;
int M;
VI inv;
VVI rrr;

VI trt(VI& a, int mask) {
    VI ans;
    FOR(i, K)
        if ((1 << i) & mask)
            ans.push_back(a[i]);
    return ans;
}

void arr(VI& a, VI& b, int ind) {
    if (a[ind] > b[ind])
        swap(a[ind], b[ind]);
}

int razb(int A, int B) {
    int& ans = rrr[A][B];
    if (ans != -1)
        return ans;
    ans = 0;
    if (A == 0 || B == 1)
        return ans = 1;
    FOR(i, A + 1)
        ans = (ans + razb(A - i, B - 1)) % M;
    return ans;
}


int solve(int mask) {
    int V = N;
    int R = ones(mask);
    if (R == 0) {
        int ans= 1;
        FOR(i, V)
            ans = (ans * (i + 1)) % M;
        ans *= inv[(2 * V) % M];
        return ans % M;
    }
        
    VI vx = trt(s, mask);
    VI vy = trt(f, mask);
    VI order(N, 0);
    FOR(i, R)
        order[vx[i]]++, order[vy[i]]++;
    FOR(i, N)
        if (order[i] > 2)
            return 0;
    FOR(i, R)
        arr(vx, vy, i);
    int elim = 0;
    FOR(q, R) FOR(i, R) if (vx[i] != -1) FOR(j, i) if (vx[j] != -1) {
        bool ok = false;
        if (vx[i] == vx[j]) {
            if (vy[i] == vy[j])
                return (elim == N - 2) ? 1 : 0;
            ok = true;
            vx[i] = vy[j];
        } else {
            if (vy[i] == vy[j]) {
                ok = true;
                vy[i] = vx[j];
           } else
               if (vx[i] == vy[j]) {
                   ok = true;
                   vx[i] = vx[j];
               } else 
                   if (vy[i] == vx[j]) {
                       ok = true;
                       vy[i] = vy[j];
                   }
        }
         if (ok) {
            arr(vx, vy, i);
            vx[j] = vy[j] = -1;
            elim++;
        }
    }
    V -= elim;
    R -= elim;
    int ans = (1 << R);
    ans %= M;
    FOR(i, V - 2*R)
        ans = (ans * (i + 1)) % M;
    FOR(i, R)
        ans = (ans * (i + 1)) % M;
    ans *= razb(V - 2*R, R);
    ans %= M;
    ans *= inv[(2 * R) % M];
    return ans % M;
}
FILE* out;
void ff() {
    M = 9901;
    int T = 0;

    rrr = VVI(N + 1, VI(K + 1, -1));

    inv = VI(M);
    SFOR(i, 1, M)
        FOR(j, M)
        if ((i * j) % M == 1) {
            inv[i] = j;
            break;
        }
	int edge_index=1;
    FOR(i, (1 << K)) {
        int t = solve(i);
        int oo = ones(i);
		if(!COUNT_VALUE){
		  // if(oo==EDGE_NUM&&t) printf(" edge_index:%i value:%i index value:%i \n",edge_index++,t,i);
		}else {
			if(oo==EDGE_NUM&&t&&t==TEMP_VALUE) printf(" edge_index:%i value:%i index value:%i\n",edge_index++,t,i);
		}
        if ((oo % 2) == 0)
            T += t;
        else
            T += (M - t);
        T %= M;
    }

	fprintf(out,"Case #%i: %i\n",case_num,(T % M));
	cout << "Case #" << case_num++ << ": ";
    cout << (T % M)<<endl;
}

void usaco() {
	FILE * in = fopen("C-small-practice.in","r");
    //FILE * in = fopen("test.txt","r");
    out = fopen(("usaco.out"), "w+");

    int T;
	cout << "\n---------------usaco---------------------"<<endl;
	fscanf(in,"%i",&T);
    FOR(q, T) {
		fscanf(in,"%i  %i",&N, &K);
        s = VI(K);
        f = VI(K);
        FOR(i, K) {
            int x; int y;
			fscanf(in,"%i %i",&x,&y);
            s[i] = x - 1;
            f[i] = y - 1;
        }

        //cout << "Case #" << (q + 1) << ": ";
        ff();
    }
    fclose(in);
    fclose(out);
}
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
