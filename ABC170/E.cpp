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
const ll INF = (ll)1e15;

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i]>>b[i];
    rep(i,0,n)b[i]--;
    vector<multiset<ll>> arr(200010);
    rep(i,0,n){
        arr[b[i]].insert(a[i]);
    }
    
    multiset<ll> st;
    rep(i,0,200010){
        if (arr[i].size() == 0) continue;
        auto itr = arr[i].end();
        itr--;
        ll lt = *itr;
        st.insert(lt);
    }

    rep(_,0,q){
        ll c,d;
        cin>>c>>d;
        c--;d--;
        ll now = b[c];
        ll nex = d;
        ll sco = a[c];
        auto itr = arr[now].end();
        itr--;
        ll lt = *itr;
        if (lt == sco){
            arr[now].erase(itr);
            itr = st.lower_bound(sco);
            st.erase(itr);
            if (arr[now].size()!=0){
                itr = arr[now].end();
                itr--;
                st.insert(*itr);
            }
        }else{
            itr = arr[now].lower_bound(sco);
            arr[now].erase(itr);
        }
        b[c] = nex;
        
        itr = arr[nex].end();
        if (arr[nex].size()!=0){
            itr--;
            lt = *itr;
            if (lt < sco){
                itr = st.lower_bound(lt);
                st.erase(itr);
                st.insert(sco);
                arr[nex].insert(sco);
            }else{
                arr[nex].insert(sco);
            }
        }else{
            arr[nex].insert(sco);
            st.insert(sco);
        }
        cout << *st.begin() << endl;
    }
    return 0;
}