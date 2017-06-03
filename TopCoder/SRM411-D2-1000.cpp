/*
    imagine the rectangles as grids, and boarders as visited cells
    now try to flood from each non-visited cell and count the number of components
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



class HoleCakeCuts
{
public:
    bool visited[1000][1000];
    bool hor[1000];
    bool ver[1000];
    int ssz;

    int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts)
    {
        reset(visited, false);
        reset(hor, false);
        reset(ver, false);
        ssz = cakeLength*2;

        rep(i, 0, sz(horizontalCuts)) hor[horizontalCuts[i] + cakeLength - 1] = true;
        rep(i, 0, sz(verticalCuts)) ver[verticalCuts[i] + cakeLength - 1] = true;

        rep(i, cakeLength-holeLength, cakeLength+holeLength)
        {
            rep(j, cakeLength-holeLength, cakeLength+holeLength)
                visited[i][j] = true;
        }
        int ret = 0;
        rep(i, 0, 2*cakeLength)
        {
            rep(j, 0, 2*cakeLength)
            {
                if (!visited[i][j])
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        return ret;
    }

    void dfs(int i, int j)
    {
        if (visited[i][j])
            return;
        visited[i][j] = true;
        if (i > 0 && !ver[i - 1])
            dfs(i - 1, j);
        if (i < ssz - 1 && !ver[i])
            dfs(i + 1, j);
        if (j > 0 && !hor[j - 1])
            dfs(i, j - 1);
        if (j < ssz - 1 && !hor[j])
            dfs(i, j + 1);
    }

};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}";
    cout << "]" << endl;
    HoleCakeCuts *obj;
    int answer;
    obj = new HoleCakeCuts();
    clock_t startTime = clock();
    answer = obj->cutTheCake(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p4;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    vector <int> p2;
    vector <int> p3;
    int p4;

    {
    // ----- test 0 -----
    p0 = 5;
    p1 = 3;
    int t2[] = {1,-4};
    		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {1};
    		p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 6;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 10;
        p1 = 5;
        p2.clear();
        int t3[] = {-2,2};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 4;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
    // ----- test 2 -----
    p0 = 10;
    p1 = 5;
    int t2[] = {1};
    		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {-5,5};
    		p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 6;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }

    {
    // ----- test 3 -----
    p0 = 50;
    p1 = 5;
    int t2[] = {40,-40};
    		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {20,0,-20};
    		p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 12;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
