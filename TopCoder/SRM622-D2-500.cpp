/*
    store all powers of two in a range upto 1e6
    for each candyCount, place in the first box it could fit in
    accumulate all box sizes
    place them in the first box they can fit in and return the answer
    
*/
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

class BoxesDiv2
{
public:
    int findSize(vector <int> candyCounts)
    {
        vi hoba;
        rep(i, 0, 21) hoba.push_back(1<<i);
        vi boxes;
        int n = sz(candyCounts);
        rep(i, 0, n)
            boxes.push_back(*lower_bound(all(hoba), candyCounts[i]));
        int sum = 0;
        rep(i, 0, n) sum += boxes[i];
        return *lower_bound(all(hoba), sum);
    }
};

