#include <bits/stdc++.h>
using namespace std;

#define Fr(i, s, e) for(auto i = s ; i < e ; i++)
#define endl  '\n'
#define E emplace
#define _ << ' ' <<

inline void FAST(){ ios::sync_with_stdio(false); cin.tie(0); }

const int MAX = 100001;

int N, M, t, x;

struct Node{
	int id, last = -1, next = -1;
	bool dead = false;
}player[MAX];

void init(){
	Fr(i, 1, N + 1){
		if(i > 1)player[i].last = i - 1;
		if(i < N)player[i].next = i + 1;
		player[i].id = i;
	}
}

void print(){
	int i = 1;
	while(player[i].last != -1 or player[i].next < 1)i++;
	queue<int> ans;
	while(i != -1){
		if(!player[i].dead){
			ans.E(player[i].id);
		}
		i = player[i].next;
	}
	while(ans.size()){
		cout << ans.front();
		if(ans.size() > 1)cout << ' ';
		ans.pop();
	}
	cout << endl;
}

void debug(){
	Fr(i, 1, N + 1){
		cerr _ player[i].id _ player[i].last _ player[i].next _ player[i].dead _ endl;
	}
	cerr _ endl;
}

void solve(){
	while(M--){
		cin >> t >> x;
		if(t == 0){
			if(player[x].next != -1)
				player[player[x].last].next = player[x].next;
			if(player[x].last != -1)
				player[player[x].next].last = player[x].last;
			player[x].dead = true;
			player[x].last = player[x].next = -1;
		}
		else{
			int lx = player[x].last, nx = player[x].next;
			// 4 member; linked_change_max = 6
			/*
			player[x].next = lx;
			player[x].last = player[lx].last;
			player[player[lx].last].next = x;
			player[lx].next = nx;
			player[lx].last = x;
			player[nx].last = lx;
			*/
			if(lx != -1){
				player[x].next = lx;
				player[x].last = player[lx].last;
				if(player[lx].last != -1)player[player[lx].last].next = x;
				player[lx].next = nx;
				player[lx].last = x;
			}
			if(nx != -1 and lx != -1)player[nx].last = lx;
		}
		//debug();
		//print();
	}
}

int main(){
	FAST();

	cin >> N >> M;
	init();
	//print();
	solve();
	//debug();
	print();

	return 0;
}