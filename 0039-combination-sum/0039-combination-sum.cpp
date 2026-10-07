class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> solve = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }

            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > target)
                    break;

                temp.push_back(candidates[i]);

                // i because the same number can be reused
                solve(i, target - candidates[i]);

                temp.pop_back();
            }
        };

        sort(candidates.begin(), candidates.end());
        solve(0, target);

        return ans;
    }
};