#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

int main()
{
    int M;
    cin >> M;
    vector<tuple<int, int, int>> P;
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        P.push_back(make_tuple(a+b, a, b));
    }
    sort(all(P));
    int x0 = get<1>(P[0]);
    int y0 = get<2>(P[0]);
    vector<pair<int, int>> dif;
    rep(i, 1, M){
        int x1 = get<1>(P[i]);
        int y1 = get<2>(P[i]);
        int dx = x1 - x0;
        int dy = y1 - y0;
        dif.push_back(make_pair(dx, dy));
    }

    int N;
    cin >> N;
    set<pair<int, int>> st;
    
    rep(i, 0, N){
        int a, b;
        cin >> a >> b;
        st.insert(make_pair(a, b));
    }

    for (auto p: st){
        int x = p.first;
        int y = p.second;
        bool flag = true;
        for (auto q: dif){
            int dx = q.first;
            int dy = q.second;
            if (st.find(make_pair(x+dx, y+dy)) == st.end()){ flag = false; break; }
        }
        if (flag){
            cout << x - x0 << " " << y - y0 << endl;
            return 0;
        }
    }

    return 0;
}