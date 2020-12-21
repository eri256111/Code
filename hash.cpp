#include <stdio.h>

typedef long long ll;

const ll p = 1'454'654'458;
const ll q = 1'000'123'321;

int main(){
	int T, N, M;
	bool OK;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		if(N == 1 || M == 1){
			int k = (N > M ? N : M);
			for(int i = 0 ; i < k ; i++){
				int tmp; scanf("%d", &tmp);
			}
			puts("Yes"); continue;
		} else {
			OK = true;
			ll pre = 1, hash1 = 1, hash2 = 1;
			for(int i = 0 ; i < M ; i++){
				int num; scanf("%d", &num);
				if(i == M - 1)continue;
				pre = (pre * p + num) % q;
			}
			for(int i = 1 ; i < N ; i++){
				for(int j = 0 ; j < M ; j++){
					int num; scanf("%d", &num);
					if(j != 0)
						hash1 = (hash1 * p + num) % q;
					if(j != M - 1)
						hash2 = (hash2 * p + num) % q;
				}
				if(pre != hash1)OK = false;
				pre = hash2;
				hash1 = hash2 = 1;
			}
		}
		puts(OK ? "Yes" : "No");
	}
}