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
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    set<pair<int, int>> st;
    rep(i, 0, N){
        cin >> X[i] >> Y[i];
        st.insert(make_pair(X[i], Y[i]));
    }
    int ans = 0;
    rep(i, 0, N) rep(j, i+1, N){
        int x0 = X[i];
        int y0 = Y[i];
        int x1 = X[j];
        int y1 = Y[j];

        int dx = x1 - x0;
        int dy = y1 - y0;
        
        int x2 = x1 + dy;
        int y2 = y1 - dx;

        int x3 = x0 + dy;
        int y3 = y0 - dx;
        if (st.find(make_pair(x2, y2)) == st.end()) continue;
        if (st.find(make_pair(x3, y3)) == st.end()) continue;
        chmax(ans, dx*dx + dy*dy);
    }
    cout << ans << endl;
    return 0;
}