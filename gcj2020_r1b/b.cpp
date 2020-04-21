#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int ten_9 = 1'000'000'000;
	int t, a, b;
	cin >> t >> a >> b;
	int r = (a / 2);
	int bx = -ten_9, by = -ten_9, cx = ten_9, cy = ten_9;
	for(int _ = 1; _ <= t; _++){
		bool done = false;
		map<pair<int,int>,int> memo;
		auto query = [&](int x, int y){
			if(x < bx || x > cx || y < by || y > cy) return 0;
			if(done) return 0;
			if(memo.count({x, y})) return memo[{x, y}];
			cout << x << ' ' << y << endl;
			string res; cin >> res;
			if(res == "MISS") return memo[{x, y}] = 0;
			if(res == "HIT") return memo[{x, y}] = 1;
			done = true;
			if(res == "CENTER") return -1;
			assert(0);
		};
		pair<int,int> at = {-1, -1};
		for(int i = bx + r; i <= cx && at.first == -1; i += r){
			for(int j = by + r; j <= cy && at.first == -1; j += r){
				int q = query(i, j);
				if(q){
					at = {i, j};
				}
			}
		}
		int lx, rx, ly, ry;
		auto expand = [&](){
			{
				int lo = bx, hi = at.first - 1, ans = at.first;
				while(lo <= hi){
					int mid = (lo + hi)>>1;
					if(query(mid, at.second)) ans = mid, hi = mid - 1;
					else lo = mid + 1;
				}
				lx = ans;
			}
			{
				int lo = at.first + 1, hi = cx, ans = at.first;
				while(lo <= hi){
					int mid = (lo + hi)>>1;
					if(query(mid, at.second)) ans = mid, lo = mid + 1;
					else hi = mid - 1;
				}
				rx = ans;
			}
			{
				int lo = bx, hi = at.second - 1, ans = at.second;
				while(lo <= hi){
					int mid = (lo + hi)>>1;
					if(query(at.first, mid)) ans = mid, hi = mid - 1;
					else lo = mid + 1;
				}
				ly = ans;
			}
			{
				int lo = at.second + 1, hi = cx, ans = at.second;
				while(lo <= hi){
					int mid = (lo + hi)>>1;
					if(query(at.first, mid)) ans = mid, lo = mid + 1;
					else hi = mid - 1;
				}
				ry = ans;
			}
		};
		auto check = [&](int rx, int ry, int sx, int sy){
			int at_x = (rx + sx) / 2;
			int at_y = (ry + sy) / 2;
			for(int dx : {-2, -1, 0, 1, 2}){
				for(int dy : {-2, -1, 0, 1, 2}){
					query(at_x + dx, at_y + dy);
				}
			}
		};
		if(!done){
			expand();
			check(lx, ly, rx, ry);
		}
	}
	return 0;
}
