#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

ll H, W;
ll sh, sw, gh, gw;
string S[1100];
ll v[1100][1100][4];

int main()
{
    cin >> H >> W;
    cin >> sh >> sw;
    cin >> gh >> gw;
    sh--; sw--; gh--; gw--;

    for (int i=0; i<H; i++){
        cin >> S[i];
    }

    for (int i=0; i<H; i++) for (int j=0; j<W; j++) for (int k=0; k<4; k++){
        v[i][j][k] = 10000000000;
    }

    deque<tuple<ll, ll, int>> q;
    for (int i=0; i<4; i++){
        v[sh][sw][i] = 0;
        q.push_back(make_tuple(sh, sw, i));
    }

    int dh[] = {0, 0, 1, -1};
    int dw[] = {1, -1, 0, 0};
    ll ans = 10000000000;
    while(!q.empty()){
        tuple<ll, ll, ll> t = q.front();
        q.pop_front();
        ll h = get<0>(t);
        ll w = get<1>(t);
        int i = get<2>(t);

        if (h == gh && w == gw){
            for (int j=0; j<4; j++){
                ans = min(ans, v[h][w][j]);     
            }
            break;
        }
                
        for (int j=0; j<4; j++){
            ll nh = h + dh[j];
            ll nw = w + dw[j];
            if (!(0 <= nh && nh < H && 0 <= nw && nw < W && S[nh][nw] == '.')) continue;
            if (i == j){
                if (v[nh][nw][j] > v[h][w][i]){
                    v[nh][nw][j] = v[h][w][i];
                    q.push_front(make_tuple(nh, nw, j));
                }
            }else{
                if (v[nh][nw][j] > v[h][w][i] + 1){
                    v[nh][nw][j] = v[h][w][i] + 1;
                    q.push_back(make_tuple(nh, nw, j));
                }
            }
        }
    }


    cout << ans << endl;

    

    return 0;
}
