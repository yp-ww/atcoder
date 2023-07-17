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

vector<bool> eratosthenes(int N) {
    vector<bool> isprime(N+1, true);
    isprime[0] = isprime[1] = false;
    rep(p, 2, N+1){
        if (!isprime[p]) continue;
        int q = p + p;
        while (q < N+1){isprime[q] = false; q += p;}
    }
    return isprime;
}

int main()
{
    ll N;
    cin >> N;

    vector<bool> flag = eratosthenes(1000100);
    vector<int> p;
    rep(i, 2, 1000100){
        if (flag[i]) p.push_back(i);
    }

    int cnt = 0;
    rep(i, 0, p.size()){
        int a = p[i];
        if ((ll)a*a*a*a*a >= N) break;
        rep(j, i+1, p.size()){
            int b = p[j];
            if ((ll)a*a*b*b*b >= N) break;
            int l = j;
            int r = p.size();
            while (r - l > 1){
                int mid = (l + r) / 2;
                int c = p[mid];
                if ((ll)a*a*b*c*c <= N){
                    l = mid;
                }else{
                    r = mid;
                }
            }
            cnt += (l - j);
        }
    }

    cout << cnt << endl;


    

    return 0;
}