#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 3, 11, 21};

    cout << "124 -> " << minCoins(coins, 124) << endl;
    cout << "226 -> " << minCoins(coins, 226) << endl;
    cout << "121 -> " << minCoins(coins, 121) << endl;

    return 0;
}