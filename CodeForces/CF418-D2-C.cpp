#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int memo[1501][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string x;
    cin >> n >> x;

    rep(a, 0, 26)
    {
        rep(i, 0, n)
        {
            int cnt = 0;
            rep(j, i, n)
            {
                if (x[j] != a+'a') cnt++;
                memo[cnt][a] = max(memo[cnt][a], j-i+1);
            }
        }
        erep(i, 1, n)
        {
            memo[i][a] = max(memo[i][a], max(i, memo[i-1][a]));
        }
    }
    int m;
    cin >> m;
    while(m--)
    {
        int a;
        cin >> a;
        char c;
        cin >> c;
        cout << memo[a][c-'a'] << endl;
    }

    return 0;
}
