#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using pci = pair<char, int>;
using pii = pair<int, int>;

#define Fr(i, s, e) for(auto i = s ; i < e ; i++)
#define Frr(i, s, e) for(auto i = s ; i >= e ; i--)
#define endl '\n'
#define Ft first
#define Sd second
#define sz(x) (int(x.size())) 
#define Pb push_back
#define Eb emplace_back
#define All(v) v.begin(),v.end()
#define _ <<' '<<
#define coutv(v) for(auto i : v){\
	cerr _ i; \
}cerr _ endl;

#define Htable gp_hash_table

void FAST(){ ios::sync_with_stdio(false); cin.tie(0); }
int gcd(int a, int b){ return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b){ return a * b / gcd(a, b); }
int fpow(int a, int b){
	int ans = 1, base = a;
	while(b){
		if(b & 1) ans *= base;
		base *= base, b >>= 1;
	}
	return ans;
}

int main(){
	FAST();

	const ll MOD = 100000007;

	int a, b, c, d;
	cin >> a >> b;
	vector<vector<ll>> A(a, vector<ll>(b));
	Fr(i, 0, a){
		Fr(j, 0, b){
			ll num; cin >> num;
			num %= MOD;
			A[i][j] = num;
		}
	}
	cin >> c >> d;
	vector<vector<ll>> B(c, vector<ll>(d));
	Fr(i, 0, c){
		Fr(j, 0, d){
			ll num; cin >> num;
			num %= MOD;
			B[i][j] = num;
		}
	}
	if(b == c){
		Fr(i, 0, a){
			Fr(j, 0, d){
				ll tmp = 0;
				Fr(k, 0, c){
					tmp = (tmp + A[i][k] * B[k][j]) % MOD;
				}
				cout << tmp << ' ';
			}
			cout << endl;
		}
	}
	else if(a == d){
		cout << "incommutable!" << endl;
	}
	else{
		cout << "unmultipliable!" << endl;
	}
	return 0;
}