/*
    get all densities and minimize over each one, return minimum answer
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}



class CandyMaking
{
public:
    double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight)
    {
        double mn = DBL_MAX;
        vector<double> vec;
        rep(i, 0, sz(containerVolume))
        {
            vec.push_back((double)desiredWeight[i] / (double)containerVolume[i]);
        }
        rep(i, 0, sz(vec))
        {
            double sum = 0;
            rep(j, 0, sz(containerVolume))
            {
                sum += fabs((double)desiredWeight[j] - (double)(vec[i]*containerVolume[j]));
            }
            mn = min(mn, sum);
        }
        return mn;
    }
};
