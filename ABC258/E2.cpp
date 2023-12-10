#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

template<typename T>
struct Cum{
    vector<T> cum;
    // コンストラクタ
    Cum() {}
    Cum(vector<ll>& arr){
        int n = arr.size();
        cum.resize(n+1,0);
        // 累積和を計算
        for (int i=0; i<n; i++){
            cum[i+1] = cum[i] + arr[i];
        }
    }
    // 0-indexed, 区間 [l,r) の和を取得
    T get(int l, int r){
        assert(l<=r);
        return cum[r] - cum[l];
    }
};

int main()
{
    ll n,qq,x;
    cin>>n>>qq>>x;
    vector<ll>w(n);
    rep(i,0,n)cin>>w[i];
    ll tot = 0;
    rep(i,0,n)tot += w[i];
    ll rd = x/tot;
    ll rem = x%tot;

    vector<ll>ww(2*n);
    rep(i,0,2*n)ww[i] = w[i%n];
    vector<bool> v(n);
    vector<ll>q, arr;
    Cum<ll> cum(ww);
    ll pos = 0;
    ll st = -1;
    ll loop = -1;
    if (rem){
        while(1){
            q.push_back(pos);
            v[pos] = true;
            ll l = pos;
            ll r = pos+n;
            while(r-l>1){
                ll mid = (l+r)/2LL;
                if (cum.get(pos,mid)>=rem){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            arr.push_back(r-pos+rd*n);
            pos = r%n;
            if (v[pos]){
                st = pos;
                loop = q.size();
                rep(i,0,q.size()){
                    if (q[i]==st)break;
                    loop--;
                }
                break;
            }
        }
    }else{
        q.push_back(0);
        arr.push_back(rd*n);
        st = 0;
        loop = 1;
    }

    while(qq){
        qq--;
        ll k;
        cin>>k;
        k--;
        ll now = 0;
        while(k){
            assert(now<q.size());
            if (q[now]==st){
                k %= loop;
                break;
            }
            now++;
            k--;
        }
        assert(now+k<arr.size());
        cout << arr[now+k] << endl;
    }
    return 0;
}