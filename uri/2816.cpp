#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, C;
	cin >> N >> C;
	vector<int> parent(N), good(N, 0), size(N, 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int x){
		if(x == parent[x])
			return x;
		return parent[x] = find(parent[x]);
	};
	function<void(int,int)> connect = [&](int x, int y){
		x = find(x);
		y = find(y);
		if(x != y){
			if(size[x] < size[y])
				swap(x, y);
			good[x] += good[y];
			size[x] += size[y];
			parent[y] = x;
		}
	};
	string s;
	cin >> s;
	for(int _ = 0; _ < C; _++){
		int i, j;
		cin >> i >> j;
		i--;
		j--;
		connect(i, j);
	}
	for(int i = 0; i < N; i++)
		connect(i, N - 1 - i);
	vector<char> must(N);
	for(int i = 0; i < N; i++)
		if(s[i] == '*')
			good[find(i)]++;
		else
			must[find(i)] = s[i];
	const int mod = 1'000'000'007;
	int ans = 1;
	for(int i = 0; i < N; i++){
		if(s[i] != '*'){
			if(must[find(i)] != s[i])
				ans = 0;
		}
	}
	for(int i = 0; i < N; i++){
		if(i == find(i) && good[i] == size[i]){
			ans = (26ll * ans) % mod;
		}
	}
	cout << ans << '\n';
	return 0;
}
