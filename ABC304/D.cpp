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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll W, H;
    cin >> W >> H;
    ll N;
    cin >> N;
    vector<ll> P(N), Q(N);
    rep(i, 0, N) cin >> P[i] >> Q[i];
    int na;
    cin >> na;
    vector<ll> A(na);
    rep(i, 0, na) cin >> A[i];
    int nb;
    cin >> nb;
    vector<ll> B(nb);
    rep(i, 0, nb) cin >> B[i];

    ll _min = INF;
    ll _max = 0;
    map<pair<int ,int>, ll> mp;
    rep(i, 0, N){
        ll p = P[i];
        ll q = Q[i];
        auto pitr = lower_bound(all(A), p);
        auto qitr = lower_bound(all(B), q);
        int pidx = pitr - A.begin();
        int qidx = qitr - B.begin();
        mp[make_pair(pidx, qidx)] += 1LL;
    }

    for (auto itr = mp.begin(); itr != mp.end(); itr++){
        chmin(_min, itr->second);
        chmax(_max, itr->second);
    }

    if (mp.size() != (na+1)*(nb+1)) _min = 0;
    cout << _min << " " << _max << endl;

    return 0;
}