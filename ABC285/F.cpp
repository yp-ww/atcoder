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

int op(int a, int b){ return a+b; }
int e(){ return 0; }

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<int> ss;
    rep(i,0,n) ss.push_back(s[i]-'a');
    segtree<int,op,e> seg(n);
    vector<segtree<int,op,e>> cum(26,seg);
    rep(i,0,n){
        cum[ss[i]].set(i, 1);
    }
    rep(i,0,q){
        int a;
        cin>>a;
        if(a==1){
            int x;
            char c;
            cin>>x>>c;
            x--;
            int d = c-'a';
            int y = ss[x];
            cum[y].set(x, 0);
            ss[x] = d;
            cum[d].set(x, 1);
        }else{
            int l,r;
            cin>>l>>r;
            l--;

            vector<int> cnt(26);
            rep(j,0,26){
                cnt[j] = cum[j].prod(l,r);
            }

            bool flag = true;
            if (ss[l]>ss[r-1]) flag=false;
            
            rep(j,ss[l]+1,ss[r-1]){
                int ch = cum[j].prod(0, n);
                if (cnt[j]!=ch) flag=false;                
            }

            int now = 0;
            rep(j,0,26){
                if (cnt[j]==0)continue;
                int ch = cum[j].prod(min(n,l+now), min(n,l+now+cnt[j]));
                if (cnt[j]!=ch) flag = false;
                now += cnt[j];
            }
            YesNo(flag);
        }
    }

    return 0;
}