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
    int n;
    cin>>n;

    vector<vector<tuple<int,int,int>>> arr(4001);
    int cnt = 0;
    rep(i,1,n+1){
        int l = i;
        cnt++;
        arr[i].push_back({l,l,cnt});
        rep(k,0,12){
            int r = l + pow(2,k);
            if (r<=n){
                cnt++;
                arr[i].push_back({l,r,cnt});
            }
        }
    }

    cout << cnt << endl;
    rep(i,1,n+1){
        for (auto [l,r,c]: arr[i]){
            cout << l << " " << r << endl; 
        }
    }

    int q;
    cin >> q;
    rep(i,0,q){
        int l, r;
        cin>>l>>r;
        int dif = r - l;
        
        if (dif == 0){
            auto [la,ra,ca] = arr[l][0];
            cout << ca << " " << ca << endl;
            continue;
        }

        int k = 1;
        while ((1<<k) < dif){
            k++;
        }
        k--;
        auto [la,ra,ca] = arr[l][k+1];
        auto [lb,rb,cb] = arr[r-pow(2,k)][k+1];
        cout << ca << " " << cb << endl;
    }

    return 0;
}