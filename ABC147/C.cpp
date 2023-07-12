#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> A(N, vector<pair<int, int>>());

    rep(i, 0, N){
        int a;
        cin >> a;
        rep(j, 0, a){
            int x, y;
            cin >> x >> y;
            x--;
            A[i].push_back(make_pair(x, y));
        }
    }

    int ans = 0;
    rep(k, 0, 1<<N){
        vector<int> v(N, -1);
        int cnt = 0;
        bool flag = true;
        rep(i, 0, N){
            if (k & (1<<i)){
                v[i] = 1;
            }else{
                v[i] = 0;
            }
        }
        rep(i, 0, N){
            if (k & (1<<i)){
                cnt++;
                for (auto p: A[i]){
                    auto x = p.first;
                    auto y = p.second;
                    if (v[x] != y){
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag){
            chmax(ans, cnt);
        }
    }

    cout << ans << endl;



    return 0;
}