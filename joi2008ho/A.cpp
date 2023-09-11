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
    int last = -1;
    
    vector<int> par(N);
    rep(i, 0, N) par[i] = i;

    rep(i, 0, N){
        int c;
        cin >> c;
        if (i == 0) { last = c; continue; }
        if (i % 2){
            if (last == c){
                par[i] = par[i-1];
            }else{
                int now = i;
                par[now] = par[now-1];
                int nex = par[now-1];
                while (nex != par[nex]){
                    int temp = nex;
                    nex = par[nex];
                    par[temp] = nex;
                }

                if (nex-1 >= 0){
                    par[nex] = par[nex-1];
                }
            }
        }else{
            if (last == c){
                par[i] = par[i-1];
            }
        }
        last = c;
    }

    vector<int> S(N);
    rrep(i, N-1, 0){
        if (par[i] == i){
            S[i] = last;
            last += 1;
            last %= 2;
        }else{
            S[i] = last;
        }
    }

    int ans = 0;
    rep(i, 0, N){
        if (S[i] == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}