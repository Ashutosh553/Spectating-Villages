//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll inf=1e18;

int n;
ll tab[nax];
vi graf[nax];

ll dpjest[nax];
ll dpbylo[nax];
ll dp[nax];

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

void przep(int v, int u)
{
	
	dpjest[0]=dpjest[v];
	dpjest[v]=-inf;
	
	dpbylo[0]=dpbylo[v];
	dpbylo[v]=-inf;
	
	dp[0]=dp[v];
	dp[v]=-inf;
	
	maxi(dpjest[v], dpjest[0]+dpjest[u]);
	maxi(dpjest[v], dpjest[0]+dpbylo[u]);
	maxi(dpjest[v], dpjest[0]+dp[u]+tab[u]);
	
	maxi(dpbylo[v], dpbylo[0]+dpjest[u]);
	maxi(dpbylo[v], dpbylo[0]+dpbylo[u]);
	maxi(dpbylo[v], dpbylo[0]+dp[u]);
	
	maxi(dpbylo[v], dp[0]+dpjest[u]+tab[v]);
	maxi(dp[v], dp[0]+dpbylo[u]);
	maxi(dp[v], dp[0]+dp[u]);
}

void dfs(int v, int oj)
{
	dpbylo[v]=-inf;
	dp[v]=0;
	dpjest[v]=tab[v];
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		przep(v, i);
	}
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		graf[i].clear();
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0);
	printf("%lld\n", max(max(dp[1], dpjest[1]), dpbylo[1]));
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
