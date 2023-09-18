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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    ll Q;
    cin >> Q;

    set<ll> aa, bb;
    vector<ll> arr_a, arr_b;
    vector<int> la(N), lb(N);
    rep(i, 0, N){
        if (aa.find(A[i]) == aa.end()){
            aa.insert(A[i]);
            arr_a.push_back(A[i]);
        }
        if (bb.find(B[i]) == bb.end()){
            bb.insert(B[i]);
            arr_b.push_back(B[i]);
        }
        la[i] = aa.size();
        lb[i] = bb.size();
    }
    
    vector<bool> J(N+1);
    set<ll> X, Y, Z;
    rep(sz, 1, N+1){
        if (sz > arr_a.size() || sz > arr_b.size()){
            break;
        }
        ll a = arr_a[sz-1];
        ll b = arr_b[sz-1];
        if (a != b){
            if (Y.find(a) != Y.end()){
                Y.erase(a);
                Z.insert(a);
            }else{
                if (Z.find(a) == Z.end()) X.insert(a);
            }
            if (X.find(b) != X.end()){
                X.erase(b);
                Z.insert(b);
            }else{
                if (Z.find(b) == Z.end()) Y.insert(b);
            }
        }else{
            Z.insert(a);
        }
        
        if (X.size() == 0 && Y.size() == 0){
            J[sz] = true;
        }
    }   

    rep(i, 0, Q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        int len_a = la[x];
        int len_b = lb[y];
        if (len_a == len_b && J[len_a]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}