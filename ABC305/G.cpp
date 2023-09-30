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

using mint = modint998244353;

// 2次元行列ライブラリ
template<typename T>
struct mat {
    vector<vector<T>> m;
    // コンストラクタ: 第1引数⇒行数、第2引数⇒列数、第3引数⇒初期値
    mat() : m(vector<vector<T>>()){}
    mat(int h, int w) : m(vector<vector<T>>(h, vector<T>(w))){}
    mat(int h, int w, T d) : m(vector<vector<T>>(h, vector<T>(w, d))){}
    
    // 添字演算子
    vector<T> operator[](const int i) const {return m[i];} //読み取り
    vector<T>& operator[](const int i){return m[i];} //書き込み
    
    // 行数・列数
    int nrow = m.size();
    int ncol = m[0].size();

    // 行列同士の演算
    mat& operator=(const mat& a){
        if (this != &a){
            m = a.m;
            nrow = a.nrow;
            ncol = a.ncol;
        }
        return *this;
    }
    mat& operator+=(const mat& a){
        assert(ncol == a.ncol && nrow == a.nrow);
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] += a.m[i][j];
        return *this;
    }
    mat& operator-=(const mat& a){
        assert(ncol == a.ncol && nrow == a.nrow);
        rep(i, 0, nrow) rep(j,0, ncol) m[i][j] -= a.m[i][j]; 
        return *this;
    } 
    mat& operator*=(const mat& a){
        assert(ncol == a.nrow);
        mat<T> m2(nrow, a.ncol, 0);
        rep(i, 0, nrow) rep(j, 0, a.ncol) rep(k, 0, ncol){
            m2.m[i][j] += m[i][k] * a.m[k][j];
        }
        ncol = a.ncol;
        rep(i, 0, nrow) m[i].resize(ncol);
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] = m2.m[i][j]; 
        return *this;
    }
    mat operator+(const mat& a) const { return mat(*this) += a; }
    mat operator-(const mat& a) const { return mat(*this) -= a; }
    mat operator*(const mat& a) const { return mat(*this) *= a; }
    bool operator==(const mat& a) const {
        if (!(ncol == a.ncol && nrow == a.nrow)) return false;
        bool flag = true;
        rep(i, 0, nrow) rep(j, 0, ncol) if(m[i][j] != a.m[i][j]) flag = false;
        return flag;
    }

    // 行列とスカラの演算
    mat& operator+=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] += a; return *this; }
    mat& operator-=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] -= a; return *this; }
    mat& operator*=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] *= a; return *this; }
    mat& operator/=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] /= a; return *this; }
    mat operator+(const T& a) const { return mat(*this) += a; }
    mat operator-(const T& a) const { return mat(*this) -= a; }
    mat operator*(const T& a) const { return mat(*this) *= a; }
    mat operator/(const T& a) const { return mat(*this) /= a; }

    // 転置行列
    mat<T> transpose() const {
        mat<T> transposed(ncol, nrow, 0);
        rep(i, 0, nrow) rep(j, 0, ncol) transposed.m[j][i] = m[i][j];
        return transposed;
    }

    // 回転 degの数だけ時計回りに90度回転して値を更新
    mat& rot(int deg){
        deg = (deg%4 + 4) % 4;
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if (deg == 1) rep(i, 0, nrow)rep(j, 0, ncol) m2.m[j][nrow-i-1] = m[i][j];
            if (deg == 3) rep(i, 0, nrow)rep(j, 0, ncol) m2.m[ncol-j-1][i] = m[i][j];
            swap(ncol, nrow); 
            m.resize(nrow);
            rep(i, 0, nrow) m[i].resize(ncol);
        }else if (deg == 2){
            rep(i, 0, nrow) rep(j, 0, ncol) m2.m[nrow-i-1][ncol-j-1] = m[i][j];
        }else{
            return *this;
        }
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] = m2.m[i][j];
        return *this;
    }   

    // 標準出力
    void show(){
        rep(i, 0, nrow) rep(j, 0, ncol){
            if (j != 0) cout << " ";
            cout << m[i][j];
            if (j == ncol-1) cout << endl;
        }
        return ;
    }
};

int main()
{
    ll n;
    int m;
    cin>>n>>m;
    vector<string> s(m);
    rep(i,0,m)cin>>s[i];

    auto ng = [&](int x, int size){
        string t;
        rep(i,0,size){
            t += (x&1) + 'a';
            x >>= 1;
        }
        reverse(all(t));
        for (auto ss: s){
            if (t.find(ss) != string::npos) return true;
        }
        return false;
    };

    if (n <= 10){
        int ans = 0;
        rep(i,0,1<<n){
            if (!ng(i, n)) ans++;
        }
        cout << ans << endl;
        return 0;
    }

    int d = 1<<5;
    mat<mint> a(d, d, 0), st(1, d, 0);
    rep(i,0,d){
        rep(c,0,2){
            int bit = (i<<1)|c;
            if (ng(bit, 6)) continue;
            bit &= d-1;
            a.m[i][bit] += 1;
        }
    }

    rep(i,0,d){
        if (ng(i, 5)) continue;
        else st.m[0][i] = 1;
    }

    vector<mat<mint>> an(60, mat<mint>(d,d,0));
    an[0] = a;
    rep(i,1,60){
        an[i] = an[i-1]*an[i-1];
    }

    ll nn = n-5;
    rep(k,0,60){
        if ((nn&(1LL<<k))){
            st *= an[k];
        }
    }
    // st *= an[0]*an[1]*an[2]*an[3];

    mint ans = 0;
    rep(i,0,d){
        ans += st.m[0][i];
    }
    cout << ans.val() << endl;

    return 0;
}