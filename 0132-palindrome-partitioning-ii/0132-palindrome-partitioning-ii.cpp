
class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n + 1, 0);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = 0; i <= n; i++) {
            dp[i] = i - 1;
        }

        for (int end = 0; end < n; end++) {
            for (int start = end; start >= 0; start--) {

                if (s[start] == s[end] &&
                    (end - start <= 2 || palindrome[start + 1][end - 1])) {

                    palindrome[start][end] = true;
                    dp[end + 1] = min(dp[end + 1], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};
