#include <bits/stdc++.h>

/*

    first, get the center of the circle
    second, difuse each cell into 4 points (upper left, upper right, lower left, lower right) 
    calculate the distance from center to all 4 points
    if the distance to all points are <= radius then it's inside
    if the distance of 1 point <= radius then a segment of the cell is inside
    else nothing happens

*/

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



double INF = 1e100;
double EPS = 1e-7;

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
    bool operator<(const PT &p)  const
    {
        return make_pair(x,y)<make_pair(p.x,p.y);
    }
    bool operator==(const PT &p)  const
    {
        return !(*this < p) && !(p < *this);
    }
};
double dot(PT p, PT q)
{
    return sqrt(p.x*q.x+p.y*q.y);
}
double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
PT norm(PT x, double l)
{
    return x * sqrt(l*l / dot(x,x));
}
istream &operator>>(istream &is, PT &p)
{
    return is >> p.x >> p.y;
}
ostream &operator<<(ostream &os, const PT &p)
{
    return os << "(" << p.x << "," << p.y << ")";
}
/*around the origin*/
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
// project point c onto line through a and b (assuming a != b)
PT ProjectPointLine(PT a, PT b, PT c)
{
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
// project point c onto line segment through a and b (assuming a != b)
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(c-a, b-a)/dot(b-a,b-a);
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

int main()
{
    output;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    double n;
    bool flag = false;
    while(cin >> n)
    {
        if (flag) cout << endl;
        flag = true;
        double d = (2*n - 1)/ 2;
        int all = 0, some = 0;
        PT center(n+1, n+1);
        erep(i, 1, 2*n)
        {
            erep(j, 1, 2*n)
            {
                PT p1(i, j), p2(i, j+1), p3(i+1, j), p4(i+1, j+1);
                if (dist2(center, p1) <= d && (dist2(center, p2) <= d) && (dist2(center, p3) <= d) && (dist2(center, p4) <= d) )
                {
                    all++;
                }
                else if (dist2(center, p1) <= d || (dist2(center, p2) <= d) || (dist2(center, p3) <= d) || (dist2(center, p4) <= d)) some++;
            }
        }
        cout << "In the case n = " << n << ", " << some << " cells contain segments of the circle.\n";
        cout << "There are " << all << " cells completely contained in the circle.\n";
    }

    return 0;
}
