#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

ll N, A, B, C;

int main()
{
    cin >> N;
    cin >> A >> B >> C;
    ll ans = 1000000;
    for (ll i=0; i<10000; i++){
        for (ll j=0; j<(10000-i+1); j++){
            if ((N - A*i - B*j) < 0) break;
            if ((N - A*i - B*j) % C == 0){
                ans = min(ans, i + j + (N - A*i - B*j) / C);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
