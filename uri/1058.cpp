#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int cs = 1; cs <= T; cs++){
		int len;
		cin >> len;
		string S;
		cin >> S;
		using ll = long long;
		auto memo = create<ll>(len, len);
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++)
				memo[i][j] = -1;
		function<bool(int,int,int)> is_valid = [&](int i, int j, int k){
			int red = 0;
			for(int v : {i, j, k})
				if(S[v] == 'R') 
					red++;
			return red <= 1;
		};
		function<ll(int,int)> solve = [&](int l, int r){
			if(l > r)
				return 1ll;
			if((r - l + 1) % 3)
				return 0ll;
			if(memo[l][r] != -1)
				return memo[l][r];
			ll ans = 0;
			for(int i = l + 1; i <= r; i++){
				for(int j = i + 1; j <= r; j++){
					if(is_valid(l, i, j)){
						ans += solve(l + 1, i - 1) 
								* solve(i + 1, j - 1) 
								* solve(j + 1, r);
					}
				}
			}
			return memo[l][r] = ans;
		};
		cout << "Case " << cs << ": " << solve(0, len - 1) << '\n';
	}
	return 0;
}
