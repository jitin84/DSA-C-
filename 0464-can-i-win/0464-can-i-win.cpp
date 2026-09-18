class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        vector<int> dp(1 << maxChoosableInteger, -1);

        function<bool(int, int)> solve = [&](int mask, int total) {
            if (dp[mask] != -1)
                return dp[mask];

            for (int i = 1; i <= maxChoosableInteger; i++) {
                if (mask & (1 << (i - 1)))
                    continue;

                if (total + i >= desiredTotal)
                    return dp[mask] = 1;

                if (!solve(mask | (1 << (i - 1)), total + i))
                    return dp[mask] = 1;
            }

            return dp[mask] = 0;
        };

        return solve(0, 0);
    }
};