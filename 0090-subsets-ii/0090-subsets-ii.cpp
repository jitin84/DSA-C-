class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;

        function<void(int)> solve = [&](int start) {
            ans.push_back(curr);

            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i] == nums[i - 1])
                    continue;

                curr.push_back(nums[i]);
                solve(i + 1);
                curr.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};