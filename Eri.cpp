#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using pci = pair<char, int>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vb = vector<bool>;
using vbb = vector<vb>;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define Pb push_back
#define Eb emplace_back
#define All(v) v.begin(),v.end()
#define coutv(v) for(auto i : v){\
	cout << i << ' '; \
}cout << endl;

#define Htable gp_hash_table
#define _ <<' '<<

int main(){
	int n;
	while(cin >> n){
		if((n > 14 and n < 18) or n >= 80){
			cout << "減刑" << endl;
		}	
	}
	return 0;
}