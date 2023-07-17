#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

const double pi = 3.141592653589793;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

using mint = modint1000000007;

int main()
{
    int N;
    cin >> N;
    vector<string> S(2);
    cin >> S[0] >> S[1];

    vector<int> p(N, -1); 

    rep(j, 0, N){
        if (p[j] != -1) continue;
        if (j+1<N &&S[0][j] == S[0][j+1]){
            p[j] = 0;
            p[j+1] = 0;
        }else{
            p[j] = 1;
        }
    }

    vector<int> cnt(N);
    int pos = 0;
    while (pos < N){
        if (pos == 0){
            if (p[pos] == 0){
                cnt[pos] = 6;
                cnt[pos+1] = 1;
                pos += 2;
            }else{
                cnt[pos] = 3;
                pos += 1;
            }            
            continue;
        }else{
            if (p[pos] == 0){
                if (p[pos-1] == 0){
                    cnt[pos] = 3;
                    cnt[pos+1] = 1;
                    pos += 2;
                }else{
                    cnt[pos] = 2;
                    cnt[pos+1] = 1;
                    pos += 2;                    
                }

            }else{
                if (p[pos-1] == 0){
                    cnt[pos] = 1;
                    pos += 1;
                }else{
                    cnt[pos] = 2;
                    pos += 1;
                }
            }            
            continue;
        }
    }

    mint ans = 1;
    rep(i, 0, N){
        ans *= (mint)cnt[i];
    }
    cout << ans.val() << endl;

    return 0;
}