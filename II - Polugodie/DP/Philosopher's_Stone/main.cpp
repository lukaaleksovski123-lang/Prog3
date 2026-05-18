#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> matrix(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(H, vector<int>(W, 0));
    for (int j = 0; j < W; j++) {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int levo = (j > 0) ? dp[i-1][j-1] : -1;
            int centar = dp[i-1][j];
            int desno = (j < W - 1) ? dp[i-1][j+1] : -1;
            dp[i][j] = matrix[i][j] + max({levo, centar, desno});
        }
    }
    int max_stones = dp[H-1][0], start_col = 0;
    for (int j = 1; j < W; j++) {
        if (dp[H-1][j] > max_stones) {
            max_stones = dp[H-1][j];
            start_col = j;
        }
    }
    cout << "Maks: " << max_stones << endl;
    vector<pair<int, int>> pat;
    int curr_col = start_col;
    for (int i = H - 1; i >= 0; i--) {
        pat.push_back({i, curr_col});
        if (i == 0) break;
        int levo = (curr_col > 0) ? dp[i-1][curr_col-1] : -1;
        int centar = dp[i-1][curr_col];
        if (curr_col > 0 && dp[i][curr_col] == matrix[i][curr_col] + levo) {
            curr_col = curr_col - 1;
        } else if (dp[i][curr_col] == matrix[i][curr_col] + centar) {
            // ostanuva ista
        } else {
            curr_col = curr_col + 1;
        }
    }
    reverse(pat.begin(), pat.end());
    cout << "Patot (red, kolona): " << endl;
    for (auto p : pat) {
        cout << "(" << p.first << ", " << p.second << ") -> ";
    }
    return 0;
}