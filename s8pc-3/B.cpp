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
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> C(H);
    rep(i, 0, H) cin >> C[i];

    ll ans = 0;
    rep(i, 0, H) rep(j, 0, W){

        vector<vector<char>> S(W);
        rrep(a, H-1, 0) rrep(b, W-1, 0){
            if (a == i && b == j) continue;
            S[b].push_back(C[a][b]);
        }

        int cnt = 0;
        ll score = 0;
        bool flag = true;
        while (flag){
            
            vector<vector<char>> S2(W);
            flag = false;
            int point = 0;
            
            rep(b, 0, W){
                rep(a, 0, S[b].size()){

                    char c = S[b][a];
                    if (c == '0') continue;
                    
                    int l = 1;
                    int pos = b;
                    while (1){
                        if (pos+1<W){
                            if (S[pos+1].size() >= a+1){
                                char nc = S[pos+1][a];
                                if (c == nc){
                                    l++;      
                                }else{
                                    break;
                                }
                            }else{
                                break;
                            }
                        }else{
                            break;
                        }
                        pos++;
                    }
                    
                    if (l >= K){
                        flag = true;
                        point += (c - '0') * l;       
                        rep(x, 0, l){
                            S[b+x][a] = '0';
                        }
                    }

                    if (S[b][a] != '0'){
                        S2[b].push_back(c);
                    }
                }
            }

            score += pow(2, cnt) * point;
            S = S2;
            cnt++;
            if (!flag) break;
        }
        chmax(ans, score);
    }

    cout << ans << endl;

    return 0;
}