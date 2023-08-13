#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
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
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<tuple<int, int, char>> query;
    
    int last = N;
    int mode = 0;

    rep(i, 0, Q){
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        query.push_back({t, x, c});
        if (t != 1) { last = i; mode = t; }
    }

    vector<char> ans(N);
    rep(i, 0, N) ans[i] = S[i];
    rep(i, 0, last){
        auto tp = query[i];
        int t = get<0>(tp);
        if (t != 1) continue;
        int x = get<1>(tp);
        char c = get<2>(tp);
        ans[x] = c;
    }

    rep(i, 0, N){
        if (mode == 2){
           ans[i] = tolower(ans[i]);
        }else if (mode == 3){
            ans[i] = toupper(ans[i]);
        }
    }

    rep(i, last, Q){
        auto tp = query[i];
        int t = get<0>(tp);
        if (t != 1) continue;
        int x = get<1>(tp);
        char c = get<2>(tp);
        ans[x] = c;
    }

    rep(i, 0, N){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}