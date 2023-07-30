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
    vector<int> P(N), Q(N);
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, N) cin >> Q[i];

    vector<int> arr;
    rep(i, 0, N) arr.push_back(i+1);
    int a = 0, b = 0, cnt = 0;
    do {
        cnt++;
        if (arr == P) a = cnt;
        if (arr == Q) b = cnt;
    }while (next_permutation(all(arr)));

    cout << abs(a-b) << endl;

    return 0;
}