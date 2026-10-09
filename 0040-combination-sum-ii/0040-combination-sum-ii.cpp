
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, curr, ans);

        return ans;
    }

    void solve(int start, int target, vector<int>& candidates,
               vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            solve(i + 1, target - candidates[i],
                  candidates, curr, ans);

            curr.pop_back();
        }
    }
};
