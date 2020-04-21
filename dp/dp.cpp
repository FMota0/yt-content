#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> price){
    vector<int> memo(price.size(), -1);
    function<int(int)> maximum = [&](int pos){
        if(memo[pos] != -1) return memo[pos];
        if(pos == 0) return memo[pos] = price[0];
        if(pos == 1) return memo[pos] = max(price[0], price[1]);
        return memo[pos] = max(
            maximum(pos - 1),
            maximum(pos - 2) + price[pos]
        );
    };
    return maximum(price.size() - 1);
}

int main(){
    cout << calc({33}) << '\n';
    cout << calc({10, 11}) << '\n';
    cout << calc({10, 4, 4, 10}) << '\n';
    cout << calc({99, 100, 3, 1}) << '\n';
    return 0;
}
