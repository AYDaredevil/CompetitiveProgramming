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

vector<int> Zalgo(string s)
{
	int L = -1, R = -1;
	vector<int> z(s.size() + 1);
	for (int i = 1; i < s.size(); i++)
	{
		if (i > R)
		{
			L = R = i;
			while (R < s.size() && s[R] == s[R - L])
				R++;
			z[i] = R - L;
			R--;
		}
		else
		{
			if (z[i - L] < R - i + 1)
				z[i] = z[i - L];
			else
			{
				L = i;
				while (R < s.size() && s[R - L] == s[R])
					R++;
				z[i] = R - L;
				R--;
			}
		}
	}
	z[0] = s.size();
	return z;
}

string y;
string x, pat;
ll n, memo[(int) 1e6 + 5][2];
vi vec;
int nxt[(int) 1e6 + 5];
const int mod = 1e9 + 7;

ll solve(int idx, bool f)
{
	if (idx == sz(x))
		return 1;
	if (memo[idx][f] != -1)
		return memo[idx][f];

	ll ret = 0;

	if (f)
	{
		ret = (solve(idx + 1, f) + solve(idx + 1, 0)) % mod;
		if (nxt[idx] != -1)
			ret = (ret + solve(nxt[idx], 1)) % mod;
	}
	else
	{
		if (nxt[idx] != -1)
			ret = solve(nxt[idx], 1);
		ret = (ret + solve(idx + 1, 0))%mod;
	}

	return memo[idx][f] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> pat;
	n = sz(pat);
	y = pat + "$" + x;

	vec = Zalgo(y);

	reset(memo, -1);
	int last = -1;

	for (int i = sz(x) - 1; i >= 0; i--)
	{
		if (vec[i + n + 1] == n)
			last = i + n;
		nxt[i] = last;
	}

	ll sum = 0;

	rep(i, 0, sz(x))
	{
		if (nxt[i] != -1)
			sum = (sum + solve(nxt[i], 1)) % mod;
	}
	cout << sum;
	return 0;
}
