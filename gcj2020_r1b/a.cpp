#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for(int _ = 1; _ <= t; _++){
		cout << "Case #" << _ << ":";
		using ll = long long;
		ll x, y;
		cin >> y >> x;
		int rx = 0, ry = 0;
		if(x < 0) rx = 1, x = -x;
		if(y < 0) ry = 1, y = -y;
		if((x + y) % 2 == 0){
			cout << " IMPOSSIBLE\n";
			continue;
		}
		auto covers = [&](ll x, ll y, int b){
			return abs(x) + abs(y) <= ((1ll<<(b + 1)) - 1);
		};
		string res;
		for(int i = 0; i <= 40 && res.empty(); i++){
			if(covers(x, y, i)){
				for(int j = i; j >= 0; j--){
					long long delta = 1ll<<j;
					if(covers(x - delta, y, j - 1)){
						x -= delta;
						res.push_back('N');
					} else if(covers(x + delta, y, j - 1)){
						x += delta;
						res.push_back('S');
					} else if(covers(x, y - delta, j - 1)){
						y -= delta;
						res.push_back('E');
					} else if(covers(x, y + delta, j - 1)){
						y += delta;
						res.push_back('W');
					} else assert(0);
				}
			}
		}
		reverse(res.begin(), res.end());
		if(rx){
			for(auto & c : res){
				if(c == 'N') c = 'S';
				else if(c == 'S') c = 'N';
			}
		}
		if(ry){
			for(auto & c : res){
				if(c == 'E') c = 'W';
				else if(c == 'W') c = 'E';
			}
		}
		cout << " " << res << '\n';
	}
	return 0;
}
