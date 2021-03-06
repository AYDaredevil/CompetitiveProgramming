#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvii;
typedef long double ld;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) { x, {y, z } }

const int N = 6005;
int n, res;
int arr[N], lis[N];

vvi node;

void dfs(int v, int p)
{
	int idx = lower_bound(lis, lis + n, arr[v]) - lis;
	res = max(res, idx + 1);

	int temp = lis[idx];
	lis[idx] = arr[v];
	for (auto i : node[v])
		if (i != p)
			dfs(i, v);
	lis[idx] = temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	node.resize(n + 1);
	erep(i, 1, n)
		cin >> arr[i];

	rep(i, 0, N)
		lis[i] = 1e9;

	rep(i, 0, n-1)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	erep(i, 1, n)
		if (sz(node[i]) == 1)
			dfs(i, 0);

	cout << res << endl;
	return 0;
}
